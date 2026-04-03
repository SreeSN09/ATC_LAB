#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidChar(char ch) {
    return (isalnum(ch) || ch == '*' || ch == '|' || ch == '(' || ch == ')');
}

int isBalanced(char exp[]) {
    int count = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            count++;
        else if (exp[i] == ')') {
            count--;
            if (count < 0)
                return 0;
        }
    }
    return count == 0;
}

int main() {
    char exp[100];

    printf("Enter regular expression: ");
    scanf("%s", exp);

    // Check valid characters
    for (int i = 0; exp[i] != '\0'; i++) {
        if (!isValidChar(exp[i])) {
            printf("Invalid Regular Expression\n");
            return 0;
        }
    }

    // Check parentheses balance
    if (!isBalanced(exp)) {
        printf("Invalid Regular Expression (Unbalanced Parentheses)\n");
        return 0;
    }

    printf("Valid Regular Expression\n");
    return 0;
}
