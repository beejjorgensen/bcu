#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_BOLD_RED "\x1b[1;31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_FULL_RESET "\x1b[0m"

#define OK_CHECK "\u2713"   // ✓
#define NOK_CHECK "\u2715"  // ✕

#define BCU_TEST(x, y, t, pt) do {  \
    if (t) { \
        printf("%s%s passed:%s %s line %d: %s\n", COLOR_GREEN, OK_CHECK, COLOR_FULL_RESET, __FILE__, __LINE__, pt); \
    } else { \
        printf("%s%s FAILED:%s %s line %d: %s\n", COLOR_BOLD_RED, NOK_CHECK, COLOR_FULL_RESET, __FILE__, __LINE__, pt); \
        bcu_test_exit_code = 1; \
    } \
} while(0);

#define BCU_TEST_EQUAL(x, y)       BCU_TEST((x), (y), (x) == (y), #x " == " #y)
#define BCU_TEST_NOTEQUAL(x, y)    BCU_TEST((x), (y), (x) != (y), #x " != " #y)
#define BCU_TEST_STREQUAL(x, y)    BCU_TEST((x), (y), strcmp((x),(y)) == 0, #x " == " #y)
#define BCU_TEST_NOTSTREQUAL(x, y) BCU_TEST((x), (y), strcmp((x),(y)) != 0, #x " != " #y)

static int bcu_test_exit_code = 0;

#define BCU_EXIT() exit(bcu_test_exit_code)