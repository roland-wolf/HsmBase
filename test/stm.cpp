#include <iostream>
#include "stm.h"

//Implementation of the state machine published in
//Practical UML Statecharts in C++
//Miro Samek
//2nd Edition
//page 88

Stm::Stm()
{
    setRoot(&Stm::s);

    //define the hierarchy of states
    addChildState(&Stm::s, &Stm::s1);
    addChildState(&Stm::s, &Stm::s2);

    addChildState(&Stm::s1, &Stm::s11);
    addChildState(&Stm::s2, &Stm::s21);
    addChildState(&Stm::s21, &Stm::s211);

    //register initial transitions
    addInit(&Stm::s, &Stm::s11);
    addInit(&Stm::s1, &Stm::s11);
    addInit(&Stm::s2, &Stm::s211);
    addInit(&Stm::s21, &Stm::s211);
    initStatemachine(&Stm::s2, &Stm::firstInitialTransition);
}


//TODO: init function

void Stm::firstInitialTransition(const Event *ev)
{
    writeMessage("top-INIT");
    m_foo = 0;
    transition(&Stm::s2);
}

void Stm::s(const Event *ev)
{
    if(reason() == ROUTE){
        switch(*ev){
        case E:
            writeMessage("s-E");
            transition(&Stm::s11);
            break;
        case I:
            if (m_foo) {
                writeMessage("s-I");
                m_foo = 0;
                handled();
            }
            break;
        default:
            break;
        }
    }else if(reason() == ENTRY){
        writeMessage("s-ENTRY");

    }else if(reason() == EXIT){
        writeMessage("s-EXIT");
    }else if(reason() == INIT)
    {
        writeMessage("s-INIT");
    }
}

void Stm::s1(const Event *ev)
{
    if(reason() == ROUTE){
        switch(*ev){
        case A: {
            writeMessage("s1-A");
            transition(&Stm::s1);
        }
            break;
        case B: {
            writeMessage("s1-B");
            transition(&Stm::s11);
        }
            break;
        case C: {
            writeMessage("s1-C");
            transition(&Stm::s2);
        }
            break;
        case D: {
            if (!m_foo) {
                writeMessage("s1-D");
                m_foo = 1;
                transition(&Stm::s);
            }
            break;
        }
        case F: {
            writeMessage("s1-F");
            transition(&Stm::s211);
        }
            break;
        case I: {
            writeMessage("s1-I");
            handled();
        }
            break;
        default:
            break;
        }
    }else if(reason() == ENTRY){
        writeMessage("s1-ENTRY");
    }else if(reason() == EXIT){
        writeMessage("s1-EXIT");
    }else if(reason() == INIT){
        writeMessage("s1-INIT");
    }
}

void Stm::s11(const Event *ev)
{
    if(reason() == ROUTE){
        switch(*ev){
        case D: {
            if (m_foo) {
                writeMessage("s11-D");
                m_foo = 0;
                transition(&Stm::s1);
            }
            break;
        }
        case G: {
            writeMessage("s11-G");
            return transition(&Stm::s211);
        }
            break;
        case H: {
            writeMessage("s11-H");
            transition(&Stm::s);
        }
            break;
        default:
            break;
        }
    }else if(reason() == ENTRY){
        writeMessage("s11-ENTRY");
    }else if(reason() == EXIT){
        writeMessage("s11-EXIT");
    }
}

void Stm::s2(const Event *ev)
{
    Reason theReason = reason();
    if(reason() == ROUTE){
        switch(*ev){
        case C: {
            writeMessage("s2-C");
            transition(&Stm::s1);
        }
            break;
        case F: {
            writeMessage("s2-F");
            transition(&Stm::s11);
        }
            break;
        case I: {
            if (!m_foo) {
                writeMessage("s2-I");
                m_foo = 1;
                handled();
            }
            break;
        }
        default:
            break;
        }
    }else if(reason() == ENTRY){
        writeMessage("s2-ENTRY");
    }else if(reason() == EXIT){
        writeMessage("s2-EXIT");
    }else if(reason() == INIT){
        writeMessage("s2-INIT");
    }
}

void Stm::s21(const Event *ev)
{
    if(reason() == ROUTE){
        switch(*ev){

        case A: {
            writeMessage("s21-A");
            transition(&Stm::s21);
            break;
        }
        case B: {
            writeMessage("s21-B");
            transition(&Stm::s211);
            break;
        }
        case G: {
            writeMessage("s21-G");
            transition(&Stm::s1);
            break;
        }

        default:
            break;
        }
    }else if(reason() == ENTRY){
        writeMessage("s21-ENTRY");
    }else if(reason() == EXIT){
        writeMessage("s21-EXIT");
    }else if(reason() == INIT){
        writeMessage("s21-INIT");
    }

}

void Stm::s211(const Event *ev)
{
    if(reason() == ROUTE){
        switch(*ev){
        case D: {
            writeMessage("s211-D");
            transition(&Stm::s21);
            break;
        }
        case H: {
            writeMessage("s211-H");
            transition(&Stm::s);
        }
            break;
        default:
            break;
        }
    }else if(reason() == ENTRY){
        writeMessage("s211-ENTRY");
    }else if(reason() == EXIT){
        writeMessage("s211-EXIT");
    }else if(reason() == INIT){
    }
}

void Stm::clearAndDispatch(const Event *ev)
{
    messages.clear();
    processEvent(ev);
}

void Stm::writeMessage(const char *msg)
{
    messages.add(msg);
    //std::cout << msg;
}



