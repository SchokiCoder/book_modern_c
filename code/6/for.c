int main(void)
{
	int i;
	int a = 1;
	int b = 1;
	int c = 1;

	for (i = 0; i < 3; i++) {
		c = b;
		b = a;
		a = b + c;
	}
}
