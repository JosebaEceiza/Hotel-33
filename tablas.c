#include"sqlite3.h"
#include"cabecera.h"

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
    int x0 = sqlite3_exec(db,sql0,0,0,0);


    char *sql1 = "Create table if not exists RESERVA_HOTEL ("
                "ID_RESERVA_HOTEL integer primary key not null,"
                "FECHA_INI DATE,"
                "FECHA_FIN DATE,"
                "DNI VARCHAR,"
                "ID_HABITACION);";
    int x1 = sqlite3_exec(db,sql1,0,0,0);


    char *sql2 = "Create table if not exists HABITACION ("
                "ID_HABITACION integer primary key not null,"
                "ID_TIPO_HABITACION varchar not null);";
    int x2 = sqlite3_exec(db,sql2,0,0,0);


    char *sql3 = "Create table if not exists TIPO_HABITACION ("
                "ID_TIPO_HABITACION integer primary key not null,"
                "NOMBRE varchar not null,"
                "DESCRIPCION varchar not null);";
    int x3 = sqlite3_exec(db,sql3,0,0,0);


    char *sql4 = "Create table if not exists RESERVA_GYM ("
                "ID_RESERVA integer primary key not null,"
                "DNI varchar not null);";
    int x4 = sqlite3_exec(db,sql4,0,0,0);


    char *sql5 = "Create table if not exists RESERVA_COMEDOR ("
                "ID_RESERVA_COMEDOR varchar primary key not null,"
                "DNI varchar not null,"
                "ID_TIPO_COMIDA integer not null);";
    int x5 = sqlite3_exec(db,sql5,0,0,0);


    char *sql6 = "Create table if not exists TIPO_COMIDA ("
                "ID_TIPO_COMIDA integer primary key not null,"
                "nombre varchar not null,"
                "descripcion varchar not null);";
    int x6 = sqlite3_exec(db,sql6,0,0,0);

    char *sql7 = "Create table if not exists USUARIO ("
                "ID_USUARIO integer primary key not null,"
                "nombre varchar not null,"
                "apellido varchar not null,"
                "DNI varchar not null,"
                "contrasena varchar not null);";
    int x7 = sqlite3_exec(db,sql7,0,0,0);

    sqlite3_close(db);
}