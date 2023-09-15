#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert character to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid Operator\n");
                    exit(1);
            }
        }
    }

    result = pop(&stack);
    if (!isEmpty(&stack)) {
        printf("Invalid Expression\n");
        exit(1);
    }

    return result;
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    gets(postfix);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
