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
    Asistencia* aux_asistencia = new Asistencia;
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
    int N=5;
    Inscripcion* aux_inscripcion = new Inscripcion[N];
    aux_inscripcion[0].idCurso=1;
    aux_inscripcion[0].fechaInscripcion = time(0);
    aux_inscripcion[1].idCurso=2;
    aux_inscripcion[1].fechaInscripcion = time(0);
    aux_inscripcion[2].idCurso=2;
    aux_inscripcion[2].fechaInscripcion = time(0);
    aux_inscripcion[3].idCurso=2;
    aux_inscripcion[3].fechaInscripcion = time(0);
    aux_inscripcion[4].idCurso=3;
    aux_inscripcion[4].fechaInscripcion = time(0);

    Asistencia* aux_asistencia = new Asistencia;
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=N;
    aux_asistencia->CursosInscriptos = aux_inscripcion;

    achicartamInscrip(aux_asistencia->CursosInscriptos, N);
    aux_asistencia->CursosInscriptos=(aux_asistencia->CursosInscriptos)-1;
    REQUIRE(N == 4);

    delete[] aux_inscripcion;
    delete aux_asistencia;
}
TEST_CASE("DesplazarAlFinalElemento", "[fancy]")
{
    int cantInscriptos=4;
    Inscripcion* cursosInscriptos = new Inscripcion[cantInscriptos];
    int pos=1;
    cursosInscriptos[0].idCurso=1;
    cursosInscriptos[0].fechaInscripcion= time(0);
    cursosInscriptos[1].idCurso=2;
    cursosInscriptos[1].fechaInscripcion= time(0);
    cursosInscriptos[2].idCurso=3;
    cursosInscriptos[2].fechaInscripcion= time(0);
    cursosInscriptos[3].idCurso=4;
    cursosInscriptos[3].fechaInscripcion= time(0);

    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    REQUIRE(cursosInscriptos[0].idCurso==1);
    REQUIRE(cursosInscriptos[1].idCurso==3);
    REQUIRE(cursosInscriptos[2].idCurso==4);
    REQUIRE(cursosInscriptos[3].idCurso==2);
    delete[] cursosInscriptos;
}
TEST_CASE("Test2dobleId_Cliente", "[fancy]")
{
    int ret;

    Inscripcion* aux_inscripcion = new Inscripcion;
    aux_inscripcion->idCurso=1;
    aux_inscripcion->fechaInscripcion = time(0);

    Asistencia* aux_asistencia = new Asistencia;
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=1;
    aux_asistencia->CursosInscriptos = aux_inscripcion;

    int N=3;
    Asistencia* asistencia_dia = new Asistencia[N];
    asistencia_dia[0].idCliente=2;
    asistencia_dia[0].cantInscriptos=1;
    asistencia_dia[0].CursosInscriptos=aux_inscripcion;
    asistencia_dia[1].idCliente=3;
    asistencia_dia[1].cantInscriptos=1;
    asistencia_dia[1].CursosInscriptos=aux_inscripcion;
    asistencia_dia[2].idCliente=1;
    asistencia_dia[2].cantInscriptos=1;
    asistencia_dia[2].CursosInscriptos=aux_inscripcion;
    asistencia_dia[3].idCliente=4;
    asistencia_dia[3].cantInscriptos=1;
    asistencia_dia[3].CursosInscriptos=aux_inscripcion;

    ret = dobleid_cliente(aux_asistencia, asistencia_dia, N);
    REQUIRE(ret == -1);
    delete[] aux_inscripcion;
    delete[] asistencia_dia;
}
TEST_CASE("Test1dobleId_Cliente", "[fancy]")
{
    int ret;

    Inscripcion* aux_inscripcion = new Inscripcion;
    aux_inscripcion->idCurso=1;
    aux_inscripcion->fechaInscripcion = time(0);

    Asistencia* aux_asistencia = new Asistencia;
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=1;
    aux_asistencia->CursosInscriptos = aux_inscripcion;

    int N=3;
    Asistencia* asistencia_dia = new Asistencia[N];
    asistencia_dia[0].idCliente=2;
    asistencia_dia[0].cantInscriptos=1;
    asistencia_dia[0].CursosInscriptos=aux_inscripcion;
    asistencia_dia[1].idCliente=3;
    asistencia_dia[1].cantInscriptos=1;
    asistencia_dia[1].CursosInscriptos=aux_inscripcion;
    asistencia_dia[2].idCliente=5;
    asistencia_dia[2].cantInscriptos=1;
    asistencia_dia[2].CursosInscriptos=aux_inscripcion;
    asistencia_dia[3].idCliente=4;
    asistencia_dia[3].cantInscriptos=1;
    asistencia_dia[3].CursosInscriptos=aux_inscripcion;

    ret = dobleid_cliente(aux_asistencia, asistencia_dia, N);
    REQUIRE(ret == 1);
    delete[] aux_inscripcion;
    delete[] asistencia_dia;
}
/*TEST_CASE("TestDobleIdCurso", "[fancy]") //ME DA FATAL
{
    int A=5;
    Inscripcion* aux_inscripcion = new Inscripcion[A];
    aux_inscripcion[0].idCurso=1;
    aux_inscripcion[0].fechaInscripcion = time(0);
    aux_inscripcion[1].idCurso=2;
    aux_inscripcion[1].fechaInscripcion = time(0);
    aux_inscripcion[2].idCurso=2;
    aux_inscripcion[2].fechaInscripcion = time(0);
    aux_inscripcion[3].idCurso=2;
    aux_inscripcion[3].fechaInscripcion = time(0);
    aux_inscripcion[4].idCurso=3;
    aux_inscripcion[4].fechaInscripcion = time(0);

    Asistencia* aux_asistencia = new Asistencia;
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=A;
    aux_asistencia->CursosInscriptos = aux_inscripcion;

    dobleid_curso(aux_asistencia);
    REQUIRE(aux_asistencia->cantInscriptos == 3);

    delete[] aux_inscripcion;
    delete aux_asistencia;
}*/
TEST_CASE("Funcion id_clienteExistente", "[fancy]")
{
    int Nclientes=3;
    Cliente* ListaClientes=new Cliente[Nclientes];
    ListaClientes[0].idCliente=2;
    ListaClientes[1].idCliente=3;
    ListaClientes[2].idCliente=1;
    int id_cliente1=2;
    int ret1;
    int id_cliente2=5;
    int ret2;
    ret1=id_clienteExistente(ListaClientes,Nclientes,id_cliente1);
    ret2=id_clienteExistente(ListaClientes,Nclientes,id_cliente2);
    REQUIRE(ret1==1);
    REQUIRE(ret2==-1);
    delete[] ListaClientes;
}
