// C Program for Floyd Warshall Algorithm
#include<stdio.h>
int graph[10][10];int dist[10][10];
void printSolution(int);
void floydWarshall (int n)
{
	int dist[n][n], i, j, k;
	//for (i = 0; i < n; i++)
	//	for (j = 0; j < n; j++)
	//		dist[i][j] = graph[i][j];

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	printSolution(n);
}

/* A utility function to print solution */
void printSolution(int n)
{
	printf ("Following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] ==9999)
				printf("%7s", "INF");
			else
				printf ("%7d", graph[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i,j,n;
	puts("Enter the number of vertex:");
	scanf("%d",&n);
	puts("Enter the matrix(Give 9999 if no edge between vertex)");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	floydWarshall(n);
	return 0;
}

