#include <catch2/catch.hpp>
#include "funciones.cpp"
#include "archivos.cpp"
#include <ctime>

TEST_CASE("AgrandarTamTEST", "[fancy]")
{
    int N=5;
    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=4;
    aux_asistencia->CursosInscriptos = new Inscripcion[N]; // Asignar memoria para CursosInscriptos
    aux_asistencia->CursosInscriptos[0]={1, time(0)};
    aux_asistencia->CursosInscriptos[1]={2, time(0)};
    aux_asistencia->CursosInscriptos[2]={3, time(0)};
    aux_asistencia->CursosInscriptos[3]={4, time(0)};
    agrandartamInscrip(aux_asistencia->CursosInscriptos, N);
    REQUIRE(N == 6);
    cout<<"N es: " << N <<endl;
    delete[] aux_asistencia->CursosInscriptos;
    delete[] aux_asistencia;
}
TEST_CASE("AchicarTamTEST", "[fancy]")
{
    int N=5;
    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=4;
    aux_asistencia->CursosInscriptos = new Inscripcion[N]; // Asignar memoria para CursosInscriptos
    aux_asistencia->CursosInscriptos[0]={1, time(0)};
    aux_asistencia->CursosInscriptos[1]={2, time(0)};
    aux_asistencia->CursosInscriptos[2]={3, time(0)};
    aux_asistencia->CursosInscriptos[3]={4, time(0)};
    achicartamInscrip(aux_asistencia->CursosInscriptos, N);
    REQUIRE(N == 4);
    cout<<"N es: " << N <<endl;
    delete[] aux_asistencia->CursosInscriptos;
    delete[] aux_asistencia;
}
TEST_CASE("DesplazarAlFinalElemento", "[fancy]")
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
}
/*TEST_CASE("NOdobleId_Cliente", "[fancy]")
{
    int N=4;
    int M=1;
    Asistencia* asistencia_dia = new Asistencia[N];
    for (int i = 0; i < N; ++i)
    {
        asistencia_dia[i].CursosInscriptos = new Inscripcion[M]; // Asignar memoria para CursosInscriptos
    }
    asistencia_dia[0]={1,1,{{1,time(0)}}};
    asistencia_dia[1]={2,1,{{1,time(0)}}};
    asistencia_dia[2]={2,1,{{1,time(0)}}};
    asistencia_dia[3]={3,1,{{1,time(0)}}};

    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->CursosInscriptos = new Inscripcion[M]; // Asignar memoria para CursosInscriptos
    aux_asistencia={2,1{2,time(0)}};

    int ret=0;
    ret=dobleid_cliente(aux_asistencia,asistencia_dia,N);

    REQUIRE(ret==-1);
    //libero memoria:
    for (int i = 0; i < N; ++i)
    {
        delete[] asistencia_dia[i].CursosInscriptos; // Liberar memoria para cada CursosInscriptos
    }
    delete[] asistencia_dia;
    delete[] aux_asistencia->CursosInscriptos; // Liberar memoria para CursosInscriptos de aux_asistencia
    delete[] aux_asistencia; // Liberar memoria para asistencia_dia
}*/
TEST_CASE("NODobleIdCurso", "[fancy]")
{
    int N=4;
    Asistencia* aux_asistencia = new Asistencia[1];
    aux_asistencia->idCliente=1;
    aux_asistencia->cantInscriptos=4;
    aux_asistencia->CursosInscriptos = new Inscripcion[N]; // Asignar memoria para CursosInscriptos
    aux_asistencia->CursosInscriptos[0].idCurso=2020;
    aux_asistencia->CursosInscriptos[0].fechaInscripcion=time(0);
    aux_asistencia->CursosInscriptos[1].idCurso=2020;
    aux_asistencia->CursosInscriptos[1].fechaInscripcion=time(0);
    aux_asistencia->CursosInscriptos[2].idCurso=2040;
    aux_asistencia->CursosInscriptos[2].fechaInscripcion=time(0);
    aux_asistencia->CursosInscriptos[3].idCurso=2050;
    aux_asistencia->CursosInscriptos[3].fechaInscripcion=time(0);

    dobleid_curso(aux_asistencia);
    //REQUIRE(aux_asistencia->cantInscriptos==3);
    REQUIRE(aux_asistencia->CursosInscriptos[0].idCurso==2020);
    REQUIRE(aux_asistencia->CursosInscriptos[1].idCurso==2040);
    REQUIRE(aux_asistencia->CursosInscriptos[2].idCurso==2050);

    delete[] aux_asistencia->CursosInscriptos;
    delete[] aux_asistencia;
}
