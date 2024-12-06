#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    float prob;
    struct Node *left, *right;
} Node;

Node* new(float prob) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->prob = prob;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int compare(const void* a, const void* b) {
    Node* aNode = *(Node**)a;
    Node* bNode = *(Node**)b;
    return aNode->prob > bNode->prob;
}

Node* buildTree(Node* nodes[], int n) {
    while (n > 1) {
        qsort(nodes, n, sizeof(Node*), compare);

        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->prob = left->prob + right->prob;
        newNode->left = left;
        newNode->right = right;

        nodes[0] = newNode;
        for (int i = 1; i < n - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        n--;
    }
    return nodes[0];
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf(": %.2f\n", root->prob); 
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("----------\n");
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        float prob;
        scanf("%f", &prob);
        nodes[i] = new(prob);
    }

    qsort(nodes, n, sizeof(Node*), compare);
    Node* root = buildTree(nodes, n);
    int arr[100];
    int top = 0;
    printf("----------\n");
    printCodes(root, arr, top);
    freeTree(root);
    return 0;
}