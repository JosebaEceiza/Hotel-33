#include<stdio.h>
#include<string.h>
#include"sqlite3.h"

//FUNCION PARA CALCULAR LA OCUPACION DE LAS HABITACIONES
int calcularOcupacion(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    sqlite3_stmt *stmt;
    char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL;";

    //char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL WHERE FECHA_PED_FIN < FECHA_INI OR FECHA_PED_INI > FECHA_FIN;";
    
    int result = sqlite3_prepare_v2(db, sql0, -1, &stmt, NULL);

    result = sqlite3_step(stmt);
    int count = sqlite3_column_int(stmt, 0);

    printf("\nEl resultado es: %i\n", count);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return result;

    //FECHA_FIN
    //FECHA_INI
    //FECHA_PED_INI
    //FECHA_PED_FIN

    //FECHA_PED_FIN < FECHA_INI
    //FECHA_PED_INI > FECHA_FIN

}


void crearBD(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    char *sql0 = "Create table if not exists CLIENTE ("
                "DNI varchar primary key not null,"
                "NOMBRE varchar not null,"
                "APELLIDO varchar not null,"
                "TELEFONO integer not null,"
                "NUM_TARJETA integer not null,"
                "FECHA_NAC date not null);";
    int x1 = sqlite3_exec(db,sql0,0,0,0);


    char *sql1 = "Create table if not exists RESERVA_HOTEL ("
                "ID_RESERVA_HOTEL integer primary key not null,"
                "FECHA_INI DATE,"
                "FECHA_FIN DATE,"
                "DNI VARCHAR,"
                "ID_HABITACION);";
    int x2 = sqlite3_exec(db,sql1,0,0,0);


    char *sql2 = "Create table if not exists HABITACION ("
                "ID_HABITACION integer primary key not null,"
                "ID_TIPO_HABITACION varchar not null);";
    int x3 = sqlite3_exec(db,sql2,0,0,0);


    char *sql3 = "Create table if not exists TIPO_HABITACION ("
                "ID_TIPO_HABITACION integer primary key not null,"
                "NOMBRE varchar not null,"
                "DESCRIPCION varchar not null);";
    int x4 = sqlite3_exec(db,sql3,0,0,0);


    char *sql4 = "Create table if not exists RESERVA_GYM ("
                "ID_RESERVA integer primary key not null,"
                "DNI varchar not null);";
    int x5 = sqlite3_exec(db,sql4,0,0,0);


    char *sql5 = "Create table if not exists RESERVA_COMEDOR ("
                "ID_RESERVA_COMEDOR varchar primary key not null,"
                "DNI varchar not null,"
                "ID_TIPO_COMIDA integer not null);";
    int x6 = sqlite3_exec(db,sql5,0,0,0);


    char *sql6 = "Create table if not exists TIPO_COMIDA ("
                "ID_TIPO_COMIDA integer primary key not null,"
                "nombre varchar not null,"
                "descripcion varchar not null);";
    int x7 = sqlite3_exec(db,sql6,0,0,0);


    sqlite3_close(db);


}

int realizarReserva(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    int resultado = calcularOcupacion();
    if (resultado = 15){
        return 3;
    }
    sqlite3_stmt *stmt1;

    char *sql = "INSERT INTO RESERVA_HOTEL VALUES (?,?,?,?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt1, NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	    return 0;
	}


    int ID_RESERVA_HOTEL = 3;
    char *DNI = "acba";
    int ID_HABITACION = 3;

    sqlite3_bind_int(stmt1, 1, ID_RESERVA_HOTEL);
    sqlite3_bind_text(stmt1, 2, DNI, strlen(DNI), SQLITE_STATIC);
    sqlite3_bind_int(stmt1, 3, ID_HABITACION);

    result = sqlite3_step(stmt1);
    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    sqlite3_finalize(stmt1);
    sqlite3_close(db);
    return 2;
}


