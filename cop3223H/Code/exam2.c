#include <stdio.h>

int f(int* a, int* b);
int main() {
    int a = INT_MIN, b = 5;
    b = f(&a, &b);
    b = 0;
    printf("a = %d, b = %d\n", a, b);
    a = f(&b, &a);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
int f(int* a, int* b) {
    int c = 2*(*b) - (*a);
    *a = 13%((*b)+(*a));
    *b = c - (*a);
    printf("a = %d, b = %d, c = %d\n", *a, *b, c);
    return 5;

}