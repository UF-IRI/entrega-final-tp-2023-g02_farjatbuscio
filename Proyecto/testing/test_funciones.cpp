#include <catch2/catch.hpp>
#include "funciones.cpp"
#include "archivos.cpp"
#include <ctime>

/**********test achicar tamano de inscripcion**********/
TEST_CASE("AchicarTamTEST", "[fancy]")
{
    int N=5;
    Inscripcion *vector = new Inscripcion[N];
    achicartam(vector, N);
    REQUIRE(N == 4);
    cout<<"N es: " << N <<endl;
    delete[] vector;
}
/**********test agrandar tamano de Inscripcion**********/
TEST_CASE("AgrandarTamTEST", "[fancy]")
{
    int N=5;
    Inscripcion *vector = new Inscripcion[N];
    agrandartam(vector, N);
    REQUIRE(N == 6);
    cout<<"N es: " << N <<endl;
    delete[] vector;
}
/*******desplazar un elemento al final y mover los elementos restantes una posición hacia arriba*******/
TEST_CASE("DesplazarAlFinalElemento1", "[fancy]")
{
    unsigned int cantInscriptos=4;
    Inscripcion *cursosInscriptos = new Inscripcion[cantInscriptos];
    unsigned int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    cout<< "ultimo id_curso deberia ser 2 (con el cambio hecho), ult id_curso: "<<cursosInscriptos[3].idCurso<<endl;
    REQUIRE(cursosInscriptos[3].idCurso==2);
    delete[] cursosInscriptos;
}
TEST_CASE("DesplazarAlFinalElemento2", "[fancy]")
{
    unsigned int cantInscriptos=4;
    Inscripcion *cursosInscriptos = new Inscripcion[cantInscriptos];
    unsigned int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    cout<< "ultimo fechainscrip deberia ser: " << time(0) << " Ultimo fechainscrip es: "<<cursosInscriptos[3].fechaInscripcion<<endl;
    REQUIRE(cursosInscriptos[3].fechaInscripcion==time(0));
    delete[] cursosInscriptos;
}
TEST_CASE("DesplazarAlFinalElemento3", "[fancy]")
{
    unsigned int cantInscriptos=4;
    Inscripcion *cursosInscriptos = new Inscripcion[cantInscriptos];
    unsigned int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    REQUIRE(cursosInscriptos[0].idCurso==1);
    delete[] cursosInscriptos;
}
TEST_CASE("DesplazarAlFinalElemento4", "[fancy]")
{
    unsigned int cantInscriptos=4;
    Inscripcion *cursosInscriptos = new Inscripcion[cantInscriptos];
    unsigned int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    REQUIRE(cursosInscriptos[1].idCurso==3);
    delete[] cursosInscriptos;
}
TEST_CASE("DesplazarAlFinalElemento5", "[fancy]")
{
    unsigned int cantInscriptos=4;
    Inscripcion *cursosInscriptos = new Inscripcion[cantInscriptos];
    unsigned int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    REQUIRE(cursosInscriptos[2].idCurso==4);
    delete[] cursosInscriptos;
}
/*****Chequea que el cliente del archivo Asitencia_dia que voy a leer, no esté ya anotado en Asistencia_dia*****/
TEST_CASE("NOdobleId_Cliente", "[fancy]")
{
    int aux;
    unsigned int N=3;
    Asistencia *asistencia_dia = new Asistencia[N];
    asistencia_dia[0].idCliente=1;
    asistencia_dia[0].cantInscriptos=1;
    asistencia_dia[0].CursosInscriptos->idCurso=2;
    asistencia_dia[0].CursosInscriptos->fechaInscripcion=time(0);
    asistencia_dia[1].idCliente=2;
    asistencia_dia[1].cantInscriptos=1;
    asistencia_dia[1].CursosInscriptos->idCurso=2;
    asistencia_dia[1].CursosInscriptos->fechaInscripcion=time(0);
    asistencia_dia[2].idCliente=3;
    asistencia_dia[2].cantInscriptos=1;
    asistencia_dia[2].CursosInscriptos->idCurso=2;
    asistencia_dia[2].CursosInscriptos->fechaInscripcion=time(0);
    Asistencia *aux_asistencia= new Asistencia[1];
    aux_asistencia->idCliente=2;
    aux_asistencia->cantInscriptos=1;
    aux_asistencia->CursosInscriptos->idCurso=2;
    aux_asistencia->CursosInscriptos->fechaInscripcion=time(0);

    aux = dobleid_cliente(aux_asistencia,asistencia_dia,N);

    REQUIRE(aux == -1);
    delete[] asistencia_dia;
    delete[] aux_asistencia;
}
