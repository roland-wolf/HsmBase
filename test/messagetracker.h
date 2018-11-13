#ifndef MESSAGETRACKER_H
#define MESSAGETRACKER_H

#include <string>
#include <vector>
#include <ostream>

class MessageTracker
{

public:
    void add(const std::string &message);
    void clear();
    size_t size() const;
    std::string at(size_t i) const;
    const std::vector<std::string> &all() const;
    bool operator == (const MessageTracker &other) const;

private:
        std::vector<std::string> m_messages;
};

MessageTracker &operator<< (MessageTracker &stream, const std::string &message);
std::ostream &operator << (std::ostream& ostr, MessageTracker const& t );



#endif // MESSAGETRACKER_H
