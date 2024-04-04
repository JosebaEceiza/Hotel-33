#include"cabecera.h"
#include<stdio.h>
#include<ctype.h>
#include <string.h>




void excepcionNumeros(char *ve){
    while(isdigit(*ve) == 0){
        printf("\nError!Introduce un numero:");
        *ve = getchar();
        fflush(stdin);
    }
}


void excepcionDNI(char *str) {
    int valido = 0;
    while (valido != 1) {
        if(strlen(str) == 9) {
            int numerosCorrectos = 0;
            int i;
            for (i = 0; i < strlen(str) - 1; i++) {
                if(isdigit(str[i])){
                    numerosCorrectos++;
                }
            }

            if(isalpha(str[8]) && numerosCorrectos == 8) {
                valido = 1;

            } else{
                printf("Formato incorrecto. Introduzcalo de nuevo:");
                scanf("%s", str);        
                fflush(stdin);
                }
            
        } else {
            printf("Formato incorrecto. Introduzcalo de nuevo:");
            scanf("%s", str);        
            fflush(stdin);
        }
    }
}


