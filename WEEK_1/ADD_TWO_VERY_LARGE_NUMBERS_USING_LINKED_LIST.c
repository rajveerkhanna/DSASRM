#include <stdio.h>
#include <stdlib.h>


struct Node {
    int value;
    struct Node* next;
};


struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}


void prefix(struct Node** head, int new_val) {
    struct Node* new = newNode(new_val);
    new->next = *head;
    *head = new;
}


void print(struct Node* head) {
    if (head == NULL)
        return;
    print(head->next);
    printf("%d ", head->value);
}


struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node* ans = newNode(0);
    struct Node* current = ans;
    int carry = 0;
    while (p1 || p2) {
        int sum = carry + (p1 ? p1->value : 0) + (p2 ? p2->value : 0);
        carry = sum / 10;
        sum %= 10;


        current->next = newNode(sum);
        current = current->next;


        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
    }


    if (carry) {
        current->next = newNode(carry);
    }
    ans = ans->next;
    return ans;
}


void release(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;


    char digit;
    printf("Enter the first number with spaces: ");
    while ((digit = getchar()) != '\n' && digit != EOF) {
        if (digit >= '0' && digit <= '9') {
            prefix(&p1, digit - '0');
        }
    }


    printf("Enter the second number with spaces: ");
    while ((digit = getchar()) != '\n' && digit != EOF) {
        if (digit >= '0' && digit <= '9') {
            prefix(&p2, digit - '0');
        }
    }


    struct Node* sum = add(p1, p2);


    printf("Number 01: ");
    print(p1);


    printf("\nNumber 02: ");
    print(p2);


    printf("\nSum is: ");
    print(sum);


    release(p1);
    release(p2);
    release(sum);


    return 0;
}
