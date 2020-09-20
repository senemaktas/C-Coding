
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int randomm,i;
    int arrayy[100];

    time_t t;
    srand((unsigned)time(&t));

    for(i=0;i<100;i++){
	    randomm=rand()%100;
	    arrayy[i]=randomm;
    }
    
    return 0;
}
