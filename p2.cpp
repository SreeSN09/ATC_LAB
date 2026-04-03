#include <stdio.h>

int main() {
    FILE *in, *out;
    char ch, next;

    in = fopen("input.c", "r");
    out = fopen("output.c", "w");

    if (in == NULL || out == NULL) {
        printf("File error\n");
        return 0;
    }

    while ((ch = fgetc(in)) != EOF) {
        if (ch == '/') {
            next = fgetc(in);

            if (next == '/') {  // single-line
                while ((ch = fgetc(in)) != '\n' && ch != EOF);
            }
            else if (next == '*') {  // multi-line
                while (1) {
                    ch = fgetc(in);
                    if (ch == '*' && (next = fgetc(in)) == '/')
                        break;
                }
            }
            else {
                fputc(ch, out);
                fputc(next, out);
            }
        } else {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("? Comments removed! Check output.c\n");

    return 0;
}
