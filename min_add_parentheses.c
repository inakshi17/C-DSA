#include <stdio.h>

int minAddToMakeValid(char* s) {
    int open = 0, insert = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                insert++;
            }
        }
    }

    return open + insert;
}

int main() {
    char s[1000];
    printf("enter string: ");
    scanf("%s", s);

    printf("Minimum additions required: %d\n", minAddToMakeValid(s));

    return 0;
}
