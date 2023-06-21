#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	
	printf("Welcome aboard captain\n"
	       "1) Brew coffee\n"
	       "2) Fire harpoon\n"
	       "3) Self destruct\n");
	
	scanf("%i", &i);
	
	switch (i) {
	case 1:
		printf("...\nCoffee ready\n");
		break;
	
	case 2:
		printf("Ammunition depleted\n");
		break;
	
	case 3:
		printf("Self destruct sequence initiated...");
		/* uncomment for real self-destruct :D
		while (1)
			malloc(sizeof(long long));
		*/
		break;
	
	default:
		printf("Option not recognised, good night\n");
		break;
	}
	
	return 0;
}
