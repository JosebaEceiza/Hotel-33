#include<stdio.h>
#include<string.h>
#include"sqlite3.h"
#include"cabecera.h"

//FUNCION PARA CALCULAR LA OCUPACION DE LAS HABITACIONES
int calcularOcupacion(){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    sqlite3_stmt *stmt;
    char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL;";

    //char *sql0 = "SELECT COUNT(*) FROM RESERVA_HOTEL WHERE FECHA_PED_FIN < FECHA_INI OR FECHA_PED_INI > FECHA_FIN;";
    
    int result = sqlite3_prepare_v2(db, sql0, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

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

int realizarReserva(){

    int resultado = calcularOcupacion();
    if (resultado = 15){
        return 3;
    }

    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

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

void anularReserva(){

}

