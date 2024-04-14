#include<stdio.h>
#include<string.h>
#include<time.h>

#include"sqlite3.h"
#include"cabecera.h"
#include<stdlib.h>

int realizarReserva(Reserva *r){

    sqlite3* db;
    sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *sql = "SELECT ID_RESERVA_HOTEL FROM RESERVA_HOTEL ORDER BY ID_RESERVA_HOTEL DESC LIMIT 1;";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt , NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	    return 0;
	}
    result = sqlite3_step(stmt);
    int count1 = sqlite3_column_int(stmt, 0) +1;


    sqlite3_finalize(stmt);


    sqlite3_stmt *stmt1;

    char *sql1 = "INSERT INTO RESERVA_HOTEL VALUES (?,?,?,?,?,?);";
    int result1 = sqlite3_prepare_v2(db, sql1, -1, &stmt1, NULL);
    if (result1 != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	    return 0;
	}


    char *fechaFormateadainicio = malloc(11);

    sprintf(fechaFormateadainicio, "%d-%02d-%02d", (*r).fecha_ini.anyo, (*r).fecha_ini.mes, (*r).fecha_ini.dia);
    

    char *fechaFormateadafin = malloc(11);

    sprintf(fechaFormateadafin, "%d-%02d-%02d", (*r).fecha_fin.anyo, (*r).fecha_fin.mes, (*r).fecha_fin.dia);
    sqlite3_bind_int(stmt1, 1, count1);
    sqlite3_bind_text(stmt1, 2, fechaFormateadainicio, strlen(fechaFormateadainicio), SQLITE_STATIC);
    sqlite3_bind_text(stmt1, 3, fechaFormateadafin, strlen(fechaFormateadafin), SQLITE_STATIC);
    sqlite3_bind_text(stmt1, 4, (*r).DNI, strlen((*r).DNI), SQLITE_STATIC);
    sqlite3_bind_int(stmt1, 5, (*r).numPersona);
    sqlite3_bind_int(stmt1, 6, (*r).id_habitacion);

    
    result1 = sqlite3_step(stmt1);
    if (result1 != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    sqlite3_finalize(stmt1);
    sqlite3_close(db);
    return 2;
}

int anularReserva(char *c){
    char fechaFormateada[11]; // Buffer para almacenar la fecha formateada (YYYY-MM-DD)
    time_t now;
    struct tm *local;

    time(&now); // Obtiene la hora actual en segundos desde el epoch
    local = localtime(&now); // Convierte la hora actual en una estructura tm local

    // Formatea la fecha actual en formato 'YYYY-MM-DD' y la almacena en el buffer fechaFormateada
    strftime(fechaFormateada, sizeof(fechaFormateada), "%Y-%m-%d", local);


    sqlite3* db;
    sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *sql = "DELETE FROM RESERVA_HOTEL WHERE  DNI LIKE ? AND FECHA_INI > ?;";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 1;
	}
    sqlite3_bind_text(stmt,1,c,-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt,1,fechaFormateada,-1,SQLITE_STATIC);

    
    result = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

