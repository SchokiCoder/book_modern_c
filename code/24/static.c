#include <stdio.h>

void func()
{
        static long unsigned i = 0;
        
        i += 1;
        printf("%lu\n", i);
}

int main()
{
        func();
        func();
        func();
}
