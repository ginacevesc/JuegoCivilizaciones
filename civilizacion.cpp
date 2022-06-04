#include "civilizacion.h"
#include <algorithm>
#include <fstream>
#include <conio.h>

Civilizacion::Civilizacion()
{

}

void Civilizacion::Agregar_Aldeano(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::Crear_Aldeano(size_t n, const Aldeano &a)
{
    aldeanos = vector<Aldeano>(n,a);
}

void Civilizacion::Primer_Aldeano()
{
    if (aldeanos.empty())
    {
        cout << "No se encontro ningun aldeano." << endl;
    }
    else
    {
        cout << "El primer aldeano es: " << endl << aldeanos.front() << endl;
    }
    //getchar();

}

void Civilizacion::Ultimo_Aldeano()
{
    if (aldeanos.empty())
    {
        cout << "No se encontro ningun aldeano." << endl;
    }
    else
    {
        cout << "El ultimo aldeano es: " <<  endl << aldeanos.back() << endl;
    }
    //getchar();
}

void Civilizacion::Ordenar()
{
    sort(aldeanos.begin(), aldeanos.end());
}

size_t Civilizacion::Poblacion_Total()
{
    return aldeanos.size();
}

void Civilizacion::Resumen()
{
    if (aldeanos.size() == 0)
    {
        cout << "La civilizacion no tiene aldeanos" << endl;
    }
    else
    {
        //cout << left;
//        cout << setw(8) << "Nombre: ";
//        cout << setw(10) << "Edad: ";
//        cout << setw(12) << "Genero: ";
//        cout << setw(11) << "Salud: " << endl;
        for (size_t i  = 0; i  < aldeanos.size(); i++)
        {
                Aldeano &a = aldeanos[i];
                cout << setw(0)<<a.getNombre();
                cout << setw(10)<<a.getEdad();
                cout << setw(10)<<a.getGenero();
                cout << setw(10)<<a.getSalud()<<endl;
        }
    }
    //getchar();
}

void Civilizacion::Eliminar_Aldeano(const string &nombre)
{
    if (aldeanos.empty())
    {
        cout << "No se encontro ningun aldeano." << endl;
    }
    else
    {
        auto it = aldeanos.begin();
        for(size_t i = 0; i < aldeanos.size(); i++)
        {
            if (aldeanos[i].getNombre() == nombre)
            {
                aldeanos.erase(it + i);
                cout << "Aldeano eliminado." << endl;
                getchar();
            }
            else if (i==aldeanos.size()-1 and aldeanos[i].getNombre() != nombre )
            {
                cout <<endl<< "No se encontro ningun aldeano con ese nombre." << endl;

            }

        }

    }

}

float Civilizacion::Salud_Prom()
{
    float s=0;
    for (size_t i = 0; i < aldeanos.size(); i++)
    {
        Aldeano &a = aldeanos[i];
        s += aldeanos[i].getSalud();
    }
    s=s/aldeanos.size();
    return s;
}

void Civilizacion::Agregar_Barco(barco *b)
{
    puerto.push_back(b);
}

void Civilizacion::mostrarb()
{
    if (puerto.size() == 0)
    {
        cout << "El puerto no tiene barcos aun." << endl;
    }
    else
    {
        cout << left;
        cout << setw(8) << "Id: ";
        cout << setw(10) << "Combustible: ";
        cout << setw(12) << "Velocidad: ";
        cout << setw(11) << "Armadura: ";
        cout << setw(12) << "Cantidad de Guerreros: " << endl;
        for (auto it = puerto.begin() ; it != puerto.end(); it++)
        {
                barco *b = *it;
                cout << setw(0)  << b->getId() << "            ";
                cout << setw(10) << b->getCombustible();
                cout << setw(12) << b->getVelocidad();
                cout << setw(11) << b->getArmadura();
                cout << setw(12) << b->T_Guerreros() << endl;
        }
    }
}

void Civilizacion::buscarb()
{
    string buscar;
    char bandera = 'F';
    char ban = 'F';
    cout << "Ingrese el Id del barco a buscar: " << endl;
    getline(cin, buscar);

    for(auto it= puerto.begin() ; it!= puerto.end() ; it++)
    {
        barco *b = *it;
        if(b->getId() == buscar)
        {

            cout << "Barco encontrado." << endl;
            ban = 'V';
            guerrero g;
            int sel;

            do
            {
                system("cls");
                cout << "Id del barco: " << buscar << endl;
                cout << "\n1.- Agregar Guerrero." << endl
                     << "2.- Eliminar Ultimo Guerrero." << endl
                     << "3.- Mostrar Ultimo Guerrero." << endl
                     << "4.- Mostrar Todos Los Guerreros." << endl
                     << "5.- Regresar." << endl;
                cin >> sel;
                cin.ignore();

                switch(sel)
                {
                case 1:
                {
                    system("cls");
                    string id;
                    int salud;
                    int guerr;
                    double fuerza;
                    double escudo;

                    cout << "Ingrese Id del Guerrero: " << endl;
                    getline(cin,id);
                    g.setId(id);

                    cout << "Ingrese la Salud del Guerrero: " << endl;
                    cin >> salud;
                    cin.ignore();
                    g.setSal(salud);

                    cout << "Ingrese la Fuerza del Guerrero: " << endl;
                    cin >> fuerza;
                    cin.ignore();
                    g.setFuerza(fuerza);

                    cout << "Ingrese el escudo del Guerrero: " << endl;
                    cin >> escudo;
                    cin.ignore();
                    g.setEscudo(escudo);

                    cout << "Elija el tipo de Guerrero: \n" << endl;

                    cout << "1.- Lancero." << endl
                         << "2.- Arquero." << endl
                         << "3.- Paladin." << endl
                         << "4.- Cazador." << endl
                         << "5.- Brujo." << endl;
                    cout << "\nSu eleccion: " << endl;
                    cin >> guerr;
                    cin.ignore();

                    switch(guerr)
                    {
                    case 1:
                    {
                        g.setT_Guerrero("Lancero");
                        break;
                    }
                    case 2:
                    {
                        g.setT_Guerrero("Arquero");
                        break;
                    }
                    case 3:
                    {
                        g.setT_Guerrero("Paladin");
                        break;
                    }
                    case 4:
                    {
                        g.setT_Guerrero("Cazador");
                        break;
                    }
                    case 5:
                    {
                        g.setT_Guerrero("Brujo");
                        break;
                    }
                    }

                    b->Agregar_Guerrero(g);
                    cout << "Guerrero aniadido con exito." << endl;
                    bandera = 'V';
                    //system("cls");
                    system("pause");
                    break;
                }
                case 2:
                {
                    system("cls");
                    b->Eliminar_Guerrero();
                    cout << "Ultimo Guerrero Eliminado." << endl;
                    system("pause");
                    bandera = 'V';
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout << "El ultimo Guerrero fue:" << endl;
                    b->Tope();
                    bandera = 'V';
                    system("pause");
                    break;
                }
                case 4:
                {
                    system("cls");
                    cout << "Guerreros:\n" << endl;
                    b->mostrarg();
                    bandera = 'V';
                    system("pause");
                    break;
                }
                case 5:
                {
                    break;
                }
              }

            }while(sel!=5);
            ban = 'V';
        }

        ban = 'V';
        if(ban == 'F')
        {
            cout << "No existe un barco con ese Id." << endl;
            break;
        }
    }
}

void Civilizacion::elim_id()
{
    string el;
    cout << "Escriba el Id del barco a eliminar: " << endl;
    getline(cin, el);

    for(auto it = puerto.begin() ; it != puerto.end() ; it++)
    {
        barco *b = *it;

        if(el == b->getId())
        {
            puerto.erase(it);
            barco *b = NULL;
            delete b;
            break;
        }
    }

}

void Civilizacion::elim_comb()
{
    double cant=0;
    cout << "Ingrese la cantidad de Combustible: " << endl;
    cin >> cant;
    cin.ignore();

    puerto.remove_if([cant](barco *b){return b->getCombustible() < cant;});
    barco *b = NULL;
    delete b;
}

void Civilizacion::buscarpq()
{
    string idd;
    char ban = 'F';
    cout << "Escriba el Id del barco que entrara en batalla." << endl;
    getline(cin,idd);

    for(auto it = puerto.begin() ; it != puerto.end() ; it++)
    {
        barco *b = *it;

        if(idd == b->getId())
        {
            ban = 'V';
            if(b->getCombustible() > 0.0)
            {
                cout << "Barco encontrado!\n" << endl;
                double v;
                cout << "Escriba la velocidad deseada: " << endl;
                cin >> v;
                b->setVelocidad(v);
                cin.ignore();

                pq.push(b);
                puerto.erase(it);
                break;
            }
            else if(b->getCombustible() < 0.0)
            {
                ban = 'C';
                cout << "El combustible debe ser mayor a 0.0" << endl;
                break;
            }
            ban = 'V';

        }
        //ban = 'V';
//        if(ban=='V' || ban == 'C')
//        {
//            break;
//        }
    }
    if(ban == 'F')
    {
        cout << "No existe Barco con ese Id." << endl;
        //break;
    }
}

void Civilizacion::moverpq()
{
    //if(pq.pop)
    double comb, arm;
    barco *b = pq.top();
    if(b->getArmadura() <= 0.0 || b->getCombustible() <= 0.0)
    {
        cout << "El barco no puede regresar al puerto." << endl;
        pq.pop();
        delete b;
        //break;
    }
    else if(b->getArmadura() > 0.0)
    {
        cout << "Barco: " << b->getId() << endl << endl;
        b->setVelocidad(0.0);
        cout << "Ingrese la cantidad de combustible: " << endl;
        cin >> comb;
        cin.ignore();
        b->setCombustible(comb);
        cout << "Ingrese la armadura: " << endl;
        cin >> arm;
        cin.ignore();
        if(arm <=0)
        {
            cout << "El barco no puede regresar al puerto." << endl;
            delete b;
            pq.pop();
        }
        else
        {
            b->setArmadura(arm);
            puerto.push_back(b);
            pq.pop();
            cout << "Se ha retirado de la batalla al barco: " << b->getId() << endl;
        }

        //break;
    }

    priority_queue <barco*, vector <barco*>, barco::Comparador > copy;
    while(!pq.empty())
    {
        barco *aux = pq.top();
        aux->setArmadura(aux->getArmadura()-10);
        aux->setCombustible(aux->getCombustible()-15);

        if(aux->getArmadura() <= 0 || aux->getCombustible() <= 0)
        {
            delete aux;
        }
        else
        {
            copy.push(aux);
        }
        pq.pop();
    }
    pq = copy;
    //copy.pop();
    //break;
}

void Civilizacion::mostrarpq()
{
    if(pq.empty())
    {
        cout << "Aun no hay barcos en batalla." << endl;
    }
    else
    {
        priority_queue <barco*, vector <barco*>, barco::Comparador > copy(pq);
        cout << left;
        cout << setw(8) << "Id: ";
        cout << setw(13) << "Velocidad: ";
        cout << setw(17) << "Combustible: ";
        cout << setw(20) << "Armadura: ";
        cout << endl;
        while(!copy.empty())
        {
            barco *b = copy.top();
            cout << setw(0) << b->getId() << "        "
                 << setw(10) << b->getVelocidad()
                 << setw(12) << b->getCombustible() << "   "
                 << setw(13) << b->getArmadura() << endl;
            //cout << setw(10) << *b << endl;
            copy.pop();
            //delete b;
        }
    }
}

string Civilizacion::getNombre() const
{
    return Nombre;
}

void Civilizacion::setNombre(const string &value)
{
    Nombre = value;
}

