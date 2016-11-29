#include <stdio.h>
#include <stdlib.h>

int main()    {
  setenv("TEST_ENV", "1234", 0);
  return 0;
}
