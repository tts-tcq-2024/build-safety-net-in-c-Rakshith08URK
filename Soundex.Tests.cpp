#include <gtest/gtest.h>
#include "Soundex.h"
#include <assert.h>

void test_soundex_simple() {
    const char* input = "hello";
    const char* expected = "H400";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}
