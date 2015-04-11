# HsmBase
A type safe hierarchical state machine implementation for C++ 

While there are many options to add a hierarchical state machine (HSM) to your project all of them have shortcomings in certain scenarios:

- There are free and commercial generators which take a HSM description and produce C/C++ code.
- boost comes with 2 different HSM. These state machines make heavy use of template expressions.
- Miro Samek published HSM software. He associates states with methods. 

Here is another option: Derive from HsmBase and implement every state as a method. This direct mapping between bubbles in your state chart and methods in your code makes development and maintaining of HSM's easy. The way you write state machines with HsmBase is similar Miro Samek's state machine. 

## Features of HsmBase

- type safe, no makros
- free for commercial and non-commercial use 
- runs very fast
- compiles very fast, even for huge HSMs
- type safe
- number of states and nesting depth is not limited
- events can be enums or of class type - values or pointers
- needs a c++03 compliant compiler and has no further depedency on libraries
- supports inits, entry / exit actions and transitions.  Transitions will be called in the correct order.
- HsmBase is a template but the state machine class you write is not.
- No template expressions, very straightforward code. 


Currently there is no documentation but a tiny example. 

The general usage is simple: Copy the file stateprocessor.h to your project. Derive a class from stm::StateProcessor which needs two template parameters. The first template parameter is the derived class (google for CRTP if this feels odd), the second parameter ist your event type.  
