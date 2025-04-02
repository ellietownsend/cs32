//
//  main.cpp
//  Lecture One
//
//  Created by Ellie Townsend on 4/1/25.
//

#include <iostream>
using namespace std;
#include <cstdlib>
#include "circle.hpp"

//This is the declaration of a function, it can even be done outside of a member function.


//When going about implementation, we can ask ourseles, what does this function need to do its job?

double Circle::radius() const{
    return m_r;
}

//The following constructor makes use of the member inialization list, it can only be used for constructors
Circle::Circle(double x, double y, double r):
m_x(x), m_y(y), m_r(r){
    // We have to make sure we dont mess up the class invariant, the constructor is especially important because its setting up the object for success
    if(r <= 0){
        //Error message is good, you dont want a program dying with no explanation
        cout << "Cannot create radius with a negative value" << endl;
        exit(1); // It exits the program. Brought to us by the c standard library
    }
        // Constructors DO NOT return a value, so we cant return a value that says something might have gone wrong
        // So we throw an exception.
        //      - The exception will construct its own object and throw it to the object it was called on. Its our job to "catch" it. We can catch it in multiple places, but if its not caught, we will get an uncaught exception error
}

bool Circle::scale(double factor){
    // HAVE TO MAKE SURE OF THE INVARIANT, I would say when you have a variable with a constraint/variant, you should always make sure its within the constraints
    if(factor <= 0)
        return false;
    m_r *= factor;
    return true;
}

//The function used to create a local variable "x", which is an exact copy of the object it was given. This means all the variables within the object.
//But if it were a HUGE, huge object that was EXPENSIVE to copy, were going to want to pass by refrence
//This function does not change circle, so we can put const
//Now, we have to be careful what we use on circle now that we have promised not to change it
double area(const Circle &x){
    const double PI = 3.14159;
    return PI * x.radius() * x.radius();
}

class StickFigure{
public:
    StickFigure(double bl, double hd, string nm, double hx, double hy);
private:
    // When we make an object, it first makes the data members! They are made in the order they are declared. Then it looks to the member initalization list to fill these values. If we do not include a built in type to the member initalization list, its life unitialized. BUT if its not a built in type (object, string) it calls the default constructor. We can initalize these un-builtin types in the inizalation section as well. 
    string m_name;
    Circle m_head; // Now when we have an object in another object, all the new object's member variables are present here
    double m_bodyLength;
};

StickFigure::StickFigure(double bl, double hd, string nm, double hx, double hy):
m_name(nm), m_bodyLength(bl), m_head(hx,hy,hd/2){
    if(bl <=0 || hd <=0){
        exit(1);
    }
    //m_head = Circle(hx, hy, hd/2); // were creating a temporary circle with all the values the circle constrcutor needs, and giving it our already declared object, temp circle goes away
    //Circle m_head(hx,hy,hd/2) // this is confusing, are you calling a function that returns a circle?? are you inializing?? hell if the c++ compliler knows...
}


int main() {
    //Before we have even created the circle object, we think about what we want the circle to be able to do.
    // This is creating the interface, it covers the "what" aspect
    Circle c(8, -3, 3.7);
    c.scale(2); // a member function, we know so because there is a calling object (c)
    c.draw();
    cout << area(c); // NOT a member function, there is no calling object, we are giving an object to a function
    //Now that we have an interface, we can think about implementation, the "how" are we going to do these things
}


