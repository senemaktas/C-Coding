
#include <stdio.h>

int main(){

   int kare_kenar,kkenar,ukenar,karealan,dikdalan;
   void alanlar(int *kare_kenar,int *kkenar,int *ukenar,int karealan,int dikdalan);

   printf("sirasiyla kare kanerini, kisa kenari, uzun kenarin degerlerini girin..\n");
   scanf("%d %d %d", &kare_kenar,&kkenar,&ukenar);

   alanlar(&kare_kenar,&kkenar,&ukenar,&karealan,&dikdalan);
   printf("karenin alani %d\n",karealan);
   printf("dikdortgenin alani %d\n",dikdalan);

   return 0;
}

void alanlar(int *kare,int *kisa,int *uzun,int *kalan,int *dalan){
 *kalan=*kare * *kare;
 *dalan=*kisa * *uzun;
}
