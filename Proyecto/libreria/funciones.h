#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <sstream>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

typedef std::string str;

/************Declaracion de structs:**********/

//estructura de cliente:
typedef struct {
    int idCliente;
    str Nombre;
    str Apellido;
    str Mail;
    str Telefono;
    time_t fechaNacimiento;
    int estado;
} Cliente;

//estructura de clases:
typedef struct {
    unsigned int idClase;
    str NombreClase;
    float Horario;
} Clases;

//estructura de asistencia y inscripcion:
typedef struct {
    unsigned int idCurso;
    time_t fechaInscripcion;
} Inscripcion;
typedef struct {
    unsigned int idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

//estructura de cupos
typedef struct {
    unsigned int Nclases;
    unsigned int IdClase;
    unsigned int cupo;
} CupoClases;

/**************Enum para errores:**************/
typedef enum {ErrDobleIdCliente = -1, ExitoIdCLiente=1} eDobleId_Cliente;


/************** DECLARO FUNCIONES **************/
//funcion agrandar Clases (resize)
void agrandartamClases(Clases*& vector, int& N);
//funcion agrandar Cliente (resize)
void agrandartamCliente(Cliente*& vector, int& N);
//funcion agrandar Inscripcion (resize)
void agrandartamInscrip(Inscripcion*& vector, int& N);
//funcion achicar Inscripcion (resize)
void achicartamInscrip(Inscripcion*& vector, int& N);
//funcion desplazar un elemento al final para desp eliminarla con el resize
void moveralfinal(Inscripcion* cursosInscriptos, unsigned int CantInscriptos, unsigned int pos);
//Chequea que el cliente del archivo Asitencia_dia que voy a leer, no esté ya anotado en Asistencia_dia
int dobleid_cliente(Asistencia aux_asistencia, Asistencia* Asistencia_dia, unsigned int N);


#endif // FUNCIONES_H
