//v0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "NDB.h"

int main(){

  int b1,b2;
  int b3;
  char cmd[1];
  const char* n = "n";
  int op; //DERIVATED ARE WORKING

  while(1){

    while(1){
      printf("Select the operation: \n");
      printf("-----------------------------------------------------------------------\n");
      printf("Binary closed: \n");
      printf("(1)NOT (2)AND (3)OR  (4)DERIVATED(XOR, NOR,...)\n");
      printf("-----------------------------------------------------------------------\n");
      printf("ext: \n");
      printf("(5)GAMMA\n");
      printf("-----------------------------------------------------------------------\n");
      printf("I0 closed, but not binary closed: \n");
      printf("(6)SUM\n");
      printf("-----------------------------------------------------------------------\n");
      //printf("Visualization:\n");
      //printf("(7)Convert from I0 to Natural\n");
      //printf("-----------------------------------------------------------------------\n");
      scanf("%d", &op);
      if(op >= 1 && op <= 6 ){
        break;
      }else{
        printf("WRONG OPERATION!\n");
      }
    }

    while(1){
      printf("Insert a binary digit: ");
      scanf("%d", &b1);
      if(check_binary_form(b1)){
        break;
      }else{
        printf("WRONG DIGIT!\n");
      }
    }

    while(op != 1){
      printf("Insert a binary digit: ");
      scanf("%d", &b2);
      if(check_binary_form(b2)){
        break;
      }else{
        printf("WRONG DIGIT!\n");
      }
    }

    switch(op){
      case 1:
              printf("NOT(%d) =  %d \n", b1, !b1);
              break;
      case 5:
              b3 = gamma_(b1,b2);
              printf("GAMMA(%d, %d) =  %d \n", b1, b2, b3 );
              printf("In natural: %d\n", convert(b3));
              break;
      case 6:
              b3 = full_adder(b1,b2);
              printf("SUM(%d, %d) =  %d \n", b1, b2, b3);
              printf("In natural: %d + %d = %d \n",convert(b1), convert(b2), convert(b3));
              break;

      default:
              //I'm too lazy!
              break;
    }

    printf("continue? [y/n]\n");
    scanf("%s", &cmd);
    if(!strcmp(cmd,n)){
      return 0;
    }
  }
  return 0;
}
