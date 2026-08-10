#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    int top = -1, i;
    char ch;

    for (i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            top++;
            s[top] = ch;
        } 
        else {
            if (top == -1) { 
                return false; 
            }

            if ((ch == ')' && s[top] != '(') ||
                (ch == '}' && s[top] != '{') ||
                (ch == ']' && s[top] != '[')) { 
                return false; 
            }

            top--;
        }
    }

    return top == -1;
}

int main() {
    char s[10000];

    fgets(s, sizeof(s), stdin);

    if (isValid(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
