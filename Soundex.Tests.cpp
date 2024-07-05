#include <gtest/gtest.h>
#include "soundex.h"
#include <assert.h>

void test_soundex_simple() {
    char* input = "hello";
    char* expected = "H400";
    char* actual = soundex(input);
    assert(strcmp(actual, expected) == 0);
}
