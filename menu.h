#ifndef MENU_H
#define MENU_H
#include "civilizacion.h"
#include "aldeano.h"
#include <list>
#include <iomanip>
#include "guerrero.h"
#include "barco.h"

class Menu
{
public:
    Menu();
    //void eliminar_poblacion(const size_t p);
private:
    //Civilizacion civilizacion;
    void Agregar(Civilizacion &c);
    void Crear(Civilizacion &c);
    void Eliminar();
    void Resumen();
    void Ordenar_Nombre();
    void Ordenar_Pob();
    void Ordenar_Salud();
    void EliminarX( size_t a);
    void Respaldar(list <Civilizacion> &civilizaciones);
    void Recuperar(list <Civilizacion> &civilizaciones);

    void agregarb(Civilizacion &);
    void eliminarb(Civilizacion &c);

    list <Civilizacion> civilizaciones;
};

#endif // MENU_H
