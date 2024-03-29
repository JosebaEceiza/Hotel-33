#include<stdio.h>
#include"cabecera.h"

void main(){
    crearBD();


    printf("BIENVENIDO A HOTEL 33");
    printf("\n1. Iniciar Sesion");
    printf("\n2. Registrar Usuario");
    printf("\n3. Salir del programa");

    int ve = 1;
    if (ve == 1){

        //INICIAR SESION
        printf("\n1. Realizar reserva");
        printf("\n2. Anular reserva");
        printf("\n3. Historial de reservas por cliente (DNI)");
        printf("\n4. Consultar datos habitaciones");
        printf("\n5. Consultar datos usuario");
        printf("\n6. Cerrar sesion");

    }
    else if (ve == 2){

        //REGISTRAR USUARIO
        printf("Introduzca su nombre: ");
        printf("Introduzca su apellido: ");
        printf("Introduzca su DNI: ");
        printf("Introduzca su contraseña: ");

    }

    else if (ve == 3){

        //SALIR DEL PROGRAMA

    }
}