#include "Table.h"
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void Table::InsertStudent(Student x, int y){
    if (records.find(x.id) == records.end()) {
        Record temp;
        temp.student.id = x.id;
        temp.student.name = x.name;
        temp.grade = y;
        records[x.id] = temp;
    } else {
        cout << "Student exists." << endl;
    }
}



void Table::PrintAll(){
    map<int, Record>::iterator itr;
    for(itr = records.begin(); itr != records.end(); itr++){
        cout << itr->second.student.id << " " << itr->second.student.name << " " << itr->second.grade << endl;
    }
}

void Table::SearchbyID(int x){
    if (records.find(x) == records.end()) {
        cout << "No such student" << endl;
    } else {
        cout << records[x].student.name << endl;
        cout << records[x].grade << endl;
    }
}

void Table::SearchbyGrade(int y){
    bool exist = false;
    map<int, Record>::iterator itr;
    for(itr = records.begin(); itr!=records.end(); itr++){
        if(itr->second.grade == y){
            exist = true;
            cout << itr->second.student.id << " " << itr->second.student.name << endl;
        }
    }
    if(!exist){
        cout << "No such records." << endl;
    }
}

bool comparebyGrade(const Record & a, const Record & b){
    if(a.grade == b.grade){
        return a.student.id < b.student.id;
    }
    return a.grade > b.grade;
}

void Table::SortbyGrade(){
    vector<Record> temp_rec;
    map<int, Record>::iterator itr;
    for(itr = records.begin(); itr != records.end(); itr++){
        temp_rec.push_back(itr->second);
    }

    sort(temp_rec.begin(), temp_rec.end(), comparebyGrade);
    vector<Record>::iterator itr_r;
    for(itr_r = temp_rec.begin(); itr_r != temp_rec.end(); itr_r++){
        cout << (*itr_r).student.id << " " << (*itr_r).student.name << " " << (*itr_r).grade << endl;
    }
}

void Table::Statistics(){
    int max_grade = records.begin()->second.grade;
    int min_grade = records.begin()->second.grade;
    map<int, Record>::iterator itr;
    for(itr = records.begin(); itr != records.end(); itr++){
        if(itr->second.grade > max_grade) {
            max_grade = itr->second.grade;
        }
        if(itr->second.grade < min_grade){
            min_grade = itr->second.grade;
        }
    }
    cout << "Maximum " << max_grade << endl;


    vector<Record> temp_rec;
    for(itr = records.begin(); itr != records.end(); itr++){
        temp_rec.push_back(itr->second);
    }

    sort(temp_rec.begin(), temp_rec.end(), comparebyGrade);
    vector<Record>::iterator itr_r;


    double median = 0;
    int i = 0;
    if(records.size()%2 == 0){
        for(itr_r = temp_rec.begin(); itr_r != temp_rec.end(); itr_r++){
            if(i == records.size()/2 || i == (records.size()/2)-1) {
                median+= (*itr_r).grade;
            }
            i++;
        }
        median/=2;
        //median = (records[records.size()/2].grade + records[(records.size()/2)-1].grade) / 2;
    }
    else{
        for(itr_r = temp_rec.begin(); itr_r != temp_rec.end(); itr_r++){
            if(i == (records.size()/2)-1) {
                median+= (*itr_r).grade;
            }
            i++;
        }
        //median = records[(records.size()-1)/2].grade;
    }
    cout << "Median " << median << endl;
    cout << "Minimum " << min_grade << endl;
}


