#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"cabecera.h"
#include"sqlite3.h"



void main(){
    crearBD();

    char ve;
    while (ve != '3'){
        fflush(stdin);

        printf("BIENVENIDO A HOTEL 33");
        printf("\n1. Iniciar Sesion");
        printf("\n2. Registrar Usuario");
        printf("\n3. Salir del programa\n");
        printf("Introduzca la opcion deseada: ");
        ve = getchar();
        fflush(stdin);
        excepcionNumeros(&ve);

        if (ve == '1'){
            while (ve != '6'){
                //INICIAR SESION

                printf("\n INICIO SESION\n");
                char str1[15];
                char str2[15];
                Usuario *usuario = malloc(sizeof(Usuario));


                printf("Introduzca su DNI: ");
                scanf("%s", str1);
                fflush(stdin); 
                str1[8] = toupper(str1[8]);

    
                printf("Introduzca su contrasena: ");
                scanf("%s",str2);
                fflush(stdin); 


                (*usuario).DNI = str1;
                (*usuario).contrasena = str2;
                
                

                int acceso = loggear(usuario);  //esto devolvera un 1(true) o 0(false)
                
                if (acceso == 0){
                    while (acceso == 0){
                        printf("\n1. Realizar reserva");
                        printf("\n2. Anular reserva");
                        printf("\n3. Historial de reservas por cliente (DNI)");
                        printf("\n4. Consultar datos habitaciones");
                        printf("\n5. Consultar datos usuario");
                        printf("\n6. Cerrar sesion");
                        printf("\nIntroduzca la opcion deseada:");

                        ve = getchar();
                        fflush(stdin); 

                        if (ve == '1'){
                            Reserva *r = malloc(sizeof(Reserva));
                            printf("¿Tiene registrado sus datos? (Si es asi pulsa S): ");
                            char registro = getchar();
                            fflush(stdin); 

                            if ((registro == 'S') || (registro =='s')){

                                printf("\nIndique su DNI: ");
                                scanf("%s", (*r).DNI);  
                                (*r).fecha_ini;
                                (*r).fecha_fin;
                            }
                            else{
                                Cliente *c = malloc(sizeof(Cliente));
                                if (c == NULL) {
                                    printf("Error: No se pudo asignar memoria para el cliente.\n");
                                    exit(1);
                                    }

                                printf("\nIndique su DNI: ");
                                scanf("%s", (*c).DNI);  
                                excepcionDNI((*c).DNI);

                                printf("\nIndique su nombre: ");
                                scanf("%s", (*c).nombre);  
                                excepcionNombre((*c).nombre);
                            
                                printf("\nIndique su apellido: ");
                                scanf("%s", (*c).apellido);  
                                excepcionApellido((*c).apellido);

                                printf("\nIndique su telefono: ");
                                scanf("%s", (*c).telefono);  
                                printf("\nIndique su numero de tarjeta: ");
                                scanf("%s", (*c).num_tarjeta);  
                                printf("\nIndique su anyo de nacimiento: ");
                                scanf("%i", &(*c).fecha_nac.anyo);  
                                printf("\nIndique su mes de nacimiento: ");
                                scanf("%i", &(*c).fecha_nac.mes);  
                                printf("\nIndique su dia de nacimiento: ");
                                scanf("%i", &(*c).fecha_nac.dia);  
                                fflush(stdin); 


                                Fecha fec = (*c).fecha_nac;
                                



                                registrarCliente(c);

                            }
                            realizarReserva();
                        }
                        else if (ve == '2'){
                            anularReserva();
                        }
                        else if (ve == '3'){
                        }
                        else if (ve == '4'){
                        }
                        else if (ve == '5'){
                        }
                        else if (ve =='6'){
                            free(usuario);
                            acceso = 1;
                        }
                    }
                }
                else{
                    printf("\nDatos incorrectos");
                    printf("\nSi quieres salir pulsa 6, sino, pulsa otro boton: ")  ;
                    ve = getchar();
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
            excepcionNombre(str2);

            printf("Introduzca su apellido: ");
            scanf("%s",str3);
            fflush(stdin); 
            excepcionApellido(str3);

            printf("Introduzca su contrasena: ");
            scanf("%s",str4);
            fflush(stdin); 
            excepcionContrasena(str4);


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