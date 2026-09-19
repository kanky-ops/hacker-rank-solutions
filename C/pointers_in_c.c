#include <stdio.h>
void update(int* a, int* b) {
    // Store the value of a in a temporary variable
    int temp = *a;
    // Add the value of b to a
    *a += *b;
    // Store the absolute difference between a and b, into b
    *b = abs(temp - *b);
}

int main() {
    int a, b;
    int* pa = &a, * pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
     printf("%d\n%d", a, b);

    return 0;
}
