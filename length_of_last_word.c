#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int i, c = 0, r = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            continue;
        }

        if (s[i] != ' ') {
            c++;
            r = c;
        }
        else {
            c = 0;
        }
    }
    return r;
}

int main() {
    char inputString[1000];

    printf("Enter a string: ");
    
    if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
        int length = lengthOfLastWord(inputString);
        printf("Length of the last word: %d\n", length);
    }

    return 0;
}
