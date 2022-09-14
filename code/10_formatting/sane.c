#include <stdbool.h>

int main( void )
{
    int my_number = 22;
    bool num_even = false;
    bool num_err = false;
    
    // if num even, flag
    if ((my_number % 2) == 0)
        num_even = true;
    
    switch (my_number)
    {
        case 0:
            my_number=1;
            break;
            
        case 1:
            my_number=0;
            break;
            
        case 7:
            my_number*=3;
            break;
            
        case 23:
            // explicit check needed for reason X
            if (num_even)
                num_err = true;
            break;
            
        case 43:
            my_number=-1;
            break;
            
        case 68:
            my_number++;
            break;
            
        case 101:
            my_number /= 2;
            break;
    }
}