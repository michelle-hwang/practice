#include<iostream>
#include <list>

class Graph {
	int N; // num nodes
	list<int> *adj; // pointer to array containing adjacency lists

public:
	Graph(int N); // constructor
	void add(int n, int x); // Add value x to node n
	void bfs(int s); 
};

Graph::Graph(int N) {
	this->N = N;
	adj = new list<int>[N];
}

void Graph::add(int n, int x) {
	adj[n].push_back(x);
}

void bfs(int s) {

}

int main() {

	// Test graph 1
	Graph g(4);
	g.add(0, 1);
	g.add(0, 2);
	g.add(1, 2);
	g.add(2, 0);
	g.add(2, 3);
	g.add(3, 3);

	g.bfs;

	return;
}


main();

