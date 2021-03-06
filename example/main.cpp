#include <iostream>
#include "../src/hsmbase.h"


using namespace std;



enum Event {
    Connect, Disconnect, SessionReceived, SessionLost
};

class Stm : public stm::HsmBase<Stm, Event>
{
public:
    Stm();

private:
    void init(const Event *ev);     //Initial transition
    void root(const Event *ev){}
    void connected(const Event *ev);
    void disconnected(const Event *ev);
    void hasSession(const Event *ev);
};

Stm::Stm(){
    setRoot(&Stm::root);
    addChildState(&Stm::root, &Stm::connected);
    addChildState(&Stm::root, &Stm::disconnected);
    addChildState(&Stm::connected, &Stm::hasSession);
    initStatemachine(&Stm::disconnected, &Stm::init);
}

void Stm::init(const Event *ev)
{
    cout << "state machine was started, greetings from initial transition" << endl;
}

void Stm::connected(const Event *ev)
{
    switch(reason()){
    case Stm::ENTRY:
        cout << "connected Entry" << endl;
        break;
    case Stm::EXIT:
        cout << "connected Exit" << endl;
        break;
    case Stm::INIT:
        cout << "connected init" << endl;
        break;
    case Stm::ACTION:
        cout << "connected action" << endl;
        break;
    case Stm::ROUTE:
        cout << "connected Route" << endl;
        if( *ev == Disconnect){
            transition(&Stm::disconnected);
        }else if(*ev==SessionReceived){
            transition(&Stm::hasSession);
        }
        break;
    default:
        break;
    }
}

void Stm::disconnected(const Event *ev)
{
    switch(reason()){
    case Stm::ENTRY:
        cout << "discon Entry" << endl;
        break;
    case Stm::EXIT:
        cout << "discon Exit" << endl;
        break;
    case Stm::INIT:
        cout << "discon init" << endl;
        break;
    case Stm::ACTION:
        cout << "discon action" << endl;
        break;
    case Stm::ROUTE:
        cout << "discon Route" << endl;
        if( *ev == Connect){
            transition(&Stm::connected);
        }
        break;
    default:
        break;
    }
}

void Stm::hasSession(const Event *ev)
{

    switch(reason()){
    case Stm::ENTRY:
        cout << "hasSession Entry" << endl;
        break;
    case Stm::EXIT:
        cout << "hasSession Exit" << endl;
        break;
    case Stm::INIT:
        cout << "hasSession init" << endl;
        break;
    case Stm::ACTION:
        cout << "hasSession action" << endl;
        break;
    case Stm::ROUTE:
        cout << "hasSession Route" << endl;
        if( *ev == SessionLost){
            transition(&Stm::connected);
        }
        break;
    default:
        break;
    }

}

int main()
{
    Stm sm;
    Event evConnect = Connect;
    Event evDisconnect = Disconnect;
    Event evSessionReceived = SessionReceived;
    Event evSessionLost = SessionLost;
    sm.start();
    sm.processEvent(&evConnect);
    sm.processEvent(&evSessionReceived);
    sm.processEvent(&evSessionLost);
    sm.processEvent(&evSessionReceived);
    sm.processEvent(&evDisconnect);
    sm.processEvent(&evDisconnect);
    return 0;
}



