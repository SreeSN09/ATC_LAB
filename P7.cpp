#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// AST Node
struct Node {
    char data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Stack for nodes
struct Node* stack[100];
int top = -1;

void push(struct Node* n) {
    stack[++top] = n;
}

struct Node* pop() {
    return stack[top--];
}

// Build AST from postfix expression
struct Node* buildAST(char postfix[]) {
    for(int i = 0; postfix[i] != '\0'; i++) {

        // If operand ? push node
        if(isalnum(postfix[i])) {
            push(newNode(postfix[i]));
        }
        else { // operator
            struct Node* right = pop();
            struct Node* left = pop();

            struct Node* op = newNode(postfix[i]);
            op->left = left;
            op->right = right;

            push(op);
        }
    }
    return pop();
}

// Inorder traversal (to display AST)
void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = buildAST(postfix);

    printf("Inorder Traversal of AST: ");
    inorder(root);

    return 0;
}

