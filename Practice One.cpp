//
//  Practice One.cpp
//  Lecture One
//
//  Created by Ellie Townsend on 4/2/25.
//

#include "Practice One.hpp"
#include <iostream>
using namespace std;

/*Problem 2*/
Double::Double():value(0){cout << "1";}
Double::Double(double num):value(num){cout << "4";}
double Double::getValue(){return value;}
Double::~Double(){cout <<"9";}


void createDouble(){
    Double a, b = 2, c = b;
    // These are all made with the constructor, we can tell because of the "Double" keyword. Although, with "b=2" we first create the object, then store the number two in value, per the constrcutor.
    a = b;
    cout << a.getValue() << b.getValue() << c.getValue();
    //Between the curly braces in which the object object is made, is also which it will be destroyed. When we hit the following curly braces all the object that were created within this function will be destroyed, one at a time.
}

/*Problem 3*/

A::A(){
    cout <<"C";
}
A::~A(){
    cout <<"2";
}

B::B(){
    cout <<"S";
}
B::~B(){
    cout <<"3";
}

void createB(){
    B b;
}

/*Problem 4*/
class Student{
public:
    Student(const string &name, const double &score);
    Student():name(""), score(0){}
    void output();
private:
    string name;
    double score;
};

Student::Student(const string &name, const double &score){
    this->name = name;
    this->score = score;
}

void Student::output(){
    cout << "Student's name is: " << name << endl;
    cout << "Student's score is: " << score << endl;
}

void createStudent(){
    Student s; // Creating a student without parameters will be a problem  when we defined a constructor with parameters, but no default. C++ thinks that this is the only way we want to create objects. Hence, it will not create a default constrcutor.
    s.output();
}



