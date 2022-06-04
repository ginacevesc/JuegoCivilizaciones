#include "aldeano.h"

Aldeano::Aldeano()
{

}

string Aldeano::getNombre() const
{
    return Nombre;
}

void Aldeano::setNombre(const string &value)
{
    Nombre = value;
}

int Aldeano::getEdad() const
{
    return Edad;
}

void Aldeano::setEdad(int value)
{
    Edad = value;
}

string Aldeano::getGenero() const
{
    return Genero;
}

void Aldeano::setGenero(const string &value)
{
    Genero = value;
}

int Aldeano::getSalud() const
{
    return Salud;
}

void Aldeano::setSalud(int value)
{
    Salud = value;
}
