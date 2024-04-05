#include"cabecera.h"
#include"sqlite3.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int registrarCliente(Cliente *cliente){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    //INSERT USUARIO
    sqlite3_stmt *stmt;

    char *sql = "INSERT INTO CLIENTE VALUES (?,?,?,?,?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

    char *nombre = (*cliente).nombre;
    char *apellido = (*cliente).apellido;
    char *DNI = (*cliente).DNI;
    char *telefono = (*cliente).telefono;
    char *num_tarjeta = (*cliente).num_tarjeta;
    int anyo = (*cliente).fecha_nac.anyo;
    int mes = (*cliente).fecha_nac.mes;
    int dia = (*cliente).fecha_nac.dia;
    char *fechaFormateada = malloc(11);

    sprintf(fechaFormateada, "%d-%02d-%02d", anyo, mes, dia);
    
    sqlite3_bind_text(stmt, 1, DNI, strlen(DNI), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, nombre, strlen(nombre), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, apellido, strlen(apellido), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, telefono, strlen(telefono), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, num_tarjeta, strlen(num_tarjeta), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, fechaFormateada, -1, SQLITE_STATIC);


    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return result;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;

}
