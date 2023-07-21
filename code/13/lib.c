#include "lib.h"

int some_math(const int a, const int b)
{
        if (a > 11)
                return a + b;
        else
                return (a * a) - b;
}
