#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//max N bits
#define N 10

//i've should used char* for input and converted it into int[], this strategie suffers of overflow

int check_binary_form(int b){
  int tmp = 0;
  while(b){
    tmp = b % 10;
    if((tmp != 0 && tmp != 1)) return 0;
    b /= 10;
  }
  return 1;
}
int convert(int n) {
  int dec = 0, i = 0, rem;
  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  return dec;
}

int gamma_(int a, int b){ //concat/append
  char s1[20];
  char s2[20];

  // Convert both the integers to string
  sprintf(s1, "%d", a);
  sprintf(s2, "%d", b);

  // Concatenate both strings
  strcat(s1, s2);

  // Convert the concatenated string
  // to integer
  int c = atoi(s1);

  // return the formed integer
  return c;
}

int full_adder(int a, int b){
  //A + B + C_IN = S + C_OUT
  int a_digits[N], b_digits[N], s_digits[N];
  for(int i = 0; i < N; i++){
    a_digits[i] = a%10;
    b_digits[i] = b%10;
    a /= 10;
    b /= 10;
  }

  int carry_in = 0, carry_out = 0;

  //^ = XOR, DERIVATED FROM BASIC BINARY OPERATOR (AND, OR, NOT)

  for(int i = 0; i < N; i++){
    carry_in = carry_out;

    s_digits[i] = (a_digits[i] ^ b_digits[i] ^ carry_in );

    carry_out = ((a_digits[i] && b_digits[i]) || (a_digits[i] && carry_in));
  }

  int s = 0;

  for(int i = 0; i < N; i++){
    s += s_digits[i] * pow(10, i);
  }
  return s;
}
