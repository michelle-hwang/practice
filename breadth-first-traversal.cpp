#include<iostream>
#include <list>

// Write a function to print the BFS for a graph given source s

class Graph {
	int V; // num vertices
	list<int> *adj; // pointer to array containing adjacency lists

public:
	Graph(int V); // constructor
	void addEdge(int v, int w);
	void BFS(int s); 
};


