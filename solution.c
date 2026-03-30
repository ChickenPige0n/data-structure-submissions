#include <stdio.h>
#include <ctype.h>

void Solution();

int main() {
    Solution();
    return 0;
}

#define MAX_LINE_LENGTH 200000

// Using all ASCII comment in case the compiler is using GBK936...
void Solution() {
    char s[MAX_LINE_LENGTH];

    // `gets` is DEPRECATED in c99 and REMOVED later, using `fgets` is better.
    if (fgets(s, sizeof(s), stdin) == NULL) return;

    char *p = s;
    while (isspace(*p)) p++; // Skip leading spaces

    int isFirstWord = 1;
    while (*p != '\0') { // if encountered next word we are back to here

        // First find current word's range
        char *start = p; // `start` is the start of a word
        while (*p != '\0' && !isspace(*p)) p++; // Find end of word
        char *end = p;

        int foundFirstChar = 0;
        char *it;
        for (it = start; it < end; it++) { // Iterate through a word
            if (isalpha(*it)) {
                if (!foundFirstChar) {
                    *it = toupper(*it); // First letter to upper
                    foundFirstChar = 1; // Only CAPITALIZE first letter
                } else {
                    *it = tolower(*it); // Subsequent letters to lower
                }
            }
        }

        // Manually print a space
        // (since we skipped all spaces below, we have to manually print a space)
        if (!isFirstWord) putchar(' ');

        // Print the processed word
        for (it = start; it < end; it++) putchar(*it);
        isFirstWord = 0;

        while (isspace((unsigned char)*p)) p++; // Skip spaces between words
    }
}
