#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(){

   int key;
   int x=;
   printf("Enter a character.....\n");
   
   do{
      key=getchar();
      printf(" Press the "z" key to exit the loop .. the entered character = %c and X value = %d  \n"key, x++);
   
   } while(key !="z");
   
printf("The cycle is over here!..");

return 0;
}
