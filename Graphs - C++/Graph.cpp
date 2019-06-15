#include "Graph.h"
#include "Vertex.h"
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

Graph::Graph()
{
    //empty_constructor
}


void Graph::InsertNode(int x){
    if (nodes.find(x) == nodes.end()) {
        Node temp;
        temp.v.id = x;
        nodes[x] = temp;
    } else {
        cout << "ID exists." << endl;
    }
}

bool operator==(const Node & a , const int & y ){
    if(a.v.id == y){
        return true;
    }
    return false;
}

void Graph::InsertEdge(int x, int y){
    if (nodes.find(x) == nodes.end()) {
        cout << "No such node." << endl;
    }
    else if (nodes.find(y) == nodes.end()) {
        cout << "No such node." << endl;
    } else {
        if (find(edges[x].begin(), edges[x].end(), y) == edges[x].end()) {
            Node temp;
            temp.v.id = y;
            edges[x].push_back(temp);
        }
    }
}

bool comparebyID(const Node & a, const Node & b){
    return a.v.id < b.v.id;
}

void Graph::ShowNeighbor(int x){
    if (edges.find(x) == edges.end()) {
        cout << "No neighbor found." << endl;
    } else {
        vector<Node>::iterator itr_r;
        sort(edges[x].begin(), edges[x].end(), comparebyID);
        for(itr_r = edges[x].begin(); itr_r != edges[x].end(); itr_r++){
            cout << (*itr_r).v.id << endl;
        }
    }
}

void Graph::DeleteNode(int x){
    if (nodes.find(x) == nodes.end()) {
        cout << "No such node." << endl;
    } else {
        nodes.erase(x);
        edges.erase(x);
        map<int, vector<Node>>::iterator itr;
        vector<Node>::iterator itr_r;
        for(itr = edges.begin(); itr != edges.end(); itr++){
            for(itr_r = itr->second.begin(); itr_r != itr->second.end(); itr_r++){
                if((*itr_r).v.id == x) {
                    break;
                }
            }
            if(itr_r != itr->second.end()) itr->second.erase(itr_r);

        }
        //removing the node if it is present in any other edges
    }
}


void Graph::DeleteEdge(int x, int y){
    if(nodes.find(x) == nodes.end()) {
        cout << "No such node." << endl;
    }
    else if(nodes.find(y) == nodes.end()){
        cout << "No such node." << endl;
    }
    else if(edges.find(x) == edges.end()) {
        cout << "No such edge." << endl;
    }
    else{
        if(find(edges[x].begin(), edges[x].end(), y) == edges[x].end()){
            cout << "No such edge." << endl;
            return;
        }
        vector<Node>::iterator itr_r;
        for(itr_r = edges[x].begin(); itr_r != edges[x].end(); itr_r++){
            if((*itr_r).v.id == y) {
                break;
            }
        }
        if(itr_r != edges[x].end()) edges[x].erase(itr_r);

        if(edges[x].size() == 0){
            edges.erase(x);
        }
        //removing the node if it is present in any other edges
    }
}

bool operator<(const Node & a , const Node & b ){
    return a.v.id < b.v.id;

}

void Graph::CommonNeighbor(int x, int y){

    if(nodes.find(x) == nodes.end()) {
        cout << "No such node." << endl;
        return;
    }
    if(nodes.find(y) == nodes.end()) {
        cout << "No such node." << endl;
        return;
    }

    sort(edges[x].begin(), edges[x].end(), comparebyID);
    sort(edges[y].begin(), edges[y].end(), comparebyID);

    vector<Node> v(edges[x].size());
    vector<Node>::iterator it;


    it = set_intersection (edges[x].begin(), edges[x].end(), edges[y].begin(), edges[y].end(), v.begin());
    v.resize(it-v.begin());

    if(v.size() == 0){
        cout << "No common neighbor." << endl;
    }
    else{
        vector<Node>::iterator itr_r;
        for(itr_r = v.begin(); itr_r != v.end(); itr_r++){
            cout << (*itr_r).v.id << endl;
        }
    }

}

void Graph::ShortestPath(int source, int destination){
    queue<int> q;
    map<int,int> previous;
    map<int,bool> visited;

    map<int, Node>::iterator itr;
    for(itr = nodes.begin(); itr != nodes.end(); itr++){
        previous[itr->second.v.id] = -1;
        visited[itr->second.v.id] = false;
    }

    q.push(source);
    visited[source] = true;

	string var1, var2;
	bool foundDestination = false;
    vector<Node>::iterator itr_r;

	while (q.size()>0 && foundDestination == false) {
		int current = q.front();
        q.pop();
		visited[current] = true;

		for (itr_r = edges[current].begin(); itr_r != edges[current].end(); itr_r++) {
            int n = (*itr_r).v.id;
			if (visited[n] == false) {
				q.push(n);
				visited[n] = true;
                previous[n] = current;
			}

			if(n == destination) foundDestination = true;
		}

	}

    if(foundDestination){
        int index = destination;
        stack<int> s;
        s.push(destination);
        while(previous[index] != -1){
            s.push(previous[index]);
            index = previous[index];
        }
        while(!s.empty()){
            cout << s.top() << endl;
            s.pop();
        }
    }
    else{
        cout << "Not path found." << endl;
    }


}



