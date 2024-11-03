/*
Leetcode 1971. Find if Path Exists in Graph
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    int dest;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **array;
} Graph;

Node *createNode(int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int n)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->array = (Node **)malloc(sizeof(Node *)*(graph->numVertices));
    
    for(int i = 0; i < n; i++)
    {
        graph->array[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
   
    Node *newNode = createNode(dest);
    
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest]=newNode;
}

bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination)
{
    if(source == destination)
    {
        return true;
    }

    Graph *graph = createGraph(n);
    for(int i = 0 ; i < edgesSize; i++)
    {
        addEdge(graph,edges[i][0],edges[i][1]);
    }

    int *queue = (int *)malloc(sizeof(int) * n); 
    int front = 0;
    int rear = 0;

    bool *visited = (bool *)calloc(n,sizeof(bool));

    queue[rear++]=source;
    visited[source] = true;

    while(front < rear)
    {
        int node = queue[front++]; //pop

        Node *temp = graph->array[node]; // node의 첫번째 이웃노드
        while(temp)
        {
            int neighbor = temp->dest;
            if (neighbor==destination)
            {
                free(queue);
                free(visited);
                free(graph->array);
                free(graph);
                return true;
            }
            if(!visited[neighbor])
            {
                visited[neighbor]=true;
                queue[rear++]=neighbor;
            }
            temp = temp->next;
        }

    }
    free(queue);
    free(visited);
    for (int i = 0; i < n; i++)
    {
        Node *temp = graph->array[i];
        while(temp)
        {
            Node *toFree=temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->array);
    free(graph);
    return false;

}