#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b) {
    return strcmp(*(const char**)b, *(const char**)a);
}
char* makeLargestSpecial(char* s) {
    int count = 0, start = 0;
    int len = strlen(s);
    char** substrings = (char**)malloc(len * sizeof(char*));
    int substrCount = 0;

    for (int i = 0; i < len; i++) {
        count += (s[i] == '1') ? 1 : -1;

        if (count == 0) {
            char* inner = (char*)malloc((i - start) * sizeof(char));
            strncpy(inner, s + start + 1, i - start - 1); // Extract inner part
            inner[i - start - 1] = '\0';

            char* largestInner = makeLargestSpecial(inner);
            free(inner);

            char* special = (char*)malloc((i - start + 2) * sizeof(char));
            sprintf(special, "1%s0", largestInner);
            free(largestInner);

            substrings[substrCount++] = special;
            start = i + 1; 
        }
    }

    qsort(substrings, substrCount, sizeof(char*), compare);

    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[0] = '\0'; // Initialize as an empty string

    for (int i = 0; i < substrCount; i++) {
        strcat(result, substrings[i]);
        free(substrings[i]); 
    }

    free(substrings); 
    return result;
}
