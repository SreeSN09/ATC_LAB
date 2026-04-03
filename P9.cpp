#include <stdio.h>
#include <string.h>

#define MAX 10

// Structure to store expressions
struct Expr {
    char op1, op2, op;
    char result;
};

int main() {
    int n;
    struct Expr expr[MAX];
    struct Expr optimized[MAX];
    int optCount = 0;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    printf("Enter expressions (format: a=b+c):\n");

    for(int i = 0; i < n; i++) {
        scanf(" %c=%c%c%c", &expr[i].result, &expr[i].op1, &expr[i].op, &expr[i].op2);
    }

    for(int i = 0; i < n; i++) {
        int found = 0;

        // Check for common subexpression
        for(int j = 0; j < optCount; j++) {
            if(expr[i].op1 == optimized[j].op1 &&
               expr[i].op2 == optimized[j].op2 &&
               expr[i].op  == optimized[j].op) {

                printf("%c = %c (reused)\n", expr[i].result, optimized[j].result);
                found = 1;
                break;
            }
        }

        if(!found) {
            optimized[optCount++] = expr[i];
            printf("%c = %c %c %c\n", expr[i].result, expr[i].op1, expr[i].op, expr[i].op2);
        }
    }

    return 0;
}

