#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;

    // Iterate through all pairs (i, j) where 1 <= i < j <= n
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int current_and = i & j;
            int current_or  = i | j;
            int current_xor = i ^ j;

            // Check and update maximum for AND
            if (current_and < k && current_and > max_and) {
                max_and = current_and;
            }
            
            // Check and update maximum for OR
            if (current_or < k && current_or > max_or) {
                max_or = current_or;
            }
            
            // Check and update maximum for XOR
            if (current_xor < k && current_xor > max_xor) {
                max_xor = current_xor;
            }
        }
    }

    // Print the results in the required format
    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);
}

int main() {
    int n, k;
  
    // Read input values for n and k
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
