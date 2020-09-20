#include <stdio.h>

int main(){

        float r1,r2,res1,res2;

        printf("2 tane direnc giriniz.\n");
        scanf("%f %f ",&r1,&r2);

        float paralel(float r1,float r2); // paralel protatif
        res1=paralel(r1,r2);
        printf("paralel esdeger direnc %f \n",res1);

        float seri(float r1,float r2);   // seri protatif
        res2=seri(r1,r2);
        printf("seri esdeger direnc %f \n",res2);

return 0;
}

float paralel(float r1,float r2){

        float rt,rtp;
        rt=(1/r1)+(1/r2);
        rtp=1/rt
        
 return rtp;
}

float seri(float r1,float r2){

        float rt;
        rt=r1,r2;

return rt;

}
