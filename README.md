# HsmBase
A type safe hierarchical state machine implementation for C++ 

While there are many options to add a hierarchical state machine (HSM) to your project all of them have certain pros and cons regarding speed, complexity, license, and build process integration:

- There are free and commercial generators which take a HSM description and produce C/C++ code.
- boost comes with 2 different HSM. These state machines make heavy use of template expressions.
- Miro Samek published HSM software. He associates states with methods. 

HsmBase provides an additional option to build a HSM: Derive from HsmBase and implement every state as a method. This direct mapping between bubbles in your state chart and methods in your code makes development and maintaining of HSM's easy. The way you write state machines with HsmBase is similar Miro Samek's state machine. 

## Features of HsmBase

- type safe, no makros
- free for commercial and non-commercial use 
- runs very fast
- compiles very fast, even for huge HSMs
- number of states and nesting depth is not limited
- events can be enums or of class type
- needs a c++03 compliant compiler and has no further depedency on libraries
- supports inits, entry / exit actions and transitions.  Transitions will be called in the correct order.
- HsmBase is a template but the state machine class you write is not.
- No template expressions, very straightforward code. 


Currently there is no documentation but a tiny example. 

The general usage is simple: Copy the file hsmbase.h to your project. Derive a class from stm::HsmBase which needs two template parameters. The first template parameter is the derived class (google for CRTP if this feels odd to you), the second parameter ist your event type. Then write a method for every leaf state and compound state. Every method contains code for entry/exit actions if needed, a call to transition() to change state and an action which is associated with the transition. Specify the hierarchy of states and the start state in the constructor. Call start on the state machine and feed events into the state machine.

TODO

- write documentation
- add asserts to give textual feedback instead of crashes for misconfigured state machines
- permit query of current state

