#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/HistoryWindow.h>
#include <Halak.Toolkit/TypeLibrary.h>
#include <Halak/BatchCommand.h>
#include <Halak/CommandHistory.h>
#include <Halak/Math.h>

namespace Halak
{
    namespace Toolkit
    {
        enum IDs
        {
            HistoryTreeID = 200,
        };

        struct HistoryWindow::Fields
        {
            wxTreeCtrl* tree;
            std::list<wxTreeItemId> cancelledCommandItemIDs;

            CommandHistory* history;

            Fields()
                : tree(nullptr),
                  history(nullptr)
            {
            }

            void RebuildItems();
            void UpdateItems(int beginIndex, int endIndex);
            void UpdateItem(const wxTreeItemId& id);
            void UpdateItem(const wxTreeItemId& id, bool isCancelled);
            void AppendItem(const wxTreeItemId& parentID, Command* command);
            void AppendItem(const wxTreeItemId& parentID, Command* command, bool isCancelled);
            void DeleteItems(int numberOfItems);
            void SelectItem(int index);
        };

        class HistoryItemData : public wxTreeItemData
        {
            public:
                HistoryItemData(Command* command)
                    : command(command)
                {
                }

                Command* GetCommand() const { return command; }

            private:
                Command* command;
        };

        BEGIN_EVENT_TABLE(HistoryWindow, wxPanel)
            EVT_TREE_SEL_CHANGED(HistoryTreeID, OnItemSelected)
        END_EVENT_TABLE()

        HistoryWindow::HistoryWindow(wxWindow* parent)
            : wxPanel(parent, wxID_ANY),
              mPointer(new Fields()),
              m(*mPointer)
        {
            m.tree = new wxTreeCtrl(this, HistoryTreeID,
                                    wxPoint(0, 0), wxSize(100, 100),
                                    wxNO_BORDER | wxTR_HAS_BUTTONS | wxTR_NO_LINES | wxTR_LINES_AT_ROOT | wxTR_HIDE_ROOT | wxTR_FULL_ROW_HIGHLIGHT);
            m.tree->AddRoot("History", 0);
        }

        HistoryWindow::~HistoryWindow()
        {
            SetHistory(nullptr);
            delete mPointer;
        }

        CommandHistory* HistoryWindow::GetHistory() const
        {
            return m.history;
        }

        void HistoryWindow::SetHistory(CommandHistory* value)
        {
            if (m.history != value)
            {
                if (m.history)
                {
                    m.history->Executed().Disconnect(this, &HistoryWindow::OnCommandExecuted);
                    m.history->Undone().Disconnect(this, &HistoryWindow::OnCommandUndone);
                    m.history->Redone().Disconnect(this, &HistoryWindow::OnCommandRedone);
                }

                m.history = value;

                if (m.history)
                {
                    m.history->Executed().Connect(this, &HistoryWindow::OnCommandExecuted);
                    m.history->Undone().Connect(this, &HistoryWindow::OnCommandUndone);
                    m.history->Redone().Connect(this, &HistoryWindow::OnCommandRedone);
                }

                m.RebuildItems();
            }
        }

        void HistoryWindow::OnItemSelected(wxTreeEvent& event)
        {
            if (m.history == nullptr)
                return;

            const wxTreeItemId& id = event.GetItem();

            if (id.IsOk() && m.tree->GetItemParent(id) == m.tree->GetRootItem())
                m.history->ProgressTo(static_cast<HistoryItemData*>(m.tree->GetItemData(id))->GetCommand());
        }

        void HistoryWindow::OnCommandExecuted(CommandHistory* sender, Command* command, const std::list<Command*>& cancelledCommands)
        {
            HKAssertDebug(m.history == sender);

            m.DeleteItems(static_cast<int>(cancelledCommands.size()));
            m.AppendItem(m.tree->GetRootItem(), command, false);
            m.SelectItem(static_cast<int>(m.history->GetCommands().size()) - 1);
        }

        void HistoryWindow::OnCommandUndone(CommandHistory* sender, const std::list<Command*>& commands)
        {
            HKAssertDebug(m.history == sender);
            HKAssertDebug(m.tree->GetChildrenCount(m.tree->GetRootItem(), false) == m.history->GetCommands().size() + m.history->GetCancelledCommands().size());

            const int beginIndex = static_cast<int>(m.history->GetCommands().size());
            m.UpdateItems(beginIndex, beginIndex + static_cast<int>(commands.size()));
            m.SelectItem(beginIndex - 1);
        }

        void HistoryWindow::OnCommandRedone(CommandHistory* sender, const std::list<Command*>& commands)
        {
            HKAssertDebug(m.history == sender);
            HKAssertDebug(m.tree->GetChildrenCount(m.tree->GetRootItem(), false) == m.history->GetCommands().size() + m.history->GetCancelledCommands().size());

            const int endIndex = static_cast<int>(m.history->GetCommands().size());
            m.UpdateItems(endIndex - static_cast<int>(commands.size()), endIndex);
            m.SelectItem(endIndex - 1);
        }

        void HistoryWindow::Fields::RebuildItems()
        {
            const wxTreeItemId& rootID = tree->GetRootItem();
            tree->DeleteChildren(rootID);

            if (history == nullptr)
                return;

            const CommandHistory::CommandCollection& commands = history->GetCommands();
            const CommandHistory::CommandCollection& cancelledCommands = history->GetCancelledCommands();

            for (CommandHistory::CommandCollection::const_iterator it = commands.begin(); it != commands.end(); it++)
                AppendItem(rootID, *it, false);
            for (CommandHistory::CommandCollection::const_iterator it = cancelledCommands.begin(); it != cancelledCommands.end(); it++)
                AppendItem(rootID, *it, true);
        }

        void HistoryWindow::Fields::UpdateItems(int beginIndex, int endIndex)
        {
            wxTreeItemIdValue cookie;
            wxTreeItemId rootID = tree->GetRootItem();
            wxTreeItemId currentID = tree->GetFirstChild(rootID, cookie);

            for (int i = 0; i < beginIndex; i++)
                currentID = tree->GetNextChild(rootID, cookie);

            const int numberOfCommands = static_cast<int>(history->GetCommands().size());

            int midtermIndex = 0;
            if (beginIndex <= numberOfCommands && numberOfCommands < endIndex)
                midtermIndex = numberOfCommands;
            else
            {
                if (endIndex <= numberOfCommands)
                    midtermIndex = endIndex;
                else
                    midtermIndex = beginIndex;
            }

            for (int i = beginIndex; i < midtermIndex; i++, currentID = tree->GetNextChild(rootID, cookie))
                UpdateItem(currentID, false);
            for (int i = midtermIndex; i < endIndex; i++, currentID = tree->GetNextChild(rootID, cookie))
                UpdateItem(currentID, true);
        }

        void HistoryWindow::Fields::UpdateItem(const wxTreeItemId& id)
        {
            const CommandHistory::CommandCollection& commands = history->GetCommands();
            const CommandHistory::CommandCollection& cancelledCommands = history->GetCancelledCommands();
            const Command* command = static_cast<HistoryItemData*>(tree->GetItemData(id))->GetCommand();

            if (std::find(commands.begin(), commands.end(), command) != commands.end())
                UpdateItem(id, false);
            else if (std::find(cancelledCommands.begin(), cancelledCommands.end(), command) != cancelledCommands.end())
                UpdateItem(id, true);
        }

        void HistoryWindow::Fields::UpdateItem(const wxTreeItemId& id, bool isCancelled)
        {
            Command* command = static_cast<HistoryItemData*>(tree->GetItemData(id))->GetCommand();

            const ClassInfo* classInfo = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().Find(command));

            if (isCancelled)
            {
                tree->SetItemText(id, classInfo->GetName());
                tree->SetItemBold(id, false);
            }
            else
            {
                tree->SetItemText(id, classInfo->GetName());
                tree->SetItemBold(id, true);
            }

            if (BatchCommand* batchCommand = dynamic_cast<BatchCommand*>(command))
            {
                const int childrenCount = static_cast<int>(tree->GetChildrenCount(id, false));
                const BatchCommand::CommandCollection& commands = batchCommand->GetCommands();

                bool commandsChanged = static_cast<int>(commands.size()) != childrenCount;
                if (commandsChanged == false)
                {
                    wxTreeItemIdValue cookie;
                    wxTreeItemId childID = tree->GetFirstChild(id, cookie);

                    // Tree에 추가되어 있는 Item들의 Command들과 같다면 갱신만 해주고,
                    // 만약 하나라도 다르다면 다 지우고 새로 추가한다.
                    for (BatchCommand::CommandCollection::const_iterator it = commands.begin(); it != commands.end(); it++, childID = tree->GetNextSibling(childID))
                    {
                        if ((*it) == static_cast<HistoryItemData*>(tree->GetItemData(childID))->GetCommand())
                            UpdateItem(childID, isCancelled);
                        else
                        {
                            commandsChanged = true;
                            break;
                        }
                    }
                }

                if (commandsChanged)
                {
                    tree->DeleteChildren(id);
                    for (BatchCommand::CommandCollection::const_iterator it = commands.begin(); it != commands.end(); it++)
                        AppendItem(id, *it, isCancelled);
                }
            }
        }

        void HistoryWindow::Fields::AppendItem(const wxTreeItemId& parentID, Command* command)
        {
            const CommandHistory::CommandCollection& commands = history->GetCommands();
            const CommandHistory::CommandCollection& cancelledCommands = history->GetCancelledCommands();
            if (std::find(commands.begin(), commands.end(), command) != commands.end())
                AppendItem(parentID, command, false);
            else if (std::find(cancelledCommands.begin(), cancelledCommands.end(), command) != cancelledCommands.end())
                AppendItem(parentID, command, true);
        }

        void HistoryWindow::Fields::AppendItem(const wxTreeItemId& parentID, Command* command, bool isCancelled)
        {
            wxTreeItemId id = tree->AppendItem(parentID, "");
            if (id.IsOk())
            {
                tree->SetItemData(id, new HistoryItemData(command));
                UpdateItem(id, isCancelled);
            }
        }

        void HistoryWindow::Fields::DeleteItems(int numberOfItems)
        {
            const wxTreeItemId& rootID = tree->GetRootItem();
            numberOfItems = Math::Min(numberOfItems, static_cast<int>(tree->GetChildrenCount(rootID, false)));

            if (numberOfItems <= 0)
                return;

            std::vector<wxTreeItemId> deletingIDs;
            deletingIDs.reserve(numberOfItems);

            wxTreeItemId id = tree->GetLastChild(rootID);
            for (int i = 0; i < numberOfItems; i++, id = tree->GetPrevSibling(id))
                deletingIDs.push_back(id);

            for (std::vector<wxTreeItemId>::iterator it = deletingIDs.begin(); it != deletingIDs.end(); it++)
                tree->Delete(*it);
        }

        void HistoryWindow::Fields::SelectItem(int index)
        {
            if (index < 0)
            {
                tree->Unselect();
                return;
            }

            wxTreeItemIdValue cookie;
            wxTreeItemId rootID = tree->GetRootItem();
            wxTreeItemId currentID = tree->GetFirstChild(rootID, cookie);

            for (int i = 0; i < index; i++)
                currentID = tree->GetNextChild(rootID, cookie);

            tree->SelectItem(currentID, true);
        }
    }
}