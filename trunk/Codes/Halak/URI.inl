namespace Halak
{
    URI::URI()
    {
    }

    URI::URI(const URI& /*original*/)
    {
    }

    URI::~URI()
    {
    }

    URI& URI::operator = (const URI& /*right*/)
    {
        return *this;
    }

    bool URI::operator == (const URI& /*right*/) const
    {
        return true;
    }

    bool URI::operator != (const URI& right) const
    {
        return !operator == (right);
    }
}