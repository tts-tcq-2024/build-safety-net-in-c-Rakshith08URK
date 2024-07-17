#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SOUNDEX_CODE_LENGTH 4
#define SOUNDEX_CODE_SIZE (MAX_SOUNDEX_CODE_LENGTH + 1)

static const char soundex_map[] = {
    'b', 'f', 'p', 'v', // b, f, p, v
    'c', 'g', 'j', 'k', 'q', 's', 'x', 'z', // c, g, j, k, q, s, x, z
    'd', 't', // d, t
    'l', // l
    'm', 'n', // m, n
    'r', // r
};

static char get_soundex_code(char c) {
    c = tolower(c);
    const char* p = strchr(soundex_map, c);
    return p ? '1' + (p - soundex_map) / 7 : '0';
}

static void init_soundex_code(char* soundex_code) {
    soundex_code[0] = '\0';
}

static void encode_first_char(const char* str, char* soundex_code) {
    soundex_code[0] = toupper(str[0]);
}

static void encode_remaining_chars(const char* str, char* soundex_code) {
    int code_idx = 1;
    for (int i = 1; i < strlen(str); i++) {
        char c = tolower(str[i]);
        char code = get_soundex_code(c);
        if (code != '0' && code != soundex_code[code_idx - 1]) {
            soundex_code[code_idx++] = code;
        }
    }
}

static void pad_with_zeros(char* soundex_code) {
    int code_idx = strlen(soundex_code);
    while (code_idx < MAX_SOUNDEX_CODE_LENGTH) {
        soundex_code[code_idx++] = '0';
    }
    soundex_code[code_idx] = '\0'; // null-terminate
}

char* soundex(const char* str) {
    static char soundex_code[SOUNDEX_CODE_SIZE];
    init_soundex_code(soundex_code);
    encode_first_char(str, soundex_code);
    encode_remaining_chars(str, soundex_code);
    pad_with_zeros(soundex_code);
    return soundex_code;
}

#endif // SOUNDEX_H
