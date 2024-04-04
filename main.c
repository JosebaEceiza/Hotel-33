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
        fflush(stdin);
        excepcionNumeros(&ve);

        if (ve == '1'){
            char ve1;
            while (ve1 != '6'){
                //INICIAR SESION

                printf("\n INICIO SESION\n");
                char *str1 = malloc(15*sizeof(char));
                char *str2 = malloc(15*sizeof(char));
                Usuario *usuario = malloc(sizeof(Usuario));


                printf("Introduzca su DNI: ");
                scanf("%s", str1);  
                fflush(stdin); 

    
                printf("Introduzca su contrasena: ");
                scanf("%s",str2);
                fflush(stdin); 


                (*usuario).DNI = str1;
                (*usuario).contrasena = str2;
                
                free(str1);
                free(str2);

                int acceso = loggear(usuario);  //esto devolvera un 1(true) o 0(false) no?
                if (acceso == 0){
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
                        free(usuario);
                        break;
                    }

                    ve1 = getchar();
                    fflush(stdin); 

                }
                else{
                    printf("\nDatos incorrectos");
                    printf("\nSi quieres salir pulsa 6, sino, pulsa otro boton: ")  ;
                    ve1 = getchar();
                    
                }
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
            excepcionDNI(str1);

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