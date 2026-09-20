#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 16

// Dynamically allocates and reads a line from stdin
char* readline() {
    size_t alloc_size = INITIAL_BUFFER_SIZE;
    size_t current_len = 0;
    char* buffer = malloc(alloc_size);
    
    if (!buffer) {
        return NULL;
    }

    while (1) {
        int ch = getchar();
        
        // Break on End-Of-File or Newline
        if (ch == EOF || ch == '\n') {
            buffer[current_len] = '\0';
            break;
        }

        buffer[current_len++] = (char)ch;

        // Resize buffer if it exceeds current allocation capacity
        if (current_len >= alloc_size) {
            alloc_size *= 2;
            char* new_buffer = realloc(buffer, alloc_size);
            if (!new_buffer) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
    }

    // Handle case where no characters were read and EOF occurred
    if (current_len == 0 && buffer[0] == '\0') {
        // You could check feof(stdin) here if needed
    }

    return buffer;
}

int main() {
    // Array of English names for numbers 1 to 9 (0-indexed offset applied later)
    const char* numbers[] = {
        "one", "two", "three", "four", "five", 
        "six", "seven", "eight", "nine"
    };

    // 1. Read input using the custom readline function
    char* input = readline();
    if (!input) {
        fprintf(stderr, "Memory allocation error or failed to read input.\n");
        return 1;
    }

    // 2. Convert string to integer using strtol
    char* endptr;
    long num = strtol(input, &endptr, 10);

    // 3. Validate conversion and apply conditional logic
    // Check if any digits were consumed at all
    if (endptr == input) {
        printf("Invalid input: not a number.\n");
    } else {
        if (num >= 1 && num <= 9) {
            // Use num as a 1-based index mapped to the 0-indexed array
            printf("%s\n", numbers[num - 1]);
        } else if (num > 9) {
            printf("Greater than 9\n");
        } else {
            printf("Less than 1\n");
        }
    }

    // 4. Free the dynamically allocated string
    free(input);

    return 0;
}

