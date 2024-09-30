#include <stdio.h>
#include <ctype.h>  // for isdigit()

#define MAX 100

// Stack structure for integers
struct Stack {
    int items[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push an integer to the stack
void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

// Pop an integer from the stack
int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If the character is a digit, push it to the stack
        if (isdigit(ch)) {
            push(&s, ch - '0');  // Convert char to int by subtracting '0'
        }
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val1 = pop(&s);
            int val2 = pop(&s);

            switch (ch) {
                case '+':
                    push(&s, val2 + val1);
                    break;
                case '-':
                    push(&s, val2 - val1);
                    break;
                case '*':
                    push(&s, val2 * val1);
                    break;
                case '/':
                    push(&s, val2 / val1);
                    break;
            }
        }
    }

    // The final result will be the only element left in the stack
    return pop(&s);
}

int main() {
    char postfix[MAX];

    // Input postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}
