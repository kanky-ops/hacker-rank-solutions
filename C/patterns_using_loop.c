#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

     int n;
    scanf("%d", &n);

    // Solution starts here
    int num = n * 2 - 1;

    for (int i = 0; i < n; i++) {
        int val = n;
        int counter = (n - i) * 2;
        int increase = n - i;

        while (val > n - i && val > 0)
            printf("%d ", val--);

        while (counter > 1 && n - i > 0) {
            counter--;
            printf("%d ", n - i);
        }

        while (increase < n)
            printf("%d ", ++increase);

        printf("\n");
    }

    // This is for the repeated values after the middle row
    int two = 0;

    for (int i = 1; i < n; i++) {
        int val = 0, counter = 0;

        while (val + i < n) {
            printf("%d ", n - val);
            val++;
        }

        while (++counter < 3 + two) {
            printf("%d ", i + 1);
        }

        two += 2;

        int increase = i + 1;
        while (increase < n) {
            printf("%d ", ++increase);
        }

        printf("\n");
    }
    return 0;
}
