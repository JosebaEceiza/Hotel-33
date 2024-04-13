#include<stdio.h>
#include<string.h>
#include"sqlite3.h"
#include"cabecera.h"
#include<stdlib.h>

//FUNCION PARA CALCULAR LA OCUPACION DE LAS HABITACIONES
int calcularOcupacion(Fecha fecha_ped_ini, Fecha fecha_ped_fin){

    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    sqlite3_stmt *stmt;
    //char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL;";
    //char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL WHERE FECHA_PED_FIN(?) < FECHA_INI OR FECHA_PED_INI(?) > FECHA_FIN;";

    char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL WHERE (? < FECHA_INI) OR (? > FECHA_FIN);";
    
    int result = sqlite3_prepare_v2(db, sql0, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

    char *fechaFormateadaInicio = malloc(11);
    sprintf(fechaFormateadaInicio, "%d-%02d-%02d", fecha_ped_ini.anyo, fecha_ped_ini.mes, fecha_ped_ini.dia);

    char *fechaFormateadaFin = malloc(11);
    sprintf(fechaFormateadaFin, "%d-%02d-%02d", fecha_ped_fin.anyo, fecha_ped_fin.mes, fecha_ped_fin.dia);

    sqlite3_bind_text(stmt, 1, fechaFormateadaFin, -1,  SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, fechaFormateadaInicio, -1, SQLITE_STATIC);


    result = sqlite3_step(stmt);
    int count = sqlite3_column_int(stmt, 0);

    printf("\nEl resultado es: %i\n", count);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return count;

    //FECHA_FIN
    //FECHA_INI
    //FECHA_PED_INI
    //FECHA_PED_FIN

    //FECHA_PED_FIN < FECHA_INI
    //FECHA_PED_INI > FECHA_FIN

}

int realizarReserva(Reserva *r){
    

    int resultado = calcularOcupacion((*r).fecha_ini, (*r).fecha_fin);
    if (resultado == 15){
        return 3;
    }

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
    sqlite3_bind_int(stmt1, 1, 2);
    sqlite3_bind_text(stmt1, 2, fechaFormateadainicio, strlen(fechaFormateadainicio), SQLITE_STATIC);
    sqlite3_bind_text(stmt1, 3, fechaFormateadafin, strlen(fechaFormateadafin), SQLITE_STATIC);
    sqlite3_bind_text(stmt1, 4, (*r).DNI, strlen((*r).DNI), SQLITE_STATIC);
    sqlite3_bind_int(stmt1, 5, (*r).numPersona);
    //sqlite3_bind_int(stmt1, 6, (*r).id_habitacion);
    sqlite3_bind_int(stmt1, 6, 5);

    
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

