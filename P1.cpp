#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *str) {
    char *keywords[] = {"int","float","char","if","else","while","for","return"};
    for(int i=0;i<8;i++)
        if(strcmp(str, keywords[i])==0)
            return 1;
    return 0;
}

int main() {
    char str[100];
    printf("Enter word: ");
    scanf("%s", str);

    if(isKeyword(str))
        printf("Keyword\n");
    else if(isdigit(str[0]))
        printf("Number\n");
    else if(isalpha(str[0]))
        printf("Identifier\n");
    else
        printf("Operator/Unknown\n");

    return 0;
}
