#include <stdio.h>
#include <string.h>

// Count number of operators (+ or *)
int countOperators(char str[]) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '+' || str[i] == '*')
            count++;
    }
    return count;
}

int main() {
    char exp[100];

    printf("Enter expression: ");
    scanf("%s", exp);

    int opCount = countOperators(exp);

    // If more than one operator ? possible ambiguity
    if(opCount > 1)
        printf("Grammar is Ambiguous for given input\n");
    else
        printf("Grammar is Not Ambiguous for given input\n");

    return 0;
}

