#ifndef STM_H
#define STM_H


#include <vector>
#include <string>
#include <assert.h>
#include "hsmbase.h"
#include "messagetracker.h"


struct StatemachineConfig
{
    const static int MAXDEPTH = 10;
    const static int ENTRIES = 50;
    static void assertFunc()
    {
        assert(1);
    }
};


enum Event {
    A=0, B, C, D, E, F, G, H, I
};



class Stm : public stm::HsmBase<Stm, Event, StatemachineConfig>
{
public:
    Stm();

    void firstInitialTransition(const Event *ev);
    void s(const Event *ev);
    void s1(const Event *ev);
    void s11(const Event *ev);
    void s2(const Event *ev);
    void s21(const Event *ev);
    void s211(const Event *ev);

    void clearAndDispatch(const Event *ev);

    MessageTracker messages;  //to log entry/exit/transitions


private:
    void writeMessage(const char *msg);
        int m_foo;


};

#endif // STM_H
