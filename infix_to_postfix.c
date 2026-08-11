#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int isfull(int top) {
    return top == MAX - 1;
}

int isempty(int top) {
    return top == -1;
}

void push(char stack[], int *top, char a) {
    if (isfull(*top)) {
        printf("Stack full\n");
        return;
    }
    stack[++(*top)] = a;
}

char pop(char stack[], int *top) {
    if (isempty(*top)) {
        printf("Stack empty\n");
        return '\0';
    }
    return stack[(*top)--];
}

char peek(char stack[], int top) {
    if (isempty(top)) {
        return '\0';
    }
    return stack[top];
}

int isopenbracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[' || ch == '<');
}

int isclosebracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']' || ch == '>');
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixtopostfix(char exp[]) {
    char stack[MAX];
    char result[MAX];
    int stop = -1;
    int rtop = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isopenbracket(exp[i])) {
            push(stack, &stop, exp[i]);
        }
        else if (isalnum(exp[i])) {
            push(result, &rtop, exp[i]);
        }
        else if (isclosebracket(exp[i])) {
            while (!isempty(stop) && !isopenbracket(peek(stack, stop))) {
                char ch = pop(stack, &stop);
                push(result, &rtop, ch);
            }
            if (!isempty(stop)) {
                pop(stack, &stop);
            }
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^') {
            while (!isempty(stop) && !isopenbracket(peek(stack, stop)) && 
                   precedence(peek(stack, stop)) >= precedence(exp[i])) {
                char ch = pop(stack, &stop);
                push(result, &rtop, ch);
            }
            push(stack, &stop, exp[i]);
        }
    }

    while (!isempty(stop)) {
        char ch = pop(stack, &stop);
        push(result, &rtop, ch);
    }

    push(result, &rtop, '\0');
    printf("Postfix expression: %s\n", result);
}

int main() {
    char exp[MAX];
    printf("Enter your expression: ");
    scanf("%s", exp);
    infixtopostfix(exp);
    return 0;
}
