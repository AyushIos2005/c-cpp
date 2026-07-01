// 5.a ) WAP to convert an infix expression to its equivalent postfix expression.

#include <stdio.h>
#include <ctype.h>  // for isalnum()

#define SIZE 100

char stack[SIZE];
int top = -1;

// Stack functions
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    return 0;
}

int isEmpty() {
    return top == -1;
}

void infixToPostfix(char infix[]) {
    char postfix[SIZE];
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            if (!isEmpty()) pop();  // Remove '('
        }
        else {  // Operator
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
