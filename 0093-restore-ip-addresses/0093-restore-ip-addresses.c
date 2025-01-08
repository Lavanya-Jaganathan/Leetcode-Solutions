#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to check if a substring is a valid part of an IP address
bool isValidPart(char* s, int start, int end) {
    if (start > end) return false;
    if (s[start] == '0' && start != end) return false; // Leading zero case
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
        if (num > 255) return false; // Out of range
    }
    return true;
}

// Recursive function to generate valid IP addresses
void backtrack(char* s, int start, int dots, char* current, int currentIndex, char*** result, int* resultSize) {
    if (dots == 3) {
        if (isValidPart(s, start, strlen(s) - 1)) {
            strcpy(&current[currentIndex], &s[start]); // Add the last part
            (*result)[*resultSize] = strdup(current); // Save valid IP
            (*resultSize)++;
        }
        return;
    }

    for (int i = start; i < strlen(s); i++) {
        if (isValidPart(s, start, i)) {
            int len = i - start + 1;
            strncpy(&current[currentIndex], &s[start], len); // Copy valid part
            current[currentIndex + len] = '.'; // Add a dot
            backtrack(s, i + 1, dots + 1, current, currentIndex + len + 1, result, resultSize);
        } else {
            break;
        }
    }
}

// Main function to restore IP addresses
char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    if (strlen(s) < 4 || strlen(s) > 12) return NULL;

    char** result = malloc(100 * sizeof(char*)); // Dynamic array to store results
    char current[16] = {0};                      // To store the current IP being formed

    backtrack(s, 0, 0, current, 0, &result, returnSize);

    return result;
}

