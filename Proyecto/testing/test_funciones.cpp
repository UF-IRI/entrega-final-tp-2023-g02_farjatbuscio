#include <catch2/catch.hpp>
#include "funciones.cpp"
#include "archivos.cpp"
#include <ctime>

/**********test achicar tamano de un vector**********/
TEST_CASE("AchicarTamTEST", "[fancy]")
{
    int N=5;
    string *vector = new string[N];
    achicartam(vector, N);
    REQUIRE(N == 4);
    cout<<"N es: " << N <<endl;
    delete[] vector;
}
/**********test agrandar tamano de un vector**********/
TEST_CASE("AgrandarTamTEST", "[fancy]")
{
    int N=5;
    string *vector = new string[N];
    agrandartam(vector, N);
    REQUIRE(N == 6);
    cout<<"N es: " << N <<endl;
    delete[] vector;
}
/*******desplazar un elemento al final y mover los elementos restantes una posición hacia arriba*******/
TEST_CASE("DesplazarAlFinalElemento1", "[fancy]")
{
    unsigned int cantInscriptos=4;
    inscripcion *cursosInscriptos = new inscripcion[cantInscriptos];
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
    inscripcion *cursosInscriptos = new inscripcion[cantInscriptos];
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
    inscripcion *cursosInscriptos = new inscripcion[cantInscriptos];
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
    inscripcion *cursosInscriptos = new inscripcion[cantInscriptos];
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
    inscripcion *cursosInscriptos = new inscripcion[cantInscriptos];
    unsigned int pos=1;
    cursosInscriptos[0]={1, time(0)};
    cursosInscriptos[1]={2, time(0)};
    cursosInscriptos[2]={3, time(0)};
    cursosInscriptos[3]={4, time(0)};
    moveralfinal(cursosInscriptos, cantInscriptos, pos);
    REQUIRE(cursosInscriptos[2].idCurso==4);
    delete[] cursosInscriptos;
}
