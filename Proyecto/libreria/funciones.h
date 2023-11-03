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
    unsigned int idCliente;
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
    time_t Horario;
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

/************** DECLARO FUNCIONES **************/
//funcion agrandar vector (resize)
void agrandartam(str*& vector, int* N);
//funcion achicar vector (resize)
void achicartam(str*& vector, int* N);
//funcion desplazar un elemento al final para desp eliminarla con el resize
void moveralfinal(Inscripcion* cursosInscriptos, unsigned int CantInscriptos, unsigned int pos);

#endif // FUNCIONES_H
