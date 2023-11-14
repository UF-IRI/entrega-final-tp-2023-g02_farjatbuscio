#include <catch2/catch.hpp>
#include "funciones.cpp"
#include "archivos.cpp"
#include <ctime>

TEST_CASE("AgrandarTamTEST", "[fancy]")
{
    int N=5;
    Inscripcion* CursosInscriptosaux = new Inscripcion[N];
    CursosInscriptosaux[0].idCurso=0;
    CursosInscriptosaux[0].fechaInscripcion=time(0);
    CursosInscriptosaux[1].idCurso=0;
    CursosInscriptosaux[1].fechaInscripcion=time(0);
    CursosInscriptosaux[2].idCurso=0;
    CursosInscriptosaux[2].fechaInscripcion=time(0);
    CursosInscriptosaux[3].idCurso=0;
    CursosInscriptosaux[3].fechaInscripcion=time(0);
    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=4;
    aux_asistencia->CursosInscriptos=CursosInscriptosaux;

    agrandartamInscrip(aux_asistencia->CursosInscriptos, N);
    REQUIRE(N == 6);

    delete[] CursosInscriptosaux;
    delete[] aux_asistencia;
}
TEST_CASE("AchicarTamTEST", "[fancy]")
{
    int N=4;
    Inscripcion* CursosInscriptosaux = new Inscripcion[N];
    CursosInscriptosaux[0].idCurso=1;
    CursosInscriptosaux[0].fechaInscripcion=time(0);
    CursosInscriptosaux[1].idCurso=2;
    CursosInscriptosaux[1].fechaInscripcion=time(0);
    CursosInscriptosaux[2].idCurso=3;
    CursosInscriptosaux[2].fechaInscripcion=time(0);
    CursosInscriptosaux[3].idCurso=4;
    CursosInscriptosaux[3].fechaInscripcion=time(0);
    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=4;
    aux_asistencia->CursosInscriptos=CursosInscriptosaux;

    achicartamInscrip(aux_asistencia->CursosInscriptos, N);
    REQUIRE(N == 3);

    delete[] CursosInscriptosaux;
    delete[] aux_asistencia;
}
/*TEST_CASE("DesplazarAlFinalElemento", "[fancy]")
{
    int cantInscriptos=4;
    Inscripcion *cursosInscriptos = new Inscripcion[cantInscriptos];
    int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    REQUIRE(cursosInscriptos[0].idCurso==1);
    REQUIRE(cursosInscriptos[1].idCurso==3);
    REQUIRE(cursosInscriptos[2].idCurso==4);
    REQUIRE(cursosInscriptos[3].idCurso==2);
    delete[] cursosInscriptos;
}*/
/*TEST_CASE("NOdobleId_Cliente", "[fancy]")
{
    int N=3;
    int M=1;
    Asistencia* asistencia_dia = new Asistencia[N];
    for (int i = 0; i < N; ++i)
    {
        asistencia_dia[i].CursosInscriptos = new Inscripcion[M]; // Asignar memoria para CursosInscriptos
    }
    asistencia_dia[0].idCliente=1;
    asistencia_dia[0].cantInscriptos=1;
    asistencia_dia[0].CursosInscriptos[0].idCurso=1;
    asistencia_dia[0].CursosInscriptos[0].fechaInscripcion=time(0);
    asistencia_dia[1].idCliente=2;
    asistencia_dia[1].cantInscriptos=1;
    asistencia_dia[1].CursosInscriptos[0].idCurso=2;
    asistencia_dia[1].CursosInscriptos[0].fechaInscripcion=time(0);
    asistencia_dia[2].idCliente=3;
    asistencia_dia[2].cantInscriptos=1;
    asistencia_dia[2].CursosInscriptos[0].idCurso=3;
    asistencia_dia[2].CursosInscriptos[0].fechaInscripcion=time(0);

    Asistencia aux_asistencia;
    aux_asistencia.idCliente=2;
    aux_asistencia.cantInscriptos=1;
    aux_asistencia.CursosInscriptos->idCurso=2;
    aux_asistencia.CursosInscriptos->fechaInscripcion=time(0);

    int ret=0;
    ret=dobleid_cliente(aux_asistencia,asistencia_dia,N);

    REQUIRE(ret==-1);
    //libero memoria:
    for (int i = 0; i < N; ++i)
    {
        delete[] asistencia_dia[i].CursosInscriptos; // Liberar memoria para cada CursosInscriptos
    }
    delete[] asistencia_dia;
}*/
TEST_CASE("NODobleIdCurso", "[fancy]")
{
    int N=4;
    Inscripcion CursosInscriptosaux = new Inscripcion[N];
    CursosInscriptosaux[0].idCurso=2020;
    CursosInscriptosaux[0].fechaInscripcion=time(0);
    CursosInscriptosaux[1].idCurso=2020;
    CursosInscriptosaux[1].fechaInscripcion=time(0);
    CursosInscriptosaux[2].idCurso=2040;
    CursosInscriptosaux[2].fechaInscripcion=time(0);
    CursosInscriptosaux[3].idCurso=2050;
    CursosInscriptosaux[3].fechaInscripcion=time(0);

    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=4;
    aux_asistencia->CursosInscriptos=CursosInscriptosaux;

    dobleid_curso(*aux_asistencia);
    REQUIRE(aux_asistencia->cantInscriptos==3);
    REQUIRE(aux_asistencia->CursosInscriptos[0].idCurso==2020);
    REQUIRE(aux_asistencia->CursosInscriptos[1].idCurso==2040);
    REQUIRE(aux_asistencia->CursosInscriptos[2].idCurso==2050);

    delete[] CursosInscriptosaux;
    delete[] aux_asistencia;
}
TEST_CASE("funcion fechas", "fancy")
{
    //deberia retornar un int dependiendo de cual fecha sea primera
    time_t time1 = time(0); //primera
    time_t time2 = time(0)-1; //segunda
    time_t timerepitente = time(0);
    int ret1;
    ret1 = fechas(time1, time2);
    REQUIRE(ret1 == 1);
    int ret2;
    ret2 = fechas(time1, timerepitente);
    REQUIRE(ret2 == 3);
}
/*TEST_CASE("horarioClase", "fancy")
{
    //retorna el horario de la clases de la cual le pases el id_curso
    float ret;
    int aux_idclase=2;
    int N=2;
    Clases* ListaClases = new Clases [N];
    ListaClases[0].Horario=9.5;
    ListaClases[0].idClase=1;
    ListaClases[0].NombreClase="Yoga";
    ListaClases[1].Horario=5.5;
    ListaClases[1].idClase=2;
    ListaClases[1].NombreClase="Yoga";
    ListaClases[2].Horario=10.0;
    ListaClases[2].idClase=3;
    ListaClases[2].NombreClase="Yoga";

    ret = horario_clase(aux_idclase, ListaClases,N);
    REQUIRE(ret == 5.5);
    delete ListaClases;
}*/
/*TEST_CASE("NODobleHorario", "fancy")
{
    int NcantClases = 3;
    Asistencia* aux_asistencia = new Asistencia[];
    Inscripcion aux_asistencia->CursosInscriptos = new Inscripcion[NcantClases];
    aux_asistencia->idCliente=1;
    aux_asistencia->CursosInscriptos=NcantClases;
    aux_asistencia->CursosInscriptos[0].idCurso=1;
    aux_asistencia->CursosInscriptos[0].fechaInscripcion = time(0);
    aux_asistencia->CursosInscriptos[1].idCurso=2;
    aux_asistencia->CursosInscriptos[1].fechaInscripcion = time(0);
    aux_asistencia->CursosInscriptos[2].idCurso=3;
    aux_asistencia->CursosInscriptos[2].fechaInscripcion = (time(0))+1;
    aux_asistencia->CursosInscriptos[3].idCurso=2;
    aux_asistencia->CursosInscriptos[3].fechaInscripcion = (time(0))+1;

    Clases* ListaClases = new Clases[5];
    ListaClases[0].idClase=1;
    ListaClases[0].Horario=7;
    ListaClases[0].NombreClase= "Yoga";
    ListaClases[1].idClase=2;
    ListaClases[1].Horario=5;
    ListaClases[1].NombreClase= "Yoga";
    ListaClases[2].idClase=3;
    ListaClases[2].Horario=7;
    ListaClases[2].NombreClase= "Yoga";
    ListaClases[3].idClase=4;
    ListaClases[3].Horario=8;
    ListaClases[3].NombreClase= "Yoga";
    ListaClases[4].idClase=5;
    ListaClases[4].Horario=9;
    ListaClases[4].NombreClase= "Yoga";
    ListaClases[5].idClase=6;
    ListaClases[5].Horario=1;
    ListaClases[5].NombreClase= "Yoga";

TERMINAR!!

    //Clases ListaClases
}*/
TEST_CASE("id_clienteExistente", "fancy")
{
    //pili
}
TEST_CASE("cuotapaga", "fancy")
{
    //pili
}
TEST_CASE("dobleid_cursoListaMan", "fancy")
{
    //pili
}
TEST_CASE("doblehorario_ListaMan", "fancy")
{
    //pili
}
TEST_CASE("funcion_cupo", "fancy")
{
    //more
}
TEST_CASE("inscripMan", "fancy")
{
    //pili
}
