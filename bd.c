#include<stdio.h>

#include"sqlite3.h"




void crearBD(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    char *sql = "Create table if not exists Clientes ("
                "DNI varchar primary key not null,"
                "nombre varchar not null,"
                "apellido varchar not null,"
                "telefono integer not null,"
                "num_tarjeta integer not null,"
                "fecha_nac date not null);";
    int x = sqlite3_exec(db,sql,0,0,0);

    sqlite3_close(db);


}