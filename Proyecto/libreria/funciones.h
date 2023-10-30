#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <ctime>
#include <string>

/************Declaracion de structs:**********/

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

/************Enum para errores:**********/
enum eId_Cliente{ ErrIdCliente = -1, ExitoIdCLiente=1};
enum eId_Curso{ErrIdCurso = -1, ExitoIdCurso=1};
enum eHorario{ErrDobleHorario = -1, ExitoDobleHorario=1};

/***********Declaracion de funciones:**********/
void resize (string*& vector, int* N); //more
//condiciones para chequear struct Asistencia_dia
eId_Cliente Doble_IdCLiente(Asistencia* Asistencia_dia);
eId_Curso Doble_IdCurso(Asistencia* Asistencia_dia);
time_t Horario_clase (unsigned int aux_idClase, Clases* ListaClases); //extra para Doble_Horario
eHorario Doble_Horario(Asistencia* Asistencia_dia, Clases* ListaClases);


#endif // FUNCIONES_H
