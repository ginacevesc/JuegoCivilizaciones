#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>

using namespace std;


class guerrero
{
public:
    guerrero();
    string getId() const;
    void setId(const string &value);

    int getSal() const;
    void setSal(int value);

    string getT_Guerrero() const;
    void setT_Guerrero(const string &value);

    double getFuerza() const;
    void setFuerza(double value);

    double getEscudo() const;
    void setEscudo(double value);

private:
    string id;
    int Sal;
    double Fuerza;
    double Escudo;
    string T_Guerrero; //enumerar
};

#endif // GUERRERO_H
