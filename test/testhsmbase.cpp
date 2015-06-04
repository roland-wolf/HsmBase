#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "hsmbase.h"
#include "stm.h"



BOOST_AUTO_TEST_CASE( checkCalls )
{
    Stm stm;

    int stateS211 = stm.methodToIndex(&Stm::s211);
    int stateS11 = stm.methodToIndex(&Stm::s11);

    Event a=A;
    Event b=B;
    Event c=C;
    Event d=D;
    Event e=E;
    Event f=F;
    Event g=G;
    Event h=H;
    Event i=I;

    MessageTracker expected;


    stm.start();
    expected << "top-INIT" << "s-ENTRY" << "s2-ENTRY" << "s2-INIT"  <<
                "s21-ENTRY" << "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&a);
    expected.clear();
    expected << "s21-A" <<  "s211-EXIT" <<  "s21-EXIT" <<  "s21-ENTRY" <<
                "s21-INIT" <<  "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&b);
    expected.clear();
    expected << "s21-B" << "s211-EXIT"<< "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&d);
    expected.clear();
    expected << "s211-D" << "s211-EXIT" << "s21-INIT" << "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&e);
    expected.clear();
    expected << "s-E" << "s211-EXIT" << "s21-EXIT" << "s2-EXIT" << "s1-ENTRY" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&i);
    expected.clear();
    expected << "s1-I";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&f);
    expected.clear();
    expected << "s1-F" << "s11-EXIT" << "s1-EXIT" << "s2-ENTRY" << "s21-ENTRY" << "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&i);
    expected.clear();
    expected << "s2-I";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&i);
    expected.clear();
    expected << "s-I";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&f);
    expected.clear();
    expected << "s2-F" << "s211-EXIT" << "s21-EXIT" << "s2-EXIT" << "s1-ENTRY" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&a);
    expected.clear();
    expected << "s1-A" << "s11-EXIT" << "s1-EXIT" << "s1-ENTRY" << "s1-INIT" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&b);
    expected.clear();
    expected << "s1-B" << "s11-EXIT" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&d);
    expected.clear();
    expected << "s1-D" << "s11-EXIT" << "s1-EXIT" << "s-INIT" << "s1-ENTRY" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&d);
    expected.clear();
    expected << "s11-D" << "s11-EXIT" << "s1-INIT" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&e);
    expected.clear();
    expected << "s-E" << "s11-EXIT" << "s1-EXIT" << "s1-ENTRY" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&g);
    expected.clear();
    expected << "s11-G" << "s11-EXIT" << "s1-EXIT" << "s2-ENTRY" << "s21-ENTRY" << "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&h);
    expected.clear();
    expected << "s211-H" << "s211-EXIT" << "s21-EXIT" << "s2-EXIT" << "s-INIT" << "s1-ENTRY" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&h);
    expected.clear();
    expected << "s11-H" << "s11-EXIT" << "s1-EXIT" << "s-INIT" << "s1-ENTRY" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&c);
    expected.clear();
    expected << "s1-C" << "s11-EXIT" << "s1-EXIT" << "s2-ENTRY" << "s2-INIT" << "s21-ENTRY" << "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&g);
    expected.clear();
    expected << "s21-G" << "s211-EXIT" << "s21-EXIT" << "s2-EXIT" << "s1-ENTRY" << "s1-INIT" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);


    stm.clearAndDispatch(&c);
    expected.clear();
    expected << "s1-C" << "s11-EXIT" << "s1-EXIT" << "s2-ENTRY" << "s2-INIT" << "s21-ENTRY" << "s211-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS211);


    stm.clearAndDispatch(&c);
    expected.clear();
    expected << "s2-C" << "s211-EXIT" << "s21-EXIT" << "s2-EXIT" << "s1-ENTRY" << "s1-INIT" << "s11-ENTRY";
    BOOST_REQUIRE_EQUAL(stm.messages, expected);
    BOOST_REQUIRE_EQUAL(stm.stateId(), stateS11);
}



