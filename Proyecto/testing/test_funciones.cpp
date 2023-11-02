#include <catch2/catch.hpp>
#include "funciones.h"

TEST_CASE("Prueba de funcion id cliente", "[fancy]")
{
    //void Doble_IdCLiente(Asistencia* Asistencia_dia);
    //creo un array dinamico de asistenica_dia
    unsigned int N=5;
    Asistencia *Asistencia_dia= new Asistencia[N];
    //instante actual time_t tSac = time(NULL);
    time_t tActual=time(NULL);
    //cargo los datos de diferentes clientes, se repiten dos clientes:
    Asistencia_dia[0]={1,2,{2,tActual}};
    Asistencia_dia[1]={2,2,{2,tActual}};
    Asistencia_dia[2]={1,0,{2,tActual}};
    Asistencia_dia[3]={4,2,{2,tActual}};
    Asistencia_dia[4]={2,2,{2,tActual}};
    Doble_IdCLiente(Asistencia_dia,5);
    Asistencia ClienteNulo;
    ClienteNulo.idCliente=0;
    ClienteNulo.cantInscriptos=0;
    ClienteNulo.CursosInscriptos->idCurso=0;
    ClienteNulo.CursosInscriptos->fechaInscripcion=0;

    REQUIRE(Asistencia_dia[2].idCliente==ClienteNulo.idCliente && Asistencia_dia[4].idCliente==ClienteNulo.idCliente);
}
