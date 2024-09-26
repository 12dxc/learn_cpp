#include <string>
#include <set>
using namespace std;
#include "Message.h"

class Folder
{
    friend class Message;
    friend void swap(Message &, Message &);
    friend void swap(Folder &, Folder &);

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
    void print_debug();

private:
    set<Message *> mags;

    void add_to_Message(const Folder &);
    void remove_to_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for (auto m : lhs.msgs)
        m->remFlddr(&lhs);
    for (auto m : rhs.msgs)
        m->remFlddr(&rhs);

    swap(lhs.msgs, rhs.msgs);

    for (auto m : lhs.msgs)
        m->addFldr(&lhs);
    for (auto m : rhs.msgs)
        m->addFldr(&rhs);
}

void Folder::add_to_Message(const Folder &f)
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Message(f);
}

void Folder::remove_to_Message()
{
    for (auto m : msgs)
        m->remFlddr(this);
    msgs.clear();
}

Folder::~Folder()
{
    remove_to_Message();
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_to_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug()
{
    for (auto m : msgs)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}