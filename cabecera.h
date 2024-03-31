#ifndef cabecera_h
#define cabecera_h

typedef struct{
    int dia;
    int mes;
    int anyo;
} Fecha;


typedef struct{
    char *DNI;
    char *nombre;
    char apellido;
    int telefono;
    int num_tarjeta
    Fecha fecha_nac;
} Cliente;

typedef struct{
    int id_tipo_comida;
    char *nombre;
    char *descripcion;
} Tipo_comida;

typedef struct{
    int id_tipo_habitacion;
    char *nombre;
    char *descripcion;
} Tipo_jabitacion;

typedef struct{
    int id_habitacion;
    int id_tipo_habitacion;
} Habitacion;

typedef struct{
    int id_reserva_hotel;
    char *DNI;
    int id_habitacion;
}

void crearBD();


#endif