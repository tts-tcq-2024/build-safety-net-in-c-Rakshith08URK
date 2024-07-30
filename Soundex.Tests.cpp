#include <gtest/gtest.h>
#include "Soundex.h"
#include <assert.h>

void test_soundex_simple() {
    const char* input = "hello";
    const char* expected = "H400";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}

void test_soundex_vowels() {
    const char* input = "aeiou";
    const char* expected = "A000";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}

void test_soundex_numbers() {
    const char* input = "hello123";
    const char* expected = "H400";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}

void test_soundex_uppercase() {
    const char* input = "HELLO";
    const char* expected = "H400";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}

void test_soundex_mixed_case() {
    const char* input = "HeLlO";
    const char* expected = "H400";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}
