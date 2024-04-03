#include<stdio.h>
#include<stdlib.h>
#include"cabecera.h"
#include"sqlite3.h"



void main(){
    crearBD();

    char ve;
    while (ve != '3'){

        printf("BIENVENIDO A HOTEL 33");
        printf("\n1. Iniciar Sesion");
        printf("\n2. Registrar Usuario");
        printf("\n3. Salir del programa\n");
        printf("Introduzca la opcion deseada:");
        ve = getchar();

        if (ve == '1'){
            char ve1;
            while (ve1 != '6'){
                printf("\n INICIO SESION\n");
                char str1[15];
                char str2[15];
                Usuario *usuario;

                printf("Introduzca su DNI: ");
                scanf("%s", str1);  
                fflush(stdin); 
 

                printf("Introduzca su contrasena: ");
                scanf("%s",str2);
                fflush(stdin); 


                (*usuario).DNI = str1;
                (*usuario).contrasena = str2;

                loggear(usuario);  //esto devolvera un 1(true) o 0(false) no?

                //INICIAR SESION
                printf("\n1. Realizar reserva");
                printf("\n2. Anular reserva");
                printf("\n3. Historial de reservas por cliente (DNI)");
                printf("\n4. Consultar datos habitaciones");
                printf("\n5. Consultar datos usuario");
                printf("\n6. Cerrar sesion\n");
                
                if (ve1 == '1'){
                    realizarReserva();
                    }
                if (ve1 == '2'){
                    anularReserva();
                    }
                if (ve1 == '3'){
                    }
                if (ve1 == '4'){
                    }
                if (ve1 == '5'){
                    }
                if (ve1 =='6'){
                    break;
                    }

                ve1 = getchar();
                fflush(stdin); 

                }
            }
        else if (ve == '2'){

            //REGISTRAR USUARIO
            printf("\nREGISTRO USUARIO\n");
           
            char str1[15];
            char str2[15];
            char str3[15];
            char str4[15];

            printf("Introduzca su DNI: ");
            scanf("%s", str1);        
            fflush(stdin); 

            printf("Introduzca su nombre: ");
            scanf("%s", str2);
            fflush(stdin);  

            printf("Introduzca su apellido: ");
            scanf("%s",str3);
            fflush(stdin); 

            printf("Introduzca su contrasena: ");
            scanf("%s",str4);
            fflush(stdin); 


        Usuario *u1;
        u1 = (Usuario*) malloc(sizeof(Usuario));
        (*u1).DNI = str1;
        (*u1).nombre = str2;
        (*u1).apellido = str3;
        (*u1).contrasena = str4;

        registrarUsuario(u1);
        free(u1);
        u1 = NULL;
        }

        else if (ve == '3'){

            //SALIR DEL PROGRAMA

        }
    }
}