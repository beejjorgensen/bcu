int add(int a, int b)
{
    return a + b;
}

#ifdef BCU_TEST_ENABLED
#include "bcu.h"

int main(void)
{
    BCU_TEST_EQUAL(add(1,2), 3);
    BCU_TEST_NOTEQUAL(add(1,2), 4);

    BCU_TEST_EQUAL(add(1,2), 3490);

    char s[128] = "foo";
    BCU_TEST_STREQUAL(strcat(s, "bar"), "foobar");

    BCU_EXIT();
}
#endif