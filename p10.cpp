#include <stdio.h>
#include <ctype.h>

int tempCount = 1;

// Function to generate new temporary variable
char getTemp() {
    return 'T' + tempCount++;
}

int main() {
    char exp[100];
    char op1, op2, op, temp;

    printf("Enter expression (e.g., a+b): ");
    scanf("%s", exp);

    op1 = exp[0];
    op  = exp[1];
    op2 = exp[2];

    temp = getTemp();

    // Generate simple assembly-like code
    printf("\nGenerated Code:\n");
    printf("MOV %c, R0\n", op1);
    printf("%c %c, R0\n", op, op2);
    printf("MOV R0, %c\n", temp);

    return 0;
}
