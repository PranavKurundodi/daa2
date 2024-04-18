#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Function to traverse the binary tree in preorder (root, left, right) manner
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in inorder (left, root, right) manner
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in postorder (left, right, root) manner
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    printf("Enter the data values for each node:\n");
    int data;
    for (int i = 0; i < numNodes; ++i) {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Preorder traversal of the binary tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
