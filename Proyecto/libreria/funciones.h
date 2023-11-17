#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <sstream>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

typedef std::string str;

//Declaracion de structs:

//estructura de cliente:
typedef struct {
    int idCliente;
    str Nombre;
    str Apellido;
    str Mail;
    str Telefono;
    float fechaNacimiento;
    int estado;
} Cliente;

//estructura de clases:
typedef struct {
    int idClase;
    string NombreClase;
    float Horario;
} Clases;

//estructura de asistencia y inscripcion:
typedef struct {
    int idCurso;
    time_t fechaInscripcion;
} Inscripcion;
typedef struct {
    int idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

//estructura de cupos
typedef struct {
    string NombreClase;
    int Ncupo;
} CupoClases;

//Enum para errores:
typedef enum { ErrCliente = -1,  ErrCouta = -2, ErrRandom = -3, ErrNingunaClase = -4, ExitoInscrip = 1} eInscripManFinal;


//DECLARO FUNCIONES
void agrandartamClases(Clases*& vector, int& N);
void agrandartamCliente(Cliente*& vector, int& N);
void agrandartamInscrip(Inscripcion*& vector, int& N);
void agrandartamAsistencia(Asistencia*& vector, int& N);
void achicartamInscrip(Inscripcion*& vector, int& N);
void moveralfinal(Inscripcion*& cursosInscriptos, int CantInscriptos, int pos);
int dobleid_cliente(Asistencia*& aux_asistencia, Asistencia*& Asistencia_dia, int N);
void dobleid_curso(Asistencia*& aux_asistencia);
int fechas(time_t fecha1, time_t fecha2);
float horario_clase (int aux_idClase, Clases*& ListaClases, int NcantClases);
void doblehorario(Asistencia*& aux_asistencia, Clases*& ListaClases, int NcantClases);
int id_clienteExistente(Cliente*& ListaClientes, int Nclientes, int id_cliente);
int cuotapaga(Cliente*& ListaClientes, int Nclientes, int id_cliente);
void dobleid_cursoListaMan(Asistencia*& AsistenciaMan, int Ninscriptos, Asistencia*& aux_asistencia);
void doblehorario_ListaMan(Asistencia*& aux_asistencia, Clases*& ListaClases, int NcantClases, Asistencia*& AsistenciaMan, int Ninscriptos);
void funcion_cupo(Asistencia*& aux_asistencia, Asistencia*& AsistenciaMan,int Ninscriptos, Clases* ListaClases,int Nclases, CupoClases*& ListaCupo, int Ncupos);
eInscripManFinal inscripMan(Asistencia*& aux_asistencia, Asistencia*& AsistenciaMan, int Ninscriptos, Clases*& ListaClases,int Nclases, Cliente*& ListaClientes, int Nclientes, CupoClases*& ListaCupo, int Ncupos);

#endif // FUNCIONES_H
