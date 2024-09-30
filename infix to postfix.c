#include <stdio.h>
#include <ctype.h>  // for isalnum() to check if character is alphanumeric

#define MAX 100  // Maximum size for stack and expressions

// Stack structure for operators
struct Stack {
    int top;
    char items[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push item onto stack
void push(struct Stack* s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

// Pop item from stack
char pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// Peek the top element of the stack
char peek(struct Stack* s) {
    if (s->top == -1) {
        return -1;
    } else {
        return s->items[s->top];
    }
}

// Function to check if character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to check precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    struct Stack s;
    initStack(&s);
    char postfix[MAX];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it to stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If the character is ')', pop until '(' is found
        else if (ch == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Remove '(' from stack
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all remaining operators from the stack
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression

    // Output the result
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    // Input the infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert to postfix
    infixToPostfix(infix);

    return 0;
}
