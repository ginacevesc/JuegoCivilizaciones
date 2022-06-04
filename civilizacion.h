#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <vector>
#include <iomanip>
#include "aldeano.h"
#include <list>
#include "barco.h"
#include <queue>

class Civilizacion
{
public:
    Civilizacion();
    void Agregar_Aldeano(const Aldeano &a);
    void Crear_Aldeano(size_t n, const Aldeano &a);
    void Primer_Aldeano();
    void Ultimo_Aldeano();
    void Ordenar();
    size_t Poblacion_Total();
    void Resumen();
    void Eliminar_Aldeano(const string &nombre);
    float Salud_Prom();

    Aldeano &operator[](size_t i)
    {
        return aldeanos[i];
    }
    Civilizacion& operator <<(Aldeano &a)
    {
        Agregar_Aldeano(a);
        return *this;
    }

    void Agregar_Barco(barco *b);
    void mostrarb();
    void buscarb();
    void elim_id();
    void elim_comb();

    void buscarpq();
    void moverpq();
    void mostrarpq();

    string getNombre() const;
    void setNombre(const string &value);

private:
    string Nombre;
    vector <Aldeano> aldeanos;
    list <barco*> puerto;
    priority_queue <barco*, vector <barco*>, barco::Comparador > pq;
};

#endif // CIVILIZACION_H
