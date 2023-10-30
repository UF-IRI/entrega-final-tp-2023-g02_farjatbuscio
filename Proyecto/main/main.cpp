#include <fstream>
#include <iostream>

#include "archivos.h"
#include "funciones.h"

using namespace std;

int main() {
    

    /**** 1er parte: Chequeo clases del dia de hoy: ****/
    //abro el archivo binario:
    ifstream archivoClasesHoy("asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) { //si no puede arbrirlo:
        cout << "Error opening binary file" << endl;
    }
    //sino llamo a la funcion para leerlo:
    else
    {
        int N=1;
        Asistencia Asistencia_dia=new Asistencia[N];
        Funcion_AsistenciaDia(&archivoClasesHoy, &Asistencia_dia, &ListaClase);

    }
    return 0;
}
