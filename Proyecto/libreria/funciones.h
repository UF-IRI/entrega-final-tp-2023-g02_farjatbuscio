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
    str NombreClase;
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
typedef enum {ErrDobleIdCliente = -1, ExitoIdCLiente=1} eDobleId_Cliente;


//DECLARO FUNCIONES
//funcion agrandar Clases (resize)
void agrandartamClases(Clases*& vector, int& N);
//funcion agrandar Cliente (resize)
void agrandartamCliente(Cliente*& vector, int& N);
//funcion agrandar Inscripcion (resize)
void agrandartamInscrip(Inscripcion*& vector, int& N);
//funcion agrandar Asistencia (resize)
void agrandartamAsistencia(Asistencia*& vector, int& N);
//funcion achicar Inscripcion (resize)
void achicartamInscrip(Inscripcion*& vector, int& N);
//funcion desplazar un elemento al final para desp eliminarla con el resize
void moveralfinal(Inscripcion*& cursosInscriptos, int CantInscriptos, int pos);
//Chequea que el cliente del archivo Asitencia_dia que voy a leer, no este ya anotado en Asistencia_dia
int dobleid_cliente(Asistencia aux_asistencia, Asistencia*& Asistencia_dia, int N);
//Chequea que no se repita el mismo id_curso por cliente, no este anotado dos veces en la misma clase
void dobleid_curso(Asistencia*& aux_asistencia);
//le paso dos fechas y dependiendo cual es mas reciente, retorna un num distinto
int fechas(time_t fecha1, time_t fecha2);
//Retorna el horario de la clase que le pases el id_curso
float horario_clase (int aux_idClase, Clases ListaClases, int NcantClases);
//Chequea que no se repita el mismo horario por cliente
void doblehorario(Asistencia*& aux_asistencia, Clases ListaClases, int NcantClases);

//Funcion que cheque el cupo de la clase con su ID:
int funcion_cupo(Asistencia*& AsistenciaMan,int Ninscriptos, Clases* ListaClases,int Nclases, int id_clase, CupoClases* &ListaCupo, int Ncupos);
#endif // FUNCIONES_H
