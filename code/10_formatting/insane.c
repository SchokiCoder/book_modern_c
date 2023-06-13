#include <stdbool.h>

int main(){
    int my_number=22;
    bool num_even_or_not=false;
    bool i_have_a_bad_feeling_about_this = false;
    if((my_number%2)==0){num_even_or_not=true;}
    switch(my_number){
        case 0:
        my_number=1;
        break;
        case 7:
        my_number*=3;
        break;
        case 43:
        my_number=-1;
        break;
        case 1:
        my_number=0;
        break;
        case 23:
        if(num_even_or_not)
        {i_have_a_bad_feeling_about_this=true;}
        break;
        case 68:
        my_number++;
        break;
        case 101:
        my_number/=2;
        break;}
}
