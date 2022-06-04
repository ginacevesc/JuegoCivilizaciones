#include "guerrero.h"

guerrero::guerrero()
{

}

string guerrero::getId() const
{
    return id;
}

void guerrero::setId(const string &value)
{
    id = value;
}

int guerrero::getSal() const
{
    return Sal;
}

void guerrero::setSal(int value)
{
    Sal = value;
}

string guerrero::getT_Guerrero() const
{
    return T_Guerrero;
}

void guerrero::setT_Guerrero(const string &value)
{
    T_Guerrero = value;
}

double guerrero::getFuerza() const
{
    return Fuerza;
}

void guerrero::setFuerza(double value)
{
    Fuerza = value;
}

double guerrero::getEscudo() const
{
    return Escudo;
}

void guerrero::setEscudo(double value)
{
    Escudo = value;
}
