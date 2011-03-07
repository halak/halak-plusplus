namespace Halak
{
    GameComponent* GameNode::GetComponent() const
    {
        return component;
    }

    GameNode* GameNode::GetParnet() const
    {
        return parent;
    }
    
    const GameNode::NodeCollection& GameNode::GetChildren() const
    {
        return children;
    }

    GameStructure* GameNode::GetStructure() const
    {
        return structure;
    }

    bool GameNode::IsRoot() const
    {
        return parent != nullptr;
    }
}