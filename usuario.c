#include<stdio.h>
#include"sqlite3.h"
#include"cabecera.h"
#include<string.h>


int registrarUsuario(Usuario *u){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    //INSERT USUARIO
    sqlite3_stmt *stmt;

    char *sql = "INSERT INTO USUARIO VALUES (?,?,?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}


    char *nombre = (*u).nombre;
    char *apellido = (*u).apellido;
    char *DNI = (*u).DNI;
    char *contrasena = (*u).contrasena;

    sqlite3_bind_text(stmt, 1, DNI, strlen(DNI), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, nombre, strlen(nombre), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, apellido, strlen(apellido), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, contrasena, strlen(contrasena), SQLITE_STATIC);


    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al ejecutar el statement: %s\n", sqlite3_errmsg(db));
        return result;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}


int loggear(Usuario *usuario){

    sqlite3* db;
    sqlite3_open("base_datos.db", &db);
    sqlite3_stmt *stmt;

    char *sql = "SELECT * FROM USUARIO WHERE contrasena LIKE ? AND DNI LIKE ?;";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 1;
	}

	printf("SQL query prepared (SELECT)\n"); // para el logger

    sqlite3_bind_text(stmt, 1, (*usuario).contrasena, -1,  SQLITE_STATIC);

    sqlite3_bind_text(stmt, 2, (*usuario).DNI, -1, SQLITE_STATIC);

    const char *count1 = NULL;
    const char *count2 = NULL;
    const char *count3 = NULL;
    const char *count4 = NULL;
    int numFilas = 0;
    int singleRow = 0;
    int acceder = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {

        numFilas++;
        if (numFilas > 1) {
            singleRow = -1; // Indicador de múltiples filas
            return 1;
        }

        count1 = (char *)sqlite3_column_text(stmt, 0);
        count2 = (char *)sqlite3_column_text(stmt, 1);
        count3 = (char *)sqlite3_column_text(stmt, 2);
        count4 = (char *)sqlite3_column_text(stmt, 3);
        
        if (strcmp((*usuario).contrasena, count4) == 0 && strcmp((*usuario).DNI, count1) == 0) {
            acceder = 1;
            strcpy((*usuario).nombre,(char*)count1);
            strcpy((*usuario).apellido,(char*)count2);        
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    if(singleRow == 0 && acceder == 1){
        printf("Se ha accedido con exito");
        return 0;
    }
    else{
        return 1;
    }
}