//
//  circle.hpp
//  Lecture One
//
//  Created by Ellie Townsend on 4/1/25.
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>
// So what if we have a program that is spanning multiple files, and lets say we wanted to use the circle class, in multiple files... what would we do... like define it in all those files?
// No! Lets just put the declerations in one place... in one file perhaps... called the header file perhaps
// Each header file should be named after the class it declares.
// The header should also include all functions that circle can use, even if its not a member function.
// We must include this header file everywhere we create a circle object

/*So, what exactly is happening in compilation?*/
/*  1. Our compiler starts turning all CPP files into object files which have the machine language translations
        - It then looks at two things, what does this file define, what does this file need (what are we using that does not have a definition within this file)
    2. Once we have defined what we need the "linker" comes in. It asks, have we met all our needs? And has it only been defined once?
        - We can not include the same/different implementation twice of a function
        - Thats why we can only have one main routine
    3. So how do headers help this issue?
        - If we can only define a function once, then that means only THAT file can use that function. WE DONT INCLUDE CPP FILES. But if we put all the decleartions in a header file that can be inlcuded, then all these files can use this object. 
 */
//Why include a header file?
//So we don't have to redefine declerations in every file we might need it, we can declare object here, and then we can "include" this file in every file we need the class
//What should we put in an implementation file?
//The implementation...dont include cpp files.

class Circle {
public:
    Circle(double x, double y, double r);
    bool scale(double factor);
    void draw() const; // Any function that does not change the object should be const
    double radius() const; // getter function, including const AFTER the function, it means "hey, this function does not modify the object", we can remeber because its not returning a const value
    
private: // We do not want the following to be public because then anyone can mess with our varibales without going through the checks, they can refuse to follow our invariants...
    // Class invariant (constraint):
    // m_r > 0
    double m_x; // when you look at this variable, you know its a member variable
    double m_y; // think about constraints when it comes to these variables, is there any with a variable
    double m_r;
};

double area(const Circle &x);


#endif /* circle_hpp */
