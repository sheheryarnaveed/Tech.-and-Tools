#include "Student.h"
#include<iostream>
#include<string>
using namespace std;
Student::Student()
{
    id = -1;
    name="";
}

Student::Student(int i, string nam)
{
    id = i;
    name = nam;
}
