#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

int main() {
  char* s = "hello";
  size_t l = strlen(s);
  char* r = (char*)malloc((l + 1) * sizeof(char));
  r[l] = '\0';
  int i;
  for(i = 0; i < l; i++) {
    r[i] = s[l - 1 - i];
  }
  printf("normal: %s\n", s);
  printf("reverse: %s\n", r);
  free(r);
}

/*int main() {*/
  /*char* s = "hello";*/
  /*size_t l = strlen(s);*/
  /*char c;*/
  /*int i;*/
  /*printf("normal: %s\n", s);*/
  /*for(i = 0; i < ((l-1) / 2); i++) {*/
    /*c = s[i];*/
    /*s[i] = s[l - i];*/
    /*s[l - i] = c;*/
  /*}*/
  /*s[l] = '\0';*/
  /*printf("reverse: %s\n", s);*/
/*}*/
