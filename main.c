/*
#include <stdbool.h>

#include "intstuff.h"
#include "floatstuff.h"

int add(int a, int b)
{
	return a + b;
}

int a = 1;
	int b = 1;
	int c = 1;

	while (a < 100)
	{
		printf("%i\n", a);

		c = b;
		b = a;
		a = b + c;
	}
*/

	/*int a = 2147483647;
	printf("%i\n", a);*/


	/*int sum = add(10, 5);
	printf("%i\n", sum);*/

/*
	int num = 0;

	switch (num)
	{
		case 0:
			num = 1;
			break;

		case 1:
			num = 0;
			break;

		case 7:
			num *= 3;
			break;

		case 43:
			num = -1;
			break;

		case 68:
			num++;
			break;

		case 101:
			num /= 2;
			break;
	}

	return 0;
*/
/*
	int num = 22;
	bool num_even = false;
	bool something_is_not_right = false;

	if ((num % 2) == 0)
	{
		num_even = true;
	}

	if (num == 23 && num_even)
	{
		something_is_not_right = true;
	}
*/

/*	int my_number=22;
	bool num_even_or_not=false;
	bool i_have_a_bad_feeling_about_this = false;
	if((my_number%2)==0){num_even_or_not=true;}
	switch(my_number){
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
		if(num_even_or_not){i_have_a_bad_feeling_about_this=true;}
		case 43:
		my_number=-1;
		break;
		case 68:
		my_number++;
		break;
		case 101:
		my_number/=2;
		break;}
*/

	//printf("f: %f\n", floatadd(0.1, 0.4));

void intptr( int* ptr )
{
	*ptr = 6;
}

/*
	int myint = 1;
	int* ppptr;

	*ppptr = 6;

	printf("%i\n", myint);

	intptr(&myint);

	printf("%i\n", myint);*/

/*#include <stdlib.h>

int main()
{
	int* ptr = malloc(sizeof(int));
	
	*ptr = 7;

	printf("%i\n", sizeof(*ptr));

	free(ptr);
}
*/

/*#include <stdio.h>


	int myint = 44;

	printf("Hello world\n");
	printf("Hello int: %i\n", 66);
	printf("Hello int variable: %i\n", myint);
	printf("Hello string: %s\n", "hi, i'm a string");
	printf("hi i am a \"real\" boy\n");
}*/

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	const unsigned int ARR_LEN = 20;
	int *array = malloc(ARR_LEN * sizeof(int));

	for (int i = 0; i < ARR_LEN; i++)
	{
		printf("i: %i; val: %i\n", i, array[i]);
	}

	free(array);
}*/

/*typedef unsigned int user_id;

#include <string.h>
#include <stdio.h>

typedef struct Message
{
	user_id sender_id;
	user_id receiver_id;
	char content[256];
} Message ;

Message receive_message(int my_id)
{
	Message result;

	result.sender_id = 32;
	result.receiver_id = my_id;
	strcpy(result.content, "1 message from your pal");

	return result;
}

int main()
{
	Message simulated_msg = receive_message(10);

	printf(
		"from: %i\nto: %i\n\n%s\n",
		simulated_msg.sender_id,
		simulated_msg.receiver_id,
		simulated_msg.content);
}*/
/*
void draw( int red, int green, int blue )
{}

typedef enum Color
{
	C_RED,
	C_GREEN,
	C_BLUE,
} Color ;

int main()
{
	Color bg_color = C_GREEN;

	switch (bg_color)
	{
		case C_RED:
			draw(255, 0, 0);
			break;

		case C_GREEN:
			draw(0, 255, 0);
			break;

		case C_BLUE:
			draw(0, 0, 255);
			break;
	}
}*/

/*
#include <stdio.h>

int main( void )
{
	unsigned int unflipped = 4000000000;
	signed int flipped = (signed int) unflipped;
	
	printf("%u flipped to %i\n", unflipped, flipped);
}*/

/*
#include <stdio.h>

#define HELLOWORLD_LEN 11
#define PRINT_LEN HELLOWORLD_LEN + 2

int main( void )
{
	char arrtext[HELLOWORLD_LEN] = "Hello World";
	char *ptrtext = "Hello World";
	
	for (unsigned int i = 0; i < PRINT_LEN; i++)
	{
		printf("%1c: %3i vs %1c: %3i\n",
			arrtext[i], arrtext[i], ptrtext[i], ptrtext[i]);
	}
}*/

#include <stddef.h>
#include <stdlib.h>

size_t str_len( const char *str )
{
	size_t result = 0;

	while (str[result] != '\0')
		result++;

	return result + 1;
}

void str_cpy( char *restrict dest, const char *restrict src, size_t len )
{
	for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }

    dest[len - 1] = '\0';
}

typedef struct String
{
	char *str;
	size_t size;
	size_t len;
} String ;

String String_new( const size_t inital_size )
{
	String result = {
		.str = malloc(inital_size),
		.len = 0,
		.size = inital_size
	};

	return result;
}

void String_append( SM_String *restrict dest, SM_String *restrict addendum )
{
	String_ensure_size(dest, dest->len + addendum->len + 1);

	strcpy(&dest->str[dest->len], addendum->str, addendum->len + 1);

	dest->len += addendum->len;
}

void String_clear( SM_String *str )
{
	free(str->str);
	str->len = 0;
	str->size = 0;
}

int main( void )
{
	Struct intro = String_new(20);
	String_append("Hello World,");
	String_append(" i am a string.");
	
	printf("%s\n", intro.str);
}


























































