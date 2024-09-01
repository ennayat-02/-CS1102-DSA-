#include <stdio.h>
#include <ctype.h>  

#define MAX 100 

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;
    }
}


char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}


int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
       
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        
        else if (infix[i] == '(') {
            push(infix[i]);
        }
      
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  
        }
        
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    
  
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  
    
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    
    printf("Enter infix expression: ");
    gets(infix);  
    
    infixToPostfix(infix);
    
    return 0;
}
