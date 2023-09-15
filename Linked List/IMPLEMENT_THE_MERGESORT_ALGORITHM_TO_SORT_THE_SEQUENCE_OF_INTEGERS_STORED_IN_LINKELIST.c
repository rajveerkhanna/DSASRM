#include <stdio.h> #include <stdlib.h>
struct Node { int data;
struct Node* next; };
struct Node* merge(struct Node* left, struct Node* right) { if (left == NULL)
return right; if (right == NULL)
return left;
struct Node* result = NULL;
struct Node* current = NULL;
while (left != NULL && right != NULL) { if (left->data <= right->data) {
if (result == NULL) { result = left;
 
  current = left; } else {
current->next = left;
current = current->next; }
left = left->next; } else {
if (result == NULL) { result = right;
current = right; } else {
current->next = right;
current = current->next; }
right = right->next; }
= left; NULL)
= right;
}
if (left != NULL) current->next else if (right != current->next
return result; }
void split(struct Node* source, struct Node** front, struct Node** back) {
struct Node* slow = source; struct Node* fast = source->next;
while (fast != NULL) { fast = fast->next; if (fast != NULL) {
slow = slow->next;
fast = fast->next; }
}
*front = source; *back = slow->next; slow->next = NULL;
}
struct Node* mergeSort(struct Node* head) { if (head == NULL || head->next == NULL)
return head; struct Node* left;

  struct Node* right; split(head, &left, &right);
left = mergeSort(left); right = mergeSort(right);
return merge(left, right); }
void append(struct Node** head, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = data;
newNode->next = NULL;
if (*head == NULL) { *head = newNode; return;
}
struct Node* temp = *head; while (temp->next != NULL) temp = temp->next;
temp->next = newNode; }
void printList(struct Node* node) { while (node != NULL) {
printf("%d ", node->data);
node = node->next; }
printf("\n"); }
int main() {
struct Node* head = NULL;
//creating an example linked list
append(&head, 12); append(&head, 11); append(&head, 13); append(&head, 5); append(&head, 6); append(&head, 7);
printf("Unsorted list: ");
  printList(head);
head = mergeSort(head);
printf("Sorted list: ");
  printList(head);
return 0;
}
