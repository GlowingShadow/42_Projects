#include <stdio.h>
#include <string.h>
// compile with gcc -m32 temp.c

int main(int argc, char** argv) {
  printf(argv[1]);
  strdup(argv[1]);
}