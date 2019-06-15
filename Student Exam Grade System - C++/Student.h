#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
using namespace std;

class Student
{
    public:
        Student();
        Student(int, string);
        int id;
        string name;
};

#endif // STUDENT_H
