#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"

int main(int argc, char **argv){
    if(argc==1){
        printf("Imprimo numeros en grados Celsius y Fahrenheit \n");
        return -1;
    }else{
        printf("--Celsius\t|\tFahrenheit--\n");
        for(int i=1; i<argc; i++){
            printf("|  %f", celsius(atoi(argv[i])));
            printf("\t|\t%f  |", fahrenheit(atoi(argv[i])));
            printf("\n");
        }
            return 0;
    }
}