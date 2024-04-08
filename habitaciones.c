#include<stdio.h>
#include<string.h>

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
    for ( int i = 1; i< 6 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = 'A';
        ha.capacidad = 2;


    }

    for ( int i = 6; i< 11 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = 'B';
        ha.capacidad = 3;


    }

    for ( int i = 11; i< 14 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = 'C';
        ha.capacidad = 4;


    }

    for ( int i = 14; i< 16 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = 'D';
        ha.capacidad = 4;


    }



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
    printf("\n\n\t(todas las habitaciones incluyen banos y duchas)");



}