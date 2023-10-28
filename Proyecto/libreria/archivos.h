#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <sstream>
#include <iostream>
#include "funciones.h"

//enum para errores y exitos:
enum eArchivoDia{ExitoArchivo=1;ErrArchivo=-1};

/*Funcion que chequea el archivo del dia de Asistencias,
 *  si cumple con las condiciones, cargo la lista de hoy*/

eArchivoDia Funcion_AsistenciaDia(ifstream *archivo_dia, Asistencia *Asistencia_dia);
/*eCodArchivos leerArchivoAgenda(std::fstream	*archi, sAgenda *agenda){
    // Comprueba que el archivo se pudo abrir.
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    // Lee la estructura de la agenda completa.
    archi->read((char*)agenda, sizeof(sAgenda));

    if(!*archi){
        return eCodArchivos::ErrorEscritura;
    }

    return eCodArchivos::ExitoOperacion;
}*/
#endif // ARCHIVOS_H
