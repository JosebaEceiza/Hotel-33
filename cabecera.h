#ifndef cabecera_h
#define cabecera_h

typedef struct{
    int dia;
    int mes;
    int anyo;
} Fecha;

typedef struct{
    char DNI[10];
    char nombre[15];
    char apellido[15];
    char telefono[10];
    char num_tarjeta[20];
    Fecha fecha_nac;
} Cliente;

typedef struct{
    char DNI[10];
    char nombre[15];
    char apellido[15];
    char contrasena[15];
} Usuario;


typedef struct{
    int id_tipo_comida;
    int precio_comida;
    char *nombre;
} Tipo_comida;

typedef struct{
    char id_tipo_habitacion;
    int precio;
} Tipo_habitacion;

typedef struct{
    int id_habitacion;
    char id_tipo_habitacion;
    int capacidad;
    char nombre[15];
    
} Habitacion;

typedef struct{
    int id_reserva_hotel;
    char DNI[10];
    int id_habitacion;
    int numPersona;
    Fecha fecha_ini;
    Fecha fecha_fin;
} Reserva;

void crearBD();

int registrarCliente(Cliente *cliente);

int comprobarCliente();

int realizarReserva();

int registrarUsuario(Usuario *u);

int loggear(Usuario *usuario);

void anularReserva();

int calcularOcupacion();

void excepcionNumeros(char *ve);

void excepcionDNI(char *str);

void excepcionNombre(char *str);

void excepcionApellido(char *str);

void excepcionContrasena(char *str);

int crearTipoHabitaciones();

void crearHabitaciones();

void mostrarHabitaciones();

int* disponibilidadHabitaciones(Fecha fechaini, Fecha fechafin);

void excepionAnyoReserva(int *anyo);

void excepionMesReserva(int *mes);

void excepcionDiaReserva(int *mes , int *dia);





#endif