#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include <sstream>
#include <string>
#include "funciones.h"

typedef enum { ErrArchivo = -1,  ExitoArchivo = 1 } eArchivo;

//Funcion que lee archivo de clases, retorna -1 si no se pudo abrir y 1 si se pudo abrir
eArchivo LeerClases(ifstream& archivoClases, Clases*& ListaClases,int &Nclases);

//Funcion que lee archivo de clientes retorna -1 si no se pudo abrir y 1 si se pudo abrir
eArchivo LeerClientes(ifstream& archivoClientes, Cliente*& ListaClientes,int &Nclientes);

//Funcion que lee el archivo de asistencia del dia de hoy, solo carga los que cumplen la condicion
eArchivo LeerAsistencia_hoy(ifstream& archivo_dia, Asistencia*& AsistenciaDia,int &Ninscripciones);

//Funcion que crea el archivo para mañana
eArchivo CrearAsistencia_manana(string& Nombre_Archivo,Asistencia*& AsistenciaMan,int &Ninscripciones);


//Funcion que me genere datos de clientes random:
void RandCliente(Cliente*& ListaClientes,int& Nclases,int& Nclientes, Clases*& ListaClase, Asistencia*& aux);
#endif // ARCHIVOS_H


