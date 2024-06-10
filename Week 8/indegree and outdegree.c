#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int vertex;
} node;

node *g[20];
int n, visited[20];
int indegree(int i);
int outdegree(int i);
void dfs(int i);
void connected(int source);

void insert(int vertexi, int vertexj)
{
    node *p, *q;
    q = (node *)malloc(sizeof(node));
    q->vertex = vertexj;
    q->next = NULL;

    if (g[vertexi] == NULL)
        g[vertexi] = q;
    else
    {
        p = g[vertexi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

void readgraph()
{
    int vertexi, vertexj, i, j, k, no_of_edges;
    for (i = 0; i < n; i++)
        g[i] = NULL;
    printf("\nEnter the number of Vertices::\n");
    scanf("%d", &n);
    printf("\nEnter the number of Edges::\n");
    scanf("%d", &no_of_edges);
    for (i = 0; i < no_of_edges; i++)
    {
        printf("\nEnter the Edge(u,v)::\n");
        scanf("%d%d", &vertexi, &vertexj);
        insert(vertexi, vertexj);
    }
}

void main()
{
    int i, j, k, source;
    readgraph();
    for (i = 1; i <= n; i++)
        visited[i] = 0;

     printf("\nNode\tIndegree\tOutdegree");
     for(i=0;i<n;i++)
     {
      j=indegree(i);
      k=outdegree(i);
      printf("\n%2d\t%4d\t\t%5d",i,j,k);
      }
     printf("\n-----------------------------------------------------");
     printf("\nenter source node\n");
     scanf("%d",&source);
     dfs(source);
     connected(source);
}

int outdegree(int i)
{
    int j = 0;
    node *p;
    p = g[i];
    while (p != NULL)
    {
        p = p->next;
        j++;
    }
    return (j);
}

int indegree(int v)
{
    int i, j = 0, k;
    node *p;
    for (i = 0; i < n; i++)
    {
        p = g[i];
        while (p != NULL)
        {
            if (p->vertex == v)
                j++;
            p = p->next;
        }
    }
    return (j);
}

void dfs(int source)
{
    node *p;
    p = g[source];
    visited[source] = 1;
    printf("\nVisit - %d ", source);
    while (p != NULL)
    {
        source = p->vertex;
        if (!visited[source])
            dfs(source);
        p = p->next;
    }
}

void connected(int source)
{
    int found=0;
    dfs(source);
    for(int i = 0; i < n; i++)
    {
        if(visited[i]==1)
        {
            found=0;           
        }
        else
		{
            found=1;
        }
    }
    if(found==1)
    {
        printf("\ngraph is not connected\n");
    }
    else
    {
        printf("\ngraph is connected\n");
    }
}