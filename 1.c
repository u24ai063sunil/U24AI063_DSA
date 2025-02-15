#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for stack
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Stack functions
void push(Stack *s, char item) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // For operands and '('
    }
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack operatorStack;
    operatorStack.top = -1;

    int i, j = 0;
    char token;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isalnum(token)) {  // If operand, add to postfix
            postfix[j++] = token;
        } else if (token == '(') {
            push(&operatorStack, token);
        } else if (token == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the '('
        } else if (strchr("+-*/", token)) { // If operator
            while (!isEmpty(&operatorStack) && precedence(token) <= precedence(operatorStack.items[operatorStack.top])) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, token);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}


int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
