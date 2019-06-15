#ifndef TABLE_H
#define TABLE_H
#include "Student.h"
#include<map>
#include<vector>

class Record{
    public:
        Student student;
        int grade;
};

class Table {
    public:
        void InsertStudent(Student x, int y);
        void SearchbyID(int x);
        void SearchbyGrade(int y);
        void SortbyGrade();
        void Statistics();
        void PrintAll();
        // You can add more member functions to help your implementation.
    private:
        map<int, Record> records;
};

#endif // TABLE_H
