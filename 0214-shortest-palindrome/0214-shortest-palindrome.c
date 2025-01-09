#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int len, char* reversed) {
    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - i - 1];
    }
    reversed[len] = '\0';
}

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) {
        // If the input string is empty, return an empty string
        return strdup("");
    }

    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    reverseString(s, len, reversed);

    int maxPalindromePrefix = 0;
    for (int i = 0; i < len; i++) {
        if (strncmp(s, reversed + i, len - i) == 0) {
            maxPalindromePrefix = len - i;
            break;
        }
    }

    char* result = (char*)malloc((2 * len - maxPalindromePrefix + 1) * sizeof(char));
    strncpy(result, reversed, len - maxPalindromePrefix);
    strcpy(result + len - maxPalindromePrefix, s);

    free(reversed); // Free the memory used for the reversed string
    return result;
}
