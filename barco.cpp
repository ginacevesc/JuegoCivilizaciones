#include "barco.h"

barco::barco()
{

}

string barco::getId() const
{
    return id;
}

void barco::setId(const string &value)
{
    id = value;
}

void barco::Agregar_Guerrero(guerrero &gu)
{
    g.push(gu);
}

void barco::Eliminar_Guerrero()
{
    if(g.size() == 0)
    {
        cout << "No hay guerreros." << endl;
    }
    else
    {
       g.pop();
    }

}

void barco::Tope()
{
    if(g.size()==0)
    {
        cout << "No hay guerreros." << endl;
    }
    else
    {
       cout << "Id: " << g.top().getId() << endl;
       cout << "Salud: " << g.top().getSal() << endl;
       cout << "Escudo: " << g.top().getEscudo() << endl;
       cout << "Fuerza: " << g.top().getFuerza() << endl;
       cout << "Tipo de Guerrero: " << g.top().getT_Guerrero() << endl;
    }

}

double barco::getCombustible() const
{
    return Combustible;
}

void barco::setCombustible(double value)
{
    Combustible = value;
}

double barco::getVelocidad() const
{
    return Velocidad;
}

void barco::setVelocidad(double value)
{
    Velocidad = value;
}

double barco::getArmadura() const
{
    return Armadura;
}

void barco::setArmadura(double value)
{
    Armadura = value;
}

size_t barco::T_Guerreros()
{
    return g.size();
}

void barco::mostrarg()
{
    stack<guerrero>copy(g);
    int contador = 1;

    while(!copy.empty())
    {
        guerrero g = copy.top();
        //cout << g << endl;
        //copy.pop();


        cout << contador;
        cout << "\tId: " <<  g.getId()
             << "\tSalud: " << g.getSal()
             << "\tEscudo: " << g.getEscudo()
             << "\tFuerza: " << g.getFuerza()
             << "\tTipo de Guerrero: " << g.getT_Guerrero() << endl<< endl;
             contador++;
        copy.pop();
    }
}
