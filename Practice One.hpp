//
//  Practice One.hpp
//  Lecture One
//
//  Created by Ellie Townsend on 4/2/25.
//

#ifndef Practice_One_hpp
#define Practice_One_hpp
#include <stdio.h>
//In header files we include interface, but not implementation, simply saying the "what" but not the "how"

/*Problem One Class/Function*/
class Double{
public:
    Double();
    Double(double num);
    double getValue();
    ~Double();
private:
    double value;
};
void createDouble();


/*Problem Two Classes/Functions*/
class A{
public:
    A();
    ~A();
};

class B{
public:
    B();
    ~B(); // Until the destrcutor has ran, that means the class has not fully run its course, this is why the object A is still "alive". And why the destrcutor for A is ran AFTER the destrcutor for B.
private:
    A a; // A is created first
};


#endif /* Practice_One_hpp */
