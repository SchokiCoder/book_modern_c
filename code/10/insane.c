#include <stdbool.h>

int main()
{
        int myNumber = 22;
        bool num_even_or_not = false;
        bool i_have_a_bad_feeling_about_this = false;
        if ((myNumber % 2) == 0) {num_even_or_not = true;}
        switch (myNumber) {
                case 0:
                        myNumber = 1;
                        break;
                case 7:
                        myNumber *= 3;
                break;
                case 43:
                        myNumber = -1;
                        break;
                case 1:
                        myNumber = 0;
                        break;
                case 23:
                        if (num_even_or_not) {
                                i_have_a_bad_feeling_about_this = true; }
                        break;
                case 68: myNumber++;
                case 101:
                        myNumber /= 2;
                        break;
        }
}
