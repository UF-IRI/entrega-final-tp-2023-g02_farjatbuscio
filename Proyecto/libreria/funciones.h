#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
typedef std::string str;

/************Declaracion de structs:**********/

//estructura de cliente:
struct cliente {
    int idCliente;
    str Nombre;
    str Apellido;
    str Mail;
    str Telefono;
    time_t fechaNacimiento;
    int estado;
}
typedef Cliente;

//estructura de clases:
struct clases{
    unsigned int idClase;
    str NombreClase;
    float Horario;
}
typedef Clases;

//estructura de asistencia y inscripcion:
struct inscripcion {
    unsigned int idCurso;
    time_t fechaInscripcion;
}
typedef Inscripcion;
struct asistencia {
    unsigned int idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
}
typedef Asistencia;

//estructura de cupos
struct cupoclases {
    unsigned int Nclases;
    unsigned int IdClase;
    unsigned int cupo;
}
typedef CupoClases;

/**************Enum para errores:**************/
enum eDobleId_Cliente{ErrDobleIdCliente = -1, ExitoIdCLiente=1};


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
int dobleid_cliente(Asistencia* aux_asistencia, Asistencia* Asistencia_dia, unsigned N);


#endif // FUNCIONES_H
