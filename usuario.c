#include<stdio.h>
#include"sqlite3.h"
#include"cabecera.h"
#include<string.h>


int registrarUsuario(Usuario *u){
    sqlite3* db;
    sqlite3_open("base_datos.db", &db);

    sqlite3_stmt *stmt;


    char *sql = "INSERT INTO USUARIO VALUES (?,?,?,?,?);";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
		printf("Error en la preparación del statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	    return result;
	}


    char *nombre = (*u).nombre;
    char *apellido = (*u).apellido;
    char *DNI = (*u).DNI;
    char *contrasena = (*u).contrasena;
    

    sqlite3_bind_int(stmt, 1, 1);
    sqlite3_bind_text(stmt, 2, nombre, strlen(nombre), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, apellido, strlen(apellido), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, DNI, strlen(DNI), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, contrasena, strlen(contrasena), SQLITE_STATIC);


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
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

    sqlite3_bind_text(stmt, 1, (*usuario).DNI, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, (*usuario).contrasena, -1, SQLITE_STATIC);
    
    result = sqlite3_step(stmt);

    printf("\n%s",result);
    printf("\n%i\n",SQLITE_ROW);

    int count = sqlite3_column_int(stmt, 0);
    const char *count1 = sqlite3_column_text(stmt, 1);

    const char *count2 = sqlite3_column_text(stmt, 2);

    const char *count3 = sqlite3_column_text(stmt, 3);

    const char *count4 = sqlite3_column_text(stmt, 4);

    printf("%s",count1);
    printf("%s",count2);

    printf("%s",count3);
    printf("%s",count4);



    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return result;
}