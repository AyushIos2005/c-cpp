#include <stdio.h>
#include <stdlib.h>
// Define the structure for a polynomial term
typedef struct Node {
int coeff; // Coefficient
int pow; // Power
struct Node* next;
} Node;
// Function to create a new node
Node* createNode(int coeff, int pow) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->coeff = coeff;
newNode->pow = pow;
newNode->next = NULL;
return newNode;
}
// Function to append a term to the polynomial
void appendTerm(Node** poly, int coeff, int pow) {
Node* temp;
Node* newNode = createNode(coeff, pow);
if (*poly == NULL) {
*poly = newNode;
} else {
temp = *poly;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
}
// Function to display the polynomial
void displayPoly(Node* poly) {
while (poly != NULL) {
printf("%dx^%d", poly->coeff, poly->pow);
poly = poly->next;
if (poly != NULL)
printf(" + ");
}
printf("\n");
}
// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
Node* result = NULL;
while (poly1 != NULL && poly2 != NULL) {
if (poly1->pow > poly2->pow) {
appendTerm(&result, poly1->coeff, poly1->pow);
poly1 = poly1->next;
} else if (poly1->pow < poly2->pow) {
appendTerm(&result, poly2->coeff, poly2->pow);
poly2 = poly2->next;
} else {
appendTerm(&result, poly1->coeff + poly2->coeff, poly1->pow);

poly1 = poly1->next;
poly2 = poly2->next;
}
}
// Add remaining terms of poly1
while (poly1 != NULL) {
appendTerm(&result, poly1->coeff, poly1->pow);
poly1 = poly1->next;
}
// Add remaining terms of poly2
while (poly2 != NULL) {
appendTerm(&result, poly2->coeff, poly2->pow);
poly2 = poly2->next;
}
return result;
}
// Function to read a polynomial from the user
void readPolynomial(Node** poly) {
int n,i;
printf("Enter the number of terms in the polynomial: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
int coeff, pow;
printf("Enter coefficient and power for term %d: ", i + 1);
scanf("%d %d", &coeff, &pow);
appendTerm(poly, coeff, pow);
}
}
// Main function
int main() {
Node* poly1 = NULL;
Node* poly2 = NULL;
printf("Enter the first polynomial:\n");
readPolynomial(&poly1);
printf("Enter the second polynomial:\n");
readPolynomial(&poly2);
printf("First Polynomial: ");
displayPoly(poly1);
printf("Second Polynomial: ");
displayPoly(poly2);
// Add the two polynomials
Node* result = addPolynomials(poly1, poly2);
printf("Resultant Polynomial: ");
displayPoly(result);
return 0;
}