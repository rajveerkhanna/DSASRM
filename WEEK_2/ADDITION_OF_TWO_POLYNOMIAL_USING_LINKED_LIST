#include <stdio.h>
#include <stdlib.h>

struct Term {
    int a;
    int b;
    struct Term* next;
};

struct Term* createTerm(int coef, int exp) {
    struct Term* newnode = (struct Term*)malloc(sizeof(struct Term));
    newnode->a = coef;
    newnode->b = exp;
    newnode->next = NULL;
    return newnode;
}

void insertTerm(struct Term** poly, int coef, int exp) {
    struct Term* newnode = createTerm(coef, exp);

    if (*poly == NULL) {
        *poly = newnode;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* temp1 = poly1;
    struct Term* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->b > temp2->b) {
            insertTerm(&result, temp1->a, temp1->b);
            temp1 = temp1->next;
        } else if (temp1->b < temp2->b) {
            insertTerm(&result, temp2->a, temp2->b);
            temp2 = temp2->next;
        } else {
            int sum = temp1->a + temp2->a;
            if (sum != 0) {
                insertTerm(&result, sum, temp1->b);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertTerm(&result, temp1->a, temp1->b);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertTerm(&result, temp2->a, temp2->b);
        temp2 = temp2->next;
    }

    return result;
}

void displayPolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->a, current->b);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Term* poly) {
    while (poly != NULL) {
        struct Term* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    int degree1, degree2;
    int coef;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);

    for (int i = degree1; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &coef);
        if (coef != 0) {
            insertTerm(&poly1, coef, i);
        }
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);

    for (int i = degree2; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &coef);
        if (coef != 0) {
            insertTerm(&poly2, coef, i);
        }
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
