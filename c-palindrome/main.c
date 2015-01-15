/*
 * http://stackoverflow.com/questions/22361865/c-palindrome-bool-function-using-pointer
 * Copyright (C) 2015 Lukas Singer
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrom(char * s){
  int i;
  int l = strlen(s);
  for(i=0;i<=l/2;i++)
    if(s[i]!=s[l-i-1])
      return 0;
  return 1;
}

int main(void) {
  char * test = "test";
  char * pal = "palap";
  printf("%s %d\n", test, palindrom(test));
  printf("%s %d\n", pal, palindrom(pal));
  return 0;
}
