#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "Graph.h"
// You can add more libraries here (if needed)
using namespace std;
// Define the classes and member functions here
int main() {
Graph g;
string command;
int id1, id2;
while (cin >> command) {
if (command == "InsertNode") {
cin >> id1;
g.InsertNode(id1);
}
else if (command == "InsertEdge") {
cin >> id1 >> id2;
g.InsertEdge(id1, id2);
}
else if (command == "ShowNeighbor") {
cin >> id1;
g.ShowNeighbor(id1);
}
else if (command == "CommonNeighbor") {
cin >> id1 >> id2;
g.CommonNeighbor(id1, id2);
}
else if (command == "DeleteNode") {
cin >> id1;
g.DeleteNode(id1);
}
else if (command == "DeleteEdge") {
cin >> id1 >> id2;
g.DeleteEdge(id1, id2);
}
else if (command == "ShortestPath") {
cin >> id1 >> id2;
g.ShortestPath(id1, id2);
}
else if (command == "Exit") {
break;
}
}
return 0;
}
