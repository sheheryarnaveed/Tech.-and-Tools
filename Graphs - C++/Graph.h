#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include<map>
#include<vector>
using namespace std;

class Node{
    public:
        Vertex v;
};

class Graph {
    public:
        Graph();
        void InsertNode(int x);
        void InsertEdge(int x, int y);
        void ShowNeighbor(int x);
        void DeleteNode(int x);
        void DeleteEdge(int x, int y);
        void CommonNeighbor(int x, int y);
        void ShortestPath(int source, int destination);
        // You can add more member functions to help your implementation.
    private:
        map<int, Node> nodes;
        map<int, vector<Node>> edges;
};

#endif // GRAPH_H
