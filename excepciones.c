#include"cabecera.h"
#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include <time.h>




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


void excepionAnyoReserva(int *anyo){
    time_t tiempo_actual;
    struct tm* tiempo_info;
    time(&tiempo_actual);
    tiempo_info = localtime(&tiempo_actual);

    int anyo_actual = tiempo_info->tm_year + 1900;

    while (*anyo < anyo_actual || *anyo >= anyo_actual+50){
        printf("El ano introducido debe ser mayor que %d. Intentelo de nuevo: ", anyo_actual);
        scanf("%d", anyo);
        fflush(stdin);
    }

}



void excepionMesReserva(int *mes){
    while(*mes < 1 || *mes > 12){
         printf("El mes introducido es incorrecto. Intentelo de nuevo: ");
         scanf("%d", mes);
         fflush(stdin);
    }
}


void excepcionDiaReserva(int *mes , int *dia){
    int valido = 0;
    while(valido != 1){
        if(*mes % 2 == 0 && *mes != 2 && *dia <= 31 && *dia >= 1){
            valido = 1;
        }
        else if(*mes % 2 != 0 && *dia <= 30 && *dia >= 1){
            valido = 1;
        }
        else if(*mes == 2 && *dia <= 28 && *dia >= 1 ){
            valido = 1;
        }
        else{
            printf("El dia introducido es incorrecto. Intentelo de nuevo: ");
            scanf("%d", dia);
            fflush(stdin);

        }

    }
}



void excepcionNumeroPersonas(int *num){
    while(*num >= 5 || *num <= 0){
        printf("El numero de personas tiene que estar entre 1 y 4. Intentelo de nuevo:");
        scanf("%i", num);
        fflush(stdin);
    }

}


void excepcionNumeroTelefono(char *str){
    int numerosCorrectos = 0;
    int valido = 0;
    while(valido != 1){
        int numerosCorrectos = 0;
        
        for(int i = 0; i < strlen(str); i++){
            if(isdigit(str[i])){
                numerosCorrectos++;
            }
        }
        if(numerosCorrectos == 9){
            valido = 1;
        }
        else{
            printf("El numero de telefono debe tener 9 digitos. Intentelo de nuevo:");
            scanf("%s", str);
            fflush(stdin);
        }
    }

}



void excepcionNumeroTarjeta(char *str){
    int numerosCorrectos = 0;
    int valido = 0;
    while(valido != 1){
        int numerosCorrectos = 0;
        
        for(int i = 0; i < strlen(str); i++){
            if(isdigit(str[i])){
                numerosCorrectos++;
            }
        }
        if(numerosCorrectos == 16){
            valido = 1;
        }
        else{
            printf("El numero de tarjeta debe tener 16 digitos. Intentelo de nuevo:");
            scanf("%s", str);
            fflush(stdin);
        }
    }

}