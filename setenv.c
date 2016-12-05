#include <stdio.h>
#include <stdlib.h>

int main()    {
  char *str = "TEST_ENV";
  setenv(str, "1234", 0);
  printf("%s = %s\n", str, getenv(str));
  return 0;
}
