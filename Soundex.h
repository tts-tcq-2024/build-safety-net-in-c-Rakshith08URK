#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}
 
// Function to check if a code is valid
int isValidCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}
 
// Function to check if the Soundex length is valid
int isSoundexLengthValid(const char* soundex) {
    return strlen(soundex) < 4;
}
 
// Function to add a Soundex code
void addSoundexCode(char* soundex, char code, char* prevCode) {
    if (isValidCode(code, *prevCode) && isSoundexLengthValid(soundex)) {
        int len = strlen(soundex);
        soundex[len] = code;
        soundex[len + 1] = '\0';
        *prevCode = code;
    }
}
 
// Function to update the Soundex code based on the name
void updateSoundex(char* soundex, const char* name, char* prevCode) {
    for (int i = 1; name[i] != '\0'; ++i) {
        char code = getSoundexCode(name[i]);
        addSoundexCode(soundex, code, prevCode);
    }
    while (strlen(soundex) < 4) {
        strcat(soundex, "0");
    }
}
 
// Function to generate the Soundex code for a given name
void generateSoundex(const char* name, char* soundex) {
    if (name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
    char prevCode = getSoundexCode(soundex[0]);
    updateSoundex(soundex, name, &prevCode);
}
 
int main() {
    const char* name = "Example";
    char soundex[5] = "";  // Initialize the soundex string
    generateSoundex(name, soundex);
    printf("Soundex code for %s is %s\n", name, soundex);
    return 0;
}
