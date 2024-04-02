#include<stdio.h>
#include"cabecera.h"

void main(){
    crearBD();
    realizarReserva();


    printf("BIENVENIDO A HOTEL 33");
    printf("\n1. Iniciar Sesion");
    printf("\n2. Registrar Usuario");
    printf("\n3. Salir del programa\n");

    char ve = getchar();
    if (ve == '1'){

        //INICIAR SESION
        printf("\n1. Realizar reserva");
        printf("\n2. Anular reserva");
        printf("\n3. Historial de reservas por cliente (DNI)");
        printf("\n4. Consultar datos habitaciones");
        printf("\n5. Consultar datos usuario");
        printf("\n6. Cerrar sesion\n");
            char ve1 = getchar();
            if (ve1 = '1'){
                realizarReserva();
            }


    }
    else if (ve == '2'){

        //REGISTRAR USUARIO
        char str1[15];
        char str2[15];
        char str3[15];
        char str4[15];

        printf("Introduzca su DNI: ");
        scanf("%s", str1);        

        printf("Introduzca su nombre: ");
        scanf("%s", str2); 

        printf("Introduzca su apellido: ");
        scanf("%s",str3);

        printf("Introduzca su contrasena: ");
        scanf("%s",str4);
    
    

    }

    else if (ve == '3'){

        //SALIR DEL PROGRAMA

    }
}