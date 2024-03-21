int main(void)
{
        int a = 10, b = 2;

start:

        if (a == 10)
                a = 0;

        if (b == 2) {
                b++;
                goto start;
        }

        return 0;
}
