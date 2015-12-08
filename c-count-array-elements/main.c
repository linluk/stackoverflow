// http://stackoverflow.com/questions/34162369/count-elements-of-an-unknown-type-array
#include <stdio.h>
#include <stdlib.h>

int nb_elems(void** array) {
  void** end = array;
  while(*end != NULL) {
    end++;
  }
  return end - array;
}

int main() {

  int** iptrs = (int**)malloc(3 * sizeof(int*));

  iptrs[0] = (int*)malloc(sizeof(int));
  *(iptrs[0]) = 42;
  iptrs[1] = (int*)malloc(sizeof(int));
  *(iptrs[1]) = 23;
  iptrs[2] = NULL;

  printf("%d", nb_elems(iptrs));
}
