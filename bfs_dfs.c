#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Define a structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the graph
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize adjacency list
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform Breadth-First Search (BFS)
void bfs(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    int queue[MAX_VERTICES];         // Queue for BFS
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to perform Depth-First Search (DFS)
void dfsHelper(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            dfsHelper(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices

    printf("DFS Traversal: ");
    dfsHelper(graph, startVertex, visited);
    printf("\n");
}

int main() {
    int choice, numVertices, src, dest, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Breadth-First Search (BFS)\n");
        printf("3. Depth-First Search (DFS)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices (0 to %d): ", numVertices - 1);
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
                    addEdge(graph, src, dest);
                } else {
                    printf("Invalid vertices! Vertices should be between 0 and %d.\n", numVertices - 1);
                }
                break;
            case 2:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < numVertices) {
                    bfs(graph, startVertex);
                } else {
                    printf("Invalid starting vertex! Vertex should be between 0 and %d.\n", numVertices - 1);
                }
                break;
            case 3:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < numVertices) {
                    dfs(graph, startVertex);
                } else {
                    printf("Invalid starting vertex! Vertex should be between 0 and %d.\n", numVertices - 1);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
