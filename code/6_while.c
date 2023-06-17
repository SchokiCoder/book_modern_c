int main(void)
{
	int a = 1;
	int b = 1;
	int c = 1;

	while (a < 100) {
		c = b;
		b = a;
		a = b + c;
	}
}
