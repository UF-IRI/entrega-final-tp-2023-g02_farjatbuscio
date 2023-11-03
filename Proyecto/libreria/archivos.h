#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "funciones.h"
using namespace std;
typedef std::string str;

enum eArchivo  { ErrArchivo = -1,  ExitoArchivo = 1 };
/****funcion que lee el archivo de clases y retorna -1 si no se pudo leer y 1 si se pudo leer,
y la lista de clases quedaria cargada:******/
eArchivo LeerClases(ifstream* archivoClases, Clases* ListaClases,int &Nclases);

#endif // ARCHIVOS_H
