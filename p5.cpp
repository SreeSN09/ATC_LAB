#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

// Function to perform operation
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char exp[100];
    int i = 0, num = 0;
    char op;

    printf("Enter expression (e.g., 2+3*4): ");
    scanf("%s", exp);

    push(0); // initial value

    for(i = 0; exp[i] != '\0'; i++) {
        if(isdigit(exp[i])) {
            num = exp[i] - '0';
            push(num);
        }
        else {
            op = exp[i];
            int b = pop();
            int a = pop();
            int result = applyOp(a, b, op);
            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
