#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int lines = 0, words = 0, chars = 0;
    int inWord = 0;

    printf("Enter text (Ctrl+Z to end):\n");

    while ((ch = getchar()) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
            inWord = 0;
        else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);

    return 0;
}
