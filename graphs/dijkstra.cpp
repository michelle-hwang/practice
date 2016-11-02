

// Returns index of vertex with minimal distance away
// from available vertices
int findMin(int dist[], bool sptSet[]) {
	int min = INT_MAX;
	int minIndex;

	for (int v = 0; v < V; v++) {
		if (sptSet[v] == false && dist[v] < min)
			minIndex = v, min = dist[v];
	}

	return minIndex;
}


// Finds min distance graph 
void dijkstra(int graph[MAX][MAX], int s, int V) {
	
	// Initialization
	int dist[V];
	bool sptSet[V];
	for (int v = 0; v < V; v++)
		dist[v] = INT_MAX;
		sptSet[v] = false;
	
	// Start at source vertex
	sptSet[s] = true;
	dist[s] = 0;
	
	for (int n = 0; n < V - 1; n++) {
		// Get min distance vertex
		int minV = findMin(dist, sptSet);
		
		// Update dist values
		for (int v = 0; v < V; v++) {
			if (sptSet[minV] == false &&
			    graph[minV][v] &&
			    dist[minV] != INT_MAX &&
			    dist[minV] + graph[minV][v] < dist[v]) {

				dist[v] = dist[minV] + graph[minV][v];		
			}	
		}
	}

}


int main() {
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
			   {4, 0, 8, 0, 0, 0, 0, 11, 0},
			   {0, 8, 0, 7, 0, 4, 0, 0, 2},
			   {0, 0, 7, 0, 9, 14, 0, 0, 0},
			   {0, 0, 4, 14, 10, 0, 2, 0, 0},
			   {0, 0, 0, 0, 0, 2, 0, 1, 6},
			   {8, 11, 0, 0, 0, 0, 1, 0, 7},
			   {0, 0, 2, 0, 0, 0, 6, 7, 0}
			  };


	dijkstra(graph, 0);

	return 0;
}
