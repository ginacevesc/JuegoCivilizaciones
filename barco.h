#ifndef BARCO_H
#define BARCO_H
#include <iostream>
#include "guerrero.h"
#include <stack>
#include <iomanip>


using namespace std;

class barco
{
public:
    barco();
    string getId() const;
    void setId(const string &value);

    void Agregar_Guerrero(guerrero &gu);
    void Eliminar_Guerrero();
    void Tope();

    double getCombustible() const;
    void setCombustible(double value);

    double getVelocidad() const;
    void setVelocidad(double value);

    double getArmadura() const;
    void setArmadura(double value);

    size_t T_Guerreros();
    void mostrarg();

//    friend ostream& operator << (ostream &out, guerrero &g)
//    {
//        out << "Id: " << g.getId() << endl;
//        out << "Salud: " << g.getSal() << endl;
//        out << "Fuerza: " << g.getFuerza() << endl;
//        out << "Escudo: " << g.getEscudo() << endl;
//        out << "Tipo de Guerrero: " << g.getT_Guerrero() << endl;

//        return out;
//    }

    barco(string i, double v, double c, double a)
    {
        id = i;
        Velocidad = v;
        Combustible = c;
        Armadura = a;
    }

    friend ostream& operator << (ostream &o, barco &b)
    {
        o << setw(3) << b.getId();
        o << setw(4) << b.getVelocidad();
        o << setw(4) << b.getCombustible();
        o << setw(4) << b.getArmadura();

        return o;
    }

    struct Comparador
    {
      bool operator() (barco *b1, barco *b2)
      {
          return b1->getVelocidad() < b2->getVelocidad();
      }
    };

private:
    string id;
    double Combustible;
    double Velocidad;
    double Armadura;
    stack <guerrero> g;
};

#endif // BARCO_H
