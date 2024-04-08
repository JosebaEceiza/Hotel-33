#include<stdio.h>
#include"sqlite3.h"
#include"cabecera.h"



void crearTipoHabitaciones(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *sql = "INSERT INTO USUARIO VALUES (?,?,?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

        Tipo_habitacion tipoA;
        tipoA.id_tipo_habitacion = 'A';
        tipoA.precio = 50;
        Tipo_habitacion tipoB;
        tipoB.id_tipo_habitacion = 'B';
        tipoB.precio = 80;
        Tipo_habitacion tipoC;
        tipoC.id_tipo_habitacion = 'C';
        tipoC.precio = 120;
        Tipo_habitacion tipoD;
        tipoD.id_tipo_habitacion = 'D';
        tipoD.precio = 130;

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