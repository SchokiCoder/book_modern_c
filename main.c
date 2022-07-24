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


	printf("f: %f\n", floatadd(0.1, 0.4));

void intptr( int* ptr )
{
	*ptr = 6;
}*/

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
#define PRINT_LEN (HELLOWORLD_LEN + 4)

int main( void )
{
	char temp[4] = {'\0'};

	char arrfit[HELLOWORLD_LEN] = "Hello World";
	char arrmore[HELLOWORLD_LEN + 2] = "Hello World";
	const char *ptr = "Hello World";

	//print all string values
	printf("char | arrfit | arrmore | ptr\n");
	
	for (unsigned int i = 0; i < PRINT_LEN; i++)
	{
		if (arrfit[i] == arrmore[i] &&
			arrmore[i] == ptr[i])
		{
			temp[0] = '\'';
			temp[1] = arrfit[i];
			temp[2] = '\'';
			temp[3] = '\0';
		}
		else
		{
			temp[0] = 'N';
			temp[1] = 'A';
			temp[2] = '\0';
		}

		printf("%4s | %6i | %7i | %4i\n",
			temp, arrfit[i], arrmore[i], ptr[i]);
	}
}*/


/*
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t stringlen( const char *str )
{
	size_t result = 0;

	while (str[result] != '\0')
		result++;

	return result + 1;
}

void stringcpy( char *restrict dest, const char *restrict src, size_t len )
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

void String_ensure_size( String *str, size_t size )
{
	while (str->size < size)
		str->size *= 2;
	
    str->str = realloc(str->str, str->size);
}

void String_append( String *dest, char *addendum )
{
	size_t add_len = stringlen(addendum);
	
	String_ensure_size(dest, dest->len + add_len);

	stringcpy(&dest->str[dest->len], addendum, add_len);

	dest->len += add_len;
}

void String_clear( String *str )
{
	free(str->str);
	str->len = 0;
	str->size = 0;
}

void String_debug( String *str )
{
	printf("stringdbg:\tstr  %p\n\t\tlen  %lu\n\t\tsize %lu\n",
		str->str, str->len, str->size);
	printf("content: {\n");

	for (size_t i = 0; i < str->size; i++)
	{
		printf("\t\t%c %i\n", str->str[i], str->str[i]);
	}

	printf("}\n");
}

int main( void )
{
	String intro = String_new(20);
	String_append(&intro, "Hello World,");
String_debug(&intro);
	String_append(&intro, " i am a string.");
String_debug(&intro);
	
	printf("%s\n", intro.str);
String_debug(&intro);
	String_clear(&intro);
}*/


/*
#include <stdio.h>

int main( void )
{
	long int li = 10000000000;
	int i = li;

	printf("%li to %i\n", li, i);
}*/


/*
#include <stdio.h>

int addi( int a, int b )
{
	return a + b;
}

float addf( float a, float b )
{
	return a + b;
}

#define add(A, B) _Generic((A) + (B), \
	int: addi, \
	float: addf)(A, B)

int main ( void )
{
	int a1 = 1, b1 = 2, c1;
	float a2 = 1.1, b2 = 1.5, c2;

	c1 = add(a1, b1);
	c2 = add(a2, b2);

	printf("%i %f\n", c1, c2);
}*/


/*
#include <stdio.h>
#include <string.h>

void reverse1(const char *src, char* dest, unsigned int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		dest[i] = src[len - i - 1];
	}

	dest[len] = '\0';
}

void reverse2(char *str)
{
	unsigned int len = strlen(str);
	
	for (unsigned int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main( void )
{
	char str1[16] = "Hello World";
	char str2[16];

	reverse1(str1, str2, strlen(str1));

	printf("method 1: \"%s\" copy to \"%s\"\n", str1, str2);

	reverse2(str1);

	printf("method 2: \"%s\"\n", str1);
}*/


/*
#include <stdio.h>

int a = 2, c = 0;

int triple( int b )
{
	a *= 3;
	return a;
}

int main( void )
{
	c = triple(a);

	printf("a: %i c: %i\n", a, c);
}*/

















































