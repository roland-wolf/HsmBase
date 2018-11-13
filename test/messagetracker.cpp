#include "messagetracker.h"


void MessageTracker::add(const std::string &message)
{
    m_messages.push_back(message);
}

void MessageTracker::clear()
{
    m_messages.clear();
}

size_t MessageTracker::size() const
{
    return m_messages.size();
}

std::string MessageTracker::at(size_t i) const
{
    return m_messages.at(i);
}

const std::vector<std::string> &MessageTracker::all() const
{
    return m_messages;
}

bool MessageTracker::operator ==(const MessageTracker &other) const
{

    return other.all() == m_messages;
}


MessageTracker &operator<<(MessageTracker &stream, const std::string &message)
{
    stream.add(message);
    return stream;
}



std::ostream &operator <<(std::ostream &ostr, const MessageTracker &t)
{
    const std::vector<std::string> &messages = t.all();
    for(size_t i=0; i< messages.size(); i++){
        ostr << messages.at(i) << " ";
    }
    return ostr;
}
