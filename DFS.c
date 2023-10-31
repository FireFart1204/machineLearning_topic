#include<stdio.h>

int adj[10][10] = {0},visited[10] = {0},n;

void dfs(int node){
    int i;
    visited[node] = 1;
    printf("%d",node);
    for(i=0;i<n;i++){
        if(adj[node][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

void BFS(int node){
    int q[20],f=-1,r=-1,i,nd;
    visited[node] = 1;
    while(f!=r){
        nd = q[++f];
        printf("\t%d",nd);
        for(i=0;i<n;i++){
            if(adj[nd][i] == 1 && visited[i] == 0 ){
                visited[i] = 1;
                q[++r] = i;
            }
        } 
    }
}


int main(){

    int e,i,v1,v2,node,n;
    printf("enter vertices");
    scanf("%d",&n);
    printf("enter no. of edges");
    scanf("%d",&e);
    for(i=0;i<e;i++){
        printf("enter edge");
        scanf("%d%d",&v1,&v2);
        adj[v1][v2] =  adj[v2][v1] = 1;

    }
    printf("enter starting node");
    scanf("%d",&node);
    BFS(node);
    return 0;
}


// chat gpt

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Structure to represent the graph
struct Graph {
    int numVertices;
    Node** adjLists;
};

typedef struct Graph Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'numVertices' vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Depth-First Search (DFS) algorithm
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    Node* adjList = graph->adjLists[vertex];
    while (adjList) {
        int connectedVertex = adjList->data;
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        adjList = adjList->next;
    }
}

// Breadth-First Search (BFS) algorithm
void BFS(Graph* graph, int startVertex, int visited[]) {
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    printf("Visited %d\n", startVertex);
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        Node* adjList = graph->adjLists[currentVertex];

        while (adjList) {
            int connectedVertex = adjList->data;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = 1;
                printf("Visited %d\n", connectedVertex);
                queue[rear++] = connectedVertex;
            }
            adjList = adjList->next;
        }
    }
}

int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    int visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("Depth-First Search (DFS):\n");
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }

    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("\nBreadth-First Search (BFS):\n");
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            BFS(graph, i, visited);
        }
    }

    return 0;
}
