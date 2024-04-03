#include"cabecera.h"
#include<stdio.h>
#include<ctype.h>



void excepcionNumeros(char *ve){
    while(isdigit(*ve) == 0){
        printf("\nError!Introduce un numero:");
        *ve = getchar();
        fflush(stdin);

 
    }

}
