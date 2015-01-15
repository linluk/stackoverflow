/*
 * http://stackoverflow.com/questions/22437104/simple-calculator-help-c
 * Copyright (C) 2015 Lukas Singer
 *
 * <expression> ::= <term>
 *                | <term> "+" <term>
 *                | <term> "-" <term>
 *
 * <term>       ::= <factor>
 *                | <factor> "*" <factor>
 *                | <factor> "/" <factor>
 *
 * <factor>     ::= <number>
 *                | "(" <expression> ")"
 *
 * <number>     ::= ["-"] ["0" .. "9"]*
 */

#include <stdio.h>
#include <stdlib.h>

char next;

void getNext(){
  next=getchar();
}

int getNum(){  //get a number
  int num=0;
  if((next<'0')||(next>'9')){
    printf("error: expected number; found %c",next);
    exit(-1);
  }
  while((next>='0')&&(next<='9')){
    num*=10;
    num+=(next-'0');
    getNext();
  }
  return num;
}

int add(int x){
  return x+term();
}
int sub(int x){
  return x-term();
}
int multiply(int x){
  return x*factor();
}
int divide(int x){
  return x/factor();
}

int factor(){
  int f=0;
  if(next=='('){
    getNext();
    f=expression();
    if(next=')')
      getNext();
    else{
      printf("error \")\" expected; found %c",next);
      exit(-1);
    }
  }else{
    f=getNum();
  }
  return f;
}

int term(){
  int val;
  val=factor();
  while((next=='*')||(next=='/')){
    char c=next;
    getNext();
    switch(c){
      case '*': val=multiply(val); break;
      case '/': val=divide(val); break;
      default: printf("error: (*, /) expected; found %c",next);
               exit(-1);
    }
  }
  return val;
}

int expression(){
  int sign=1;
  int val;
  if(next=='-'){
    sign=-1;
    getNext();
  }
  val=term()*sign;
  while((next=='+')||(next=='-')){
    char c=next;
    getNext();
    switch(c){
      case '+': val=add(val); break;
      case '-': val=sub(val); break;
      default: printf("error: (+, -) expected; found %c",next);
               exit(-1);
    }
  }
  return val;
}

int main(void) {
  getNext();
  printf("%d\n", expression());
  return 0;
}
