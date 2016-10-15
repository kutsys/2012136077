#include <stdio.h>
#include <stdlib.h>

int main()  {
  char buf[1024];
  FILE *in, *out;
  int nread;
  int cnt = 0;
  
  in = fopen("file.in", "r");
  out = fopen("file.out", "w");
  
  if(in != NULL && out != NULL) {
    while(!feof(in))  {
      nread = fread(buf, 1, 1024, in);
      fwrite(buf, 1, nread, out);
      if(++cnt % 1024 == 0) printf(".");
    }
    fclose(in);
    fclose(out);
  }
  exit(0);
}
