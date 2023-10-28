#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <ctime>
#include <string>

/***********Declaracion de structs:**********/

//estructura de cliente:
struct cliente {
    unsigned int idCliente;
    string Nombre;
    string Apellido;
    string Mail;
    string Telefono;
    time_t fechaNacimiento;
    int estado;
}
typedef Cliente;

//estructura de clases:
struct clases{
    unsigned int idClase;
    string NombreClase;
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

/***********Declaracion de funciones:**********/
void resize (string*& vector, int* N);



#endif // FUNCIONES_H
