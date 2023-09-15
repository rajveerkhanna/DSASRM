#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 100


struct Stack {
   int top;
   char items[MAX_SIZE];
};


void initialize(struct Stack* stack) {
   stack->top = -1;
}


int isEmpty(struct Stack* stack) {
   return stack->top == -1;
}


int isOperator(char ch) {
   return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int getPrecedence(char ch) {
   if (ch == '+' || ch == '-') {
       return 1;
   } else if (ch == '*' || ch == '/') {
       return 2;
   }
   return 0;
}
void push(struct Stack* stack, char ch) {
   if (stack->top == MAX_SIZE - 1) {
       printf("Stack Overflow\n");
       exit(1);
   }
   stack->items[++stack->top] = ch;
}


char pop(struct Stack* stack) {
   if (isEmpty(stack)) {
       printf("Stack Underflow\n");
       exit(1);
   }
   return stack->items[stack->top--];
}


void infixToPostfix(char infix[], char postfix[]) {
   struct Stack stack;
   initialize(&stack);
   int i, j = 0;


   for (i = 0; infix[i] != '\0'; i++) {
       char ch = infix[i];


       if (isalnum(ch)) {
           postfix[j++] = ch;
       } else if (ch == '(') {
           push(&stack, ch);
       } else if (ch == ')') {
           while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
               postfix[j++] = pop(&stack);
           }
           if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
               printf("Invalid Expression\n");
               exit(1);
           } else {
               pop(&stack);
           }
       } else {
           while (!isEmpty(&stack) && getPrecedence(ch) <= getPrecedence(stack.items[stack.top])) {
               postfix[j++] = pop(&stack);
           }
           push(&stack, ch);
       }
   }


   while (!isEmpty(&stack)) {
       postfix[j++] = pop(&stack);
   }


   postfix[j] = '\0';
}


int main() {
   char infix[MAX_SIZE], postfix[MAX_SIZE];


   printf("Enter an infix expression: ");
   gets(infix);


   infixToPostfix(infix, postfix);


   printf("Postfix expression: %s\n", postfix);


   return 0;
}
