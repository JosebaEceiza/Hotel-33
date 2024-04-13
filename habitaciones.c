#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sqlite3.h"
#include"cabecera.h"



int crearTipoHabitaciones(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *sql = "INSERT INTO TIPO_HABITACION VALUES (?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

   

    char tipoHabitacionA[1] = "A";
    int precioA = 50;

    sqlite3_bind_text(stmt, 1, tipoHabitacionA, 1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, precioA);

    result = sqlite3_step(stmt);

    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    sqlite3_finalize(stmt);



    sqlite3_stmt *stmt1;

    char *sql1 = "INSERT INTO TIPO_HABITACION VALUES (?,?);";
    int result1 = sqlite3_prepare_v2(db, sql1, -1, &stmt1, NULL);
    if (result1 != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}



    Tipo_habitacion tipoB;
    char tipoHabitacionB[1] = "B";
    int precioB = 80;

    sqlite3_bind_text(stmt1, 1, tipoHabitacionB, 1, SQLITE_STATIC);
    sqlite3_bind_int(stmt1, 2, precioB);

    result1 = sqlite3_step(stmt1);

    if (result1 != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    sqlite3_finalize(stmt1);



    sqlite3_stmt *stmt2;

    char *sql2 = "INSERT INTO TIPO_HABITACION VALUES (?,?);";
    int result2 = sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL);
    if (result2 != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

    Tipo_habitacion tipoC;
    char tipoHabitacionC[1] = "C";
    int precioC = 120;

    sqlite3_bind_text(stmt2, 1, tipoHabitacionC, 1, SQLITE_STATIC);
    sqlite3_bind_int(stmt2, 2, precioC);

    result2 = sqlite3_step(stmt2);

    if (result2 != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    sqlite3_finalize(stmt);


    sqlite3_stmt *stmt3;

    char *sql3 = "INSERT INTO TIPO_HABITACION VALUES (?,?);";
    int result3 = sqlite3_prepare_v2(db, sql3, -1, &stmt3, NULL);
    if (result3 != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
    Tipo_habitacion tipoD;
    char tipoHabitacionD[1] = "D";
    int precioD = 120;

    sqlite3_bind_text(stmt3, 1, tipoHabitacionD, 1, SQLITE_STATIC);
    sqlite3_bind_int(stmt3, 2, precioD);

    result3 = sqlite3_step(stmt3);

    if (result3 != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_close(db);
}


void crearHabitaciones(){

    sqlite3* db;
    int status = sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *error_message = 0;


   //INSERTS DE HABITACION TIPO A
    for ( int i = 1; i< 6 ; i++){
        char insert_sql[100];
        sprintf(insert_sql, "INSERT INTO HABITACION VALUES (%d,'%s','%s',%d);", i,"A","Habitacion",2);
        status = sqlite3_exec(db, insert_sql, 0, 0, &error_message);
        if (status != SQLITE_OK) {
            fprintf(stderr, "Error al insertar fila: %s\n", error_message);
            sqlite3_free(error_message);
        }
    }

    for ( int i = 6; i< 11 ; i++){
        char insert_sql[100];
        sprintf(insert_sql, "INSERT INTO HABITACION VALUES (%d,'%s','%s',%d);", i,"B","Habitacion",3);
        status = sqlite3_exec(db, insert_sql, 0, 0, &error_message);
        if (status != SQLITE_OK) {
            fprintf(stderr, "Error al insertar fila: %s\n", error_message);
            sqlite3_free(error_message);
        }
    }

    for ( int i = 11; i< 14 ; i++){
        char insert_sql[100];
        sprintf(insert_sql, "INSERT INTO HABITACION VALUES (%d,'%s','%s',%d);", i,"C","Habitacion",4);
        status = sqlite3_exec(db, insert_sql, 0, 0, &error_message);
        if (status != SQLITE_OK) {
            fprintf(stderr, "Error al insertar fila: %s\n", error_message);
            sqlite3_free(error_message);
        }


    }

    for ( int i = 14; i< 16 ; i++){
        char insert_sql[100];
        sprintf(insert_sql, "INSERT INTO HABITACION VALUES (%d,'%s','%s',%d);", i,"D","Habitacion",4);
        status = sqlite3_exec(db, insert_sql, 0, 0, &error_message);
        if (status != SQLITE_OK) {
            fprintf(stderr, "Error al insertar fila: %s\n", error_message);
            sqlite3_free(error_message);
        }


    }

    sqlite3_close(db);


}
    
int disponibilidadHabitaciones(Fecha fechaini, Fecha fechafin){
     sqlite3* db;
    int status = sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *sql = "SELECT HABITACION.ID_HABITACION FROM HABITACION INNER JOIN RESERVA_HOTEL ON HABITACION.ID_HABITACION=RESERVA_HOTEL.ID_HABITACION WHERE RESERVA_HOTEL.FECHA_FIN > ? OR RESERVA_HOTEL.FECHA_INI < ?;";
    int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL);
    if (result != SQLITE_OK){
        printf("Error preparanado setencia (SELECT)\n");
        printf("%s\n", sqlite3_errmsg(db));
        return 1;
    }
    char *fechaFormateadaInicio = malloc(11);
    sprintf(fechaFormateadaInicio, "%d-%02d-%02d", fechaini.anyo, fechaini.mes, fechaini.dia);

    char *fechaFormateadaFin = malloc(11);
    sprintf(fechaFormateadaFin, "%d-%02d-%02d", fechafin.anyo, fechafin.mes, fechafin.dia);

    sqlite3_bind_text(stmt, 1, fechaFormateadaInicio, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, fechaFormateadaFin, -1, SQLITE_STATIC);
    int lista[16] = {0};
    int valor = 0;
    while((result = sqlite3_step(stmt)) != SQLITE_DONE){
        valor = sqlite3_column_int(stmt, 0);
        lista[valor] = valor;
        printf("%i",valor);
    }

    int lista2[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for (int j = 0; j< 15;j++){
        if(lista[j] == j){
            lista2[j] = 0;
        }        
    }
    printf("\nHabitaciones disponibles: ");
    for(int k = 0; k<16;k++){
        if (lista2[k]!= 0){
            printf("\n%i",lista2[k]);}  
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

void mostrarHabitaciones(){

    printf("\n------------------TIPO HABITACIONES------------------");

    printf("\n\n\tHABITACIONES TIPO A:");

    printf("\n\t\tPRECIO: 50 $ x dia");
    printf("\n\t\tCapacidad: 1-2");
    printf("\n\t\tCama individual: 0");
    printf("\n\t\tCama matrimonial: 1");
    printf("\n\t\tServicio adicional: Ninguna");



    printf("\n\n\tHABITACIONES TIPO B:");

    printf("\n\t\tPRECIO: 80$ x dia");
    printf("\n\t\tCapacidad: 2-3");
    printf("\n\t\tCama individual: 1");
    printf("\n\t\tCama matrimonial: 1");
    printf("\n\t\tServicio adicional: Vistas al mar");



    printf("\n\n\tHABITACIONES TIPO C:");

    printf("\n\t\tPRECIO: 120$ x dia");
    printf("\n\t\tCapacidad: 4");
    printf("\n\t\tCama individual: 4");
    printf("\n\t\tCama matrimonial: 0");
    printf("\n\t\tServicio adicional: Terraza");



    printf("\n\n\tHABITACIONES TIPO D:");

    printf("\n\t\tPRECIO: 130$ x dia");
    printf("\n\t\tCapacidad: 3-4");
    printf("\n\t\tCama individual: 2");
    printf("\n\t\tCama matrimonial: 1");
    printf("\n\t\tServicio adicional: Wifi");
    printf("\n\n\t(todas las habitaciones incluyen banos y duchas)\n\n");

}