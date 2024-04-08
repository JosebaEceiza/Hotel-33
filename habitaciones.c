#include<stdio.h>
#include<sqlite3.h>
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

        TIPO_HABITACION tipoA;
        tipoA.ID_HABITACION = "A";
        tipoA.precio = 50;
        TIPO_HABITACION *tipoB;
        tipoB.ID_HABITACION = "B";
        tipoB.precio = 80;
        TIPO_HABITACION *tipoC;
        tipoC.ID_HABITACION = "C";
        tipoC.precio = 120;
        TIPO_HABITACION *tipoD;
        tipoD.ID_HABITACION = "D";
        tipoD.precio = 130;


}


void crearHabitaciones(){
    for ( int i = 1; i< 6 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = "A";
        ha.capacidad = 2;


    }

    for ( int i = 6; i< 11 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = "B";
        ha.capacidad = 3;


    }

    for ( int i = 11; i< 14 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = "C";
        ha.capacidad = 4;


    }

    for ( int i = 14; i< 16 ; i++){
        Habitacion ha;
        ha.id_habitacion = i;
        ha.id_tipo_habitacion = "D";
        ha.capacidad = 4;


    }



}
    