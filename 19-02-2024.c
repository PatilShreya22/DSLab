8) Write a program
a) To construct a binary Search tree.
b) To traverse the tree using all the methods i.e., in-order, preorder and post order
c) To display the elements in the tree.

#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);
    return node;
}

// Function to perform in-order traversal of the tree
void inOrder(struct Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

// Function to perform pre-order traversal of the tree
void preOrder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// Function to perform post-order traversal of the tree
void postOrder(struct Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    // Construct the binary search tree
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    // Traverse the tree using in-order, pre-order, and post-order methods
    printf("In-order traversal: ");
    inOrder(root);
    printf("\nPre-order traversal: ");
    preOrder(root);
    printf("\nPost-order traversal: ");
    postOrder(root);

    return 0;
}

output: 
In-order traversal: 1 3 4 6 7 8 10 13 14 
Pre-order traversal: 8 3 1 6 4 7 10 14 13 
Post-order traversal: 1 4 7 6 3 13 14 10 8 

9a) Write a program to traverse a graph using BFS method.
9b) Write a program to check whether given graph is connected or not using DFS method.

#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Adjacency matrix representation of the graph
int graph[MAX_VERTICES][MAX_VERTICES];

// Function to add an edge between two vertices in the graph
void addEdge(int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1;
}

// Function to perform BFS traversal of the graph
void bfs(int start) {
    int visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) visited[i] = 0;
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// Function to perform DFS traversal of the graph
void dfs(int start, int visited[], int* count) {
    visited[start] = 1;
    (*count)++;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[start][i] && !visited[i]) {
            dfs(i, visited, count);
        }
    }
}

// Function to check whether the graph is connected or not
int isConnected(int vertices) {
    int visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) visited[i] = 0;
    int count = 0;
    dfs(0, visited, &count);
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) return 0;
    }
    return 1;
}

int main() {
    // Construct the graph
    int vertices = 7;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(2, 1);

    // Traverse the graph using BFS method
    printf("BFS traversal: ");
    bfs(0);
    printf("\n");

    // Check whether the graph is connected or not using DFS method
    if (isConnected(vertices)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}

output:
BFS traversal: 0 1 2 3 4 
The graph is not connected.
