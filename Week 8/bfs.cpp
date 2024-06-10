#include<stdio.h>
#include<stdlib.h>

void create_graph(Graph *adj_mat, char undir) 
{
	int i, j;
	// Is graph undirected?
	int un = (undir == 'y' || undir == 'Y');
	for (int i = 0; i < adj_mat->n; ++i) 
	{
		for (int j = 0; j < adj_mat->n; ++j) 
		{
			adj_mat->adj[i][j] = 0;
		}	
	}
	while (1) 
	{
		printf("Enter source and destination vertices: ");
		scanf("%d %d", &i, &j);
		if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n) 
		{
			break;
		}
		adj_mat->adj[i][j] = 1;
		if (un) 
		{
			adj_mat->adj[j][i] = 1;
		}
	}
}


int bfs_con(Graph *adj_mat) 
{
	int *visited, *queue, qr = -1;
	visited = (int *) calloc(adj_mat->n, sizeof(int));
	queue = (int *) calloc(adj_mat->n, sizeof(int));
	for (int start = 0; start < adj_mat->n; ++start) 
	{
		// Initialise visited array
		for(int i = 0; i < adj_mat->n; ++i) 
		{
			visited[i] = 0;
		}
		append(queue, start, &qr);
		visited[start] = 1;
		int vertex;
		// While queue is not empty
		while (qr != -1) 
		{
			// Dequeue first element
			vertex = delete(queue, &qr);
			// Enqueue all unvisited connections
			for (int i = 0; i < adj_mat->n; ++i) 
			{
				if (adj_mat->adj[vertex][i] && !visited[i]) 
				{
					visited[i] = 1;
					append(queue, i, &qr);
				}
			}
		}
		// Check visited array
		for (int i = 0; i < adj_mat->n; ++i) 
		{
			if (!visited[i]) 
			{
				free(visited);
				free(queue);
				return 0;
			}			
		}
	}
	// Free memory used by visited and queue
	free(visited);
	free(queue);
	return 1;
}

