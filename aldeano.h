#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>
#include <fstream>

using namespace std;


class Aldeano
{
public:
    Aldeano();

    string getNombre() const;
    void setNombre(const string &value);

    int getEdad() const;
    void setEdad(int value);

    string getGenero() const;
    void setGenero(const string &value);

    int getSalud() const;
    void setSalud(int value);

    friend ostream& operator << (ostream &out, Aldeano &a)
    {
        out << "Nombre: " << a.getNombre() << endl;
        out << "Edad: " << a.getEdad() << endl;
        out << "Genero: " << a.getGenero() << endl;
        out << "Salud: " << a.getSalud() << endl;

        return out;
    }

    bool operator <(Aldeano &a) const
    {
        return Salud <a.getSalud();
    }

private:
    string Nombre;
    int Edad;
    string Genero;
    int Salud;
};

#endif // ALDEANO_H
