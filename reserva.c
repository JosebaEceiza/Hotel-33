#include<stdio.h>
#include<string.h>
#include"sqlite3.h"
#include"cabecera.h"
#include<stdlib.h>

int realizarReserva(Reserva *r){

    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    sqlite3_stmt *stmt1;

    char *sql = "INSERT INTO RESERVA_HOTEL VALUES (?,?,?,?,?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt1, NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	    return 0;
	}


    //formatear fechas
    //calcular reserva hotel y id_habitacion
    char *fechaFormateadainicio = malloc(11);

    sprintf(fechaFormateadainicio, "%d-%02d-%02d", (*r).fecha_ini.anyo, (*r).fecha_ini.mes, (*r).fecha_ini.dia);
    

    char *fechaFormateadafin = malloc(11);

    sprintf(fechaFormateadafin, "%d-%02d-%02d", (*r).fecha_fin.anyo, (*r).fecha_fin.mes, (*r).fecha_fin.dia);
    //sqlite3_bind_int(stmt1, 1, (*r).id_reserva_hotel);
    sqlite3_bind_int(stmt1, 1, 3);
    sqlite3_bind_text(stmt1, 2, fechaFormateadainicio, strlen(fechaFormateadainicio), SQLITE_STATIC);
    sqlite3_bind_text(stmt1, 3, fechaFormateadafin, strlen(fechaFormateadafin), SQLITE_STATIC);
    sqlite3_bind_text(stmt1, 4, (*r).DNI, strlen((*r).DNI), SQLITE_STATIC);
    sqlite3_bind_int(stmt1, 5, (*r).numPersona);
    sqlite3_bind_int(stmt1, 6, (*r).id_habitacion);

    
    result = sqlite3_step(stmt1);
    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    sqlite3_finalize(stmt1);
    sqlite3_close(db);
    return 2;
}

void anularReserva(){

}

