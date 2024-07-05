#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// Soundex constants
#define MAX_SOUNDEX_CODE_LENGTH 4
#define SOUNDEX_CODE_SIZE (MAX_SOUNDEX_CODE_LENGTH + 1)

// Soundex code mapping table
static const char soundex_map[] = {
    'b', 'f', 'p', 'v', // b, f, p, v
    'c', 'g', 'j', 'k', 'q', 's', 'x', 'z', // c, g, j, k, q, s, x, z
    'd', 't', // d, t
    'l', // l
    'm', 'n', // m, n
    'r', // r
};

// Function to convert a single character to its Soundex code
static char soundex_code(char c) {
    c = tolower(c);
    for (int i = 0; i < sizeof(soundex_map) / sizeof(soundex_map[0]); i++) {
        if (strchr(soundex_map, c)) {
            return '1' + (i / 7);
        }
    }
    return '0'; // default to 0 if not found
}

// Function to generate the Soundex code for a string
char* soundex(const char* str) {
    static char soundex_code[SOUNDEX_CODE_SIZE];
    int len = strlen(str);
    int code_idx = 0;

    // Convert the first character to uppercase
    soundex_code[code_idx++] = toupper(str[0]);

    // Iterate through the rest of the string
    for (int i = 1; i < len; i++) {
        char c = soundex_code(tolower(str[i]));
        if (c != '0' && c != soundex_code[code_idx - 1]) {
            soundex_code[code_idx++] = c;
        }
    }

    // Pad with zeros if necessary
    while (code_idx < MAX_SOUNDEX_CODE_LENGTH) {
        soundex_code[code_idx++] = '0';
    }

    soundex_code[code_idx] = '\0'; // null-terminate
    return soundex_code;
}

#endif // SOUNDEX_H
