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
                str[8] = toupper(str[8]);
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


void excepcionNombre(char *str){
    int valido = 0;
    while(valido != 1){
        str[0] = toupper(str[0]);
        int existeNumero = 0;
        int i;

        for(i = 1; i < strlen(str); i++){
            str[i] = tolower(str[i]);

            if(isdigit(str[i])){
                existeNumero = 1;
                }
            }
        

        if(existeNumero == 0){
            if(strlen(str) < 2 || strlen(str) > 15){
                printf("El nombre debe contener entre 2 y 15 caracteres. Intentelo de nuevo:");
                scanf("%s", str);
                fflush(stdin);  
            }

            else{
                valido = 1;
            }
        }

        else{
            printf("El nombre  no debe contener numeros. Intentelo de nuevo:");
            scanf("%s", str);
            fflush(stdin);
        }
    } 
}






void excepcionApellido(char *str){
    int valido = 0;
    while(valido != 1){
        str[0] = toupper(str[0]);
        int existeNumero = 0;
        int i;

        for(i = 1; i < strlen(str); i++){
            str[i] = tolower(str[i]);

            if(isdigit(str[i])){
                existeNumero = 1;
                }
            }
        

        if(existeNumero == 0){
            if(strlen(str) < 2 || strlen(str) > 15){
                printf("El apellido debe contener entre 2 y 15 caracteres. Intentelo de nuevo:");
                scanf("%s", str);
                fflush(stdin);  
            }

            else{
                valido = 1;
            }
        }

        else{
            printf("El apellido  no debe contener numeros. Intentelo de nuevo:");
            scanf("%s", str);
            fflush(stdin);
        }
    } 
}



void excepcionContrasena(char *str){
    int valido = 0;
    while (valido != 1){
          if(strlen(str) >= 4 && strlen(str) <= 15){
            valido = 1;
            }
            else{
                printf("La contrasena debe contener entre 4 y 15 caracteres. Intentelo de nuevo:");
                scanf("%s", str);
                fflush(stdin);  
            }

}

}