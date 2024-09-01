#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    int operand1, operand2, result;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(result);
        }
        i++;
    }

    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    gets(postfix);

    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
