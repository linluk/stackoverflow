/*
 * http://stackoverflow.com/questions/27957085/adding-lines-in-a-file-to-an-array-in-c
 * Copyright (C) 2015 Lukas Singer
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define THRESHOLD (5)
int main(int argc,char** argv) {
  char* fn = "test";
  FILE* file = fopen(fn,"r");
  char** names = (char**)malloc(THRESHOLD * sizeof(char*));
  size_t i;
  for(i=0; i<THRESHOLD; i++) {
    names[i] = NULL;
  }
  size_t count = 0;
  while(getline(&names[count],&i,file) != EOF) {
    count++;
    if(count >= THRESHOLD) {
      names = (char**)realloc(names,(count+THRESHOLD)*sizeof(char*));
    }
  }
  names = (char**)realloc(names,count * sizeof(char*));
  for(i=0; i<count; i++) {
    printf("element %d, value %s",i,names[i]);
  }
  for(i=0; i<count; i++) {
    free(names[i]);
  }
  free(names);
  return 0;
}
