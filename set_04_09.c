#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack node for storing tree nodes
#define MAX_STACK_SIZE 100

struct Stack {
    struct Node* data[MAX_STACK_SIZE];
    int top;
};

// Stack operations
void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(struct Stack* stack, struct Node* node) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = node;
    }
}

struct Node* pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return NULL;
}

// Create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

// Preorder traversal without recursion
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Stack stack;
    initStack(&stack);
    push(&stack, root);

    while (!isEmpty(&stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);

        // Push right first so that left is processed first
        if (current->right)
            push(&stack, current->right);
        if (current->left)
            push(&stack, current->left);
    }
}

// Sample usage
int main() {
   

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    preorderTraversal(root);
    printf("\n");

    return 0;
}