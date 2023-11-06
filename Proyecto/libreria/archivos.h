#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include "funciones.h"

typedef enum { ErrArchivo = -1,  ExitoArchivo = 1 } eArchivo;
/****funcion que lee el archivo de clases y retorna -1 si no se pudo leer y 1 si se pudo leer,
y la lista de clases quedaria cargada:******/
eArchivo LeerClases(ifstream& archivoClases, Clases*& ListaClases,int &Nclases);
eArchivo LeerClientes(ifstream& archivoClientes, Cliente*& ListaClientes,int &Nclientes);
eArchivo LeerAsistencia(ifstream& archivo_dia, Asistencia*& AsistenciaDia,int &Ninscripciones);

#endif // ARCHIVOS_H
