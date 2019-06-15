#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main() {
Table t;
string command;
int id;
string name;
int grade;
while (cin >> command) {
if (command == "InsertStudent") {
cin >> id >> name >> grade;
Student s(id, name);
t.InsertStudent(s, grade);
}
else if (command == "SearchbyID") {
cin >> id;
t.SearchbyID(id);
}
else if (command == "SearchbyGrade") {
cin >> grade;
t.SearchbyGrade(grade);
}
else if (command == "SortbyGrade") {
t.SortbyGrade();
}
else if (command == "PrintAll") {
t.PrintAll();
}
else if (command == "Statistics") {
t.Statistics();
}
else if (command == "exit") {
break;
}
}
return 0;
}





