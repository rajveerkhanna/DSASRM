#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coef;
    int exp;
    struct Poly* next;
};

struct Poly* createPoly(int c, int e) {
    struct Poly* np = (struct Poly*)malloc(sizeof(struct Poly));
    np->coef = c;
    np->exp = e;
    np->next = NULL;
    return np;
}

void insertPolyTerm(struct Poly** poly, int c, int e) {
    struct Poly* np = createPoly(c, e);

    if (*poly == NULL) {
        *poly = np;
    } else {
        struct Poly* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = np;
    }
}

struct Poly* multiplyPolynomials(struct Poly* poly1, struct Poly* poly2) {
    struct Poly* result = NULL;
    struct Poly* t1 = poly1;
    struct Poly* t2;

    while (t1 != NULL) {
        t2 = poly2;
        while (t2 != NULL) {
            int c = t1->coef * t2->coef;
            int e = t1->exp + t2->exp;
            insertPolyTerm(&result, c, e);
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    return result;
}

void displayPolynomial(struct Poly* poly) {
    struct Poly* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Poly* poly) {
    while (poly != NULL) {
        struct Poly* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Poly* poly1 = NULL;
    struct Poly* poly2 = NULL;
    struct Poly* result = NULL;

    int deg1, deg2;
    int c;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);

    for (int i = deg1; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &c);
        if (c != 0) {
            insertPolyTerm(&poly1, c, i);
        }
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &deg2);

    for (int i = deg2; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &c);
        if (c != 0) {
            insertPolyTerm(&poly2, c, i);
        }
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    result = multiplyPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
