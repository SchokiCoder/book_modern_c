int main(void)
{
        int a = 1;
        int b = 1;
        int c = 1;

        do {
                c = b;
                b = a;
                a = b + c;
        }
        while (a < 100);
}
