#include <stdio.h>

int
main(int argc, char **argv)
{
  if ((argc % 2) == 0)
    {
      printf("argc is even\n");
      return 0;
    }
  else
    return 1;
}
