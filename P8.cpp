#include <stdio.h>
#include <string.h>

// Check valid condition (simple: variable or number)
int isCondition(char str[]) {
    return (strcmp(str, "x") == 0 || strcmp(str, "y") == 0 || strcmp(str, "1") == 0);
}

int main() {
    char input[100];

    printf("Enter statement: ");
    scanf("%s", input);

    // Check IF statement
    if (strncmp(input, "if(", 3) == 0 && input[strlen(input)-1] == ')') {
        printf("Valid IF statement\n");
    }

    // Check IF-ELSE statement
    else if (strstr(input, "if(") && strstr(input, ")else")) {
        printf("Valid IF-ELSE statement\n");
    }

    // Check WHILE statement
    else if (strncmp(input, "while(", 6) == 0 && input[strlen(input)-1] == ')') {
        printf("Valid WHILE statement\n");
    }

    else {
        printf("Invalid Statement\n");
    }

    return 0;
}
