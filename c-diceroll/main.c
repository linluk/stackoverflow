/*
 * http://stackoverflow.com/questions/27970387/how-to-count-the-number-of-time-a-random-number-is-generated-in-a-less-cumbersom
 * Copyright (C) 2015 Lukas Singer
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define ROLL_TIMES (1000)
int main(int argc, char** argv) {
  int counts[6] = {0};
  int i;
  srand(time(NULL));
  for(i=0;i<ROLL_TIMES;i++) {
    counts[rand()%6]++;
  }
  for(i=0;i<6;i++){
    printf("%d times %d\n",counts[i],i+1);
  }
  return 0;
}
