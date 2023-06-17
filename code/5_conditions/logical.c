#include <stdbool.h>

int main(void)
{
	int num = 22;
	bool num_even = false;
	bool something_is_not_right = false;
	bool all_good;

	if ((num % 2) == 0) {
		num_even = true;
	}

	if (num == 23 && num_even == true) {
		something_is_not_right = true;
	}

	if (!something_is_not_right) {
		all_good = true;
	}
}
