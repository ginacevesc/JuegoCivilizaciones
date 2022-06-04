#include "menu.h"
#include "aldeano.h"
#include "civilizacion.h"
#include <iostream>
#include <iomanip>

using namespace std;

Menu::Menu()
{

    int opc;
    do
    {
        system("cls");
        cout << "Menu: " << endl
             << "1.- Agregar civilizacion." << endl
             << "2.- Buscar civilizacion." << endl
             << "3.- Eliminar civilizacion." << endl
             << "4.- Ordenar civilizaciones." << endl
             << "5.- Mostrar civilizaciones." << endl
             << "6.- Respaldar." << endl
             << "7.- Recuperar." << endl
             << "8.- Salir." << endl;
        cin >> opc;
        cin.ignore();


        switch(opc)
        {
        case 1:
        {
           system("cls");
           Civilizacion civil;
           string n1, opc1;
           char b = 'F';

           cout << "Ingrese el nombre de la civilizacion: " << endl;
           getline(cin,n1);
           civil.setNombre(n1);

           cout << "1.- Agregar objeto civilizacion al inicio." << endl
                << "2.- Agregar objeto civilizacion al final. " << endl;
           getline(cin,opc1);

           if (opc1 == "1")
           {
               cout << "Agregada al inicio exitosamente." << endl;
               civilizaciones.push_front(civil);
               system("pause");
               b = 'V';
           }
           else if(opc1 == "2")
           {
               cout << "Agregada al final exitosamente." << endl;
               civilizaciones.push_back(civil);
               system("pause");
               b = 'V';
           }

           if (b == 'V')
           {
               break;
           }
           else if(b == 'F')
           {
               cout << "Ingrese una opcion" << endl;
                system("pause");
           }
           break;

        }
        case 2:
        {
            system("cls");
            char band = 'F';
            string n2;
            cout << "Ingrese la civilizacion a buscar:" << endl;
            getline(cin,n2);


            for (auto it=civilizaciones.begin();it!=civilizaciones.end();++it)
            {
                Civilizacion &c = *it;
                if(c.getNombre() == n2)
                {

                    cout << "Civilizacion: " << n2 << endl;

                    int a;
                    cout << "Submenu" << endl;
                    cout << "1.- Aldeanos." << endl
                         << "2.- Puerto." << endl;
                    cin >> a;
                    cin.ignore();

                    switch(a)
                    {
                    case 1:
                    {
                        string op;

                           cout << "1.- Agregar Aldeano" << endl;
                           cout << "2.- Crear Aldeanos" << endl;
                           cout << "3.- Primer Aldeano" << endl;
                           cout << "4.- Ultimo Aldeano" << endl;
                           cout << "5.- Ordenar" << endl;
                           cout << "6.- Eliminar Aldeano" << endl;
                           cout << "7.- Resumen" << endl;
                           cout << "8.- Salir" << endl;
                           getline(cin,op);

                           if (op == "1")
                           {
                               system("cls");
                               Agregar(c);
                               system("pause");
                               band = 'V';
                               break;
                           }
                           else if (op == "2")
                           {
                               system("cls");
                               Crear(c);
                               system("pause");
                               band = 'V';
                               break;
                           }
                           else if (op == "3")
                           {
                               system("cls");
                               c.Primer_Aldeano();
                               system("pause");
                               band = 'V';
                               break;
                           }
                           else if (op == "4")
                           {
                               system("cls");
                               c.Ultimo_Aldeano();
                               system("pause");
                               band = 'V';
                               break;
                           }
                           else if (op == "5")
                           {
                               system("cls");
                               c.Ordenar();
                               band = 'V';
                               break;
                           }
                           else if (op == "6")
                           {
                               system("cls");
                               //Eliminar();
                               cout << "holi" << endl;
                               system("pause");
                               band = 'V';
                               break;
                           }
                           else if (op == "7")
                           {
                               system("cls");
                               //Resumen();
                               //cout << "holi" << endl;
                               system("pause");
                               band = 'V';
                               break;
                           }
                           else if (op == "8")
                           {
                               cout << "Saliendo..." << endl;
                               band = 'V';
                               break;
                           }
                           band = 'V';
                           break;
                        }
                    case 2:
                    {
                        int opcion = 0;

                        do
                        {
                            system("cls");
                            cout << "Puerto\n" << endl;
                            cout << "1.- Agregar Barco." << endl
                                 << "2.- Mostrar Barcos." << endl
                                 << "3.- Buscar Barcos." << endl
                                 << "4.- Eliminar." << endl
                                 << "5.- Agregar Barco por ID a la batalla." << endl
                                 << "6.- Sacar Barco de la batalla." << endl
                                 << "7.- Mostrar Barcos en batalla." << endl
                                 << "8.- Volver.\n" << endl;
                            cout << "Opcion: ";
                            cin >> opcion;
                            cin.ignore();

                            switch(opcion)
                            {
                            case 1:
                            {
                                system("cls");
                                agregarb(c);
                                cout << "Se ha agregado el barco." << endl;
                                system("pause");
                                break;
                            }
                            case 2:
                            {
                                system("cls");
                                c.mostrarb();
                                system("pause");
                                break;
                            }
                            case 3:
                            {
                                system("cls");
                                c.buscarb();
                                system("pause");
                                break;
                            }
                            case 4:
                            {
                                system("cls");
                                eliminarb(c);
                                //cout << " 4 " << endl;
                                break;
                            }
                            case 5:
                            {
                                system("cls");
                                c.buscarpq();
                                system("pause");
                                break;
                            }
                            case 6:
                            {
                                system("cls");
                                c.moverpq();
                                system("pause");
                                break;
                            }
                            case 7:
                            {
                                system("cls");
                                c.mostrarpq();
                                system("pause");
                                break;
                            }
                            }
                        }
                        while(opcion!=8);
                        //system("pause");

                        band = 'V';
                        break;
                    }

                    }
                    if(band == 'V')
                    {
                        break;
                    }
                    if(band == 'F')
                    {
                        cout << "No se encontro la civilizacion." << endl;
                        system("pause");
                    }
                        break;
                    }
                    }


            //system("pause");
                break;
        }
        case 3:
        {
            system("cls");
            int opc3;

            cout << "1.- Eliminar por nombre." << endl
                 << "2.- Eliminar por poblacion total menor a x." << endl
                 << "3.- Eliminar por salud promedio menor a 20." << endl;
            cin >> opc3;
            cin.ignore();

            switch(opc3)
            {
            case 1:
            {
                string n3;
                cout << "Ingrese el nombre de la civilizacion a eliminar: " << endl;
                getline(cin, n3);
                for (auto it=civilizaciones.begin();it!=civilizaciones.end();++it)
                {
                        Civilizacion &c= *it;
                        if(n3 == c.getNombre())
                        {
                            civilizaciones.erase(it);
                            cout << "Civilizacion eliminada." << endl;
                            break;
                        }
                }
                system("pause");
                break;
            }
            case 2:
            {
                size_t a;
                cout << "Ingrese la cifra de poblacion: " <<endl;
                cin >> a;
                cin.ignore();
                //EliminarX(a);
                civilizaciones.remove_if([a](Civilizacion &c){return c.Poblacion_Total() < a;});
                cout << "Civilizaciones con poblacion menor a " << a << " eliminadas." << endl;
                system("pause");
                break;
            }
            case 3:
            {
                size_t sal = 20;
                civilizaciones.remove_if([sal](Civilizacion &c){return c.Salud_Prom() < sal;});
                cout << "Se han eliminado las civilizaciones con salud menor a 20." << endl;
                system("pause");
                break;
            }
            }

            //system("pause");
            break;

        }
        case 4:
        {
            system("cls");
            int opc4;
            cout << "1.- Ordenar por nombre (ascendente). " << endl
                 << "2.- Ordenar por poblacion total (descendente). " << endl
                 << "3.- Ordenar por salud promedio (descendente). " << endl;
            cin >> opc4;

            switch(opc4)
            {
            case 1:
            {
                Ordenar_Nombre();
                cout << "Se han ordenado las civilizaciones." << endl;

                break;
            }
            case 2:
            {
                Ordenar_Pob();
                cout << "Se han ordenado las civilizaciones." << endl;
                break;
            }
            case 3:
            {
                Ordenar_Salud();
                cout << "Se han ordenado las civilizaciones." << endl;
                break;
            }
            }

            system("pause");
            break;

        }
        case 5:
        {
            system("cls");
            for (auto it=civilizaciones.begin();it!=civilizaciones.end();++it)
            {
                Civilizacion &c= *it;
                cout << endl
                     << "Civilizacion: " << c.getNombre() << endl
                     << "Poblacion total: " << c.Poblacion_Total() << endl
                     << "Aldeanos: " << endl;
                c.Resumen();

                cout << endl << endl;
            }
            system("pause");
            break;

        }
        case 6:
        {
            system("cls");
            Respaldar(civilizaciones);
            cout << "Civilizaciones respaldadas con exito." << endl;
            system("pause");

        }
            break;
        case 7:
        {
            system("cls");
            //Civilizacion c;
            //civilizaciones = c.rec
            Recuperar(civilizaciones);
            cout << "Civilizaciones recuperadas." << endl;
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            cout << "Saliendo..." << endl;
            break;
        }
        }
        //break;
    }
    while(opc!=8);

}

void Menu::Agregar(Civilizacion &c)
{
    Aldeano a;
    string Nombre;
    int Edad;
    string Genero;
    int Salud;


    cout << "Nombre: ";
    getline (cin,Nombre);
    a.setNombre(Nombre);

    cout << "Edad: ";
    cin >> Edad;
    a.setEdad(Edad);

    cout << "Genero (M/F): ";
    cin >> Genero;
    a.setGenero(Genero);

    cout << "Salud: ";
    cin >> Salud;
    a.setSalud(Salud);

    cin.ignore();

    c << a;
    cout << "Aldeano agregado." << endl;
}

void Menu::Crear(Civilizacion &c)
{
    string Nombre;
    int Edad;
    string Genero;
    int Salud;
    Aldeano a;

    cout << "Nombre: ";
    getline (cin,Nombre);
    a.setNombre(Nombre);

    cout << "Edad: ";
    cin >> Edad;
    a.setEdad(Edad);

    cout << "Genero (M/F):";
    cin >> Genero;
    a.setGenero(Genero);

    cout << "Salud: ";
    cin >> Salud;
    a.setSalud(Salud);

    cin.ignore();

    size_t n;
    cout << "Cantidad de aldeanos deseados: ";
    cin >> n;
    cin.ignore();

    c.Crear_Aldeano(n,a);

    cout << "Aldeanos agregados." << endl;

}

void Menu::Eliminar()
{
    string nombre;
    cout << "Nombre del aldeano que desea eliminar: " << endl;
    cin >> nombre;
    //civilizacion.Eliminar_Aldeano(nombre);

}

void Menu::Resumen()
{
    //civilizacion.Poblacion_Total();
    cout << "Aldeanos: " << endl;
    //civilizacion.Resumen();
}

bool comparador_nombre(const Civilizacion &c1, const Civilizacion &c2)
{
    return c1.getNombre()<c2.getNombre();
}

void Menu::Ordenar_Nombre()
{
    civilizaciones.sort(comparador_nombre);
}

bool comparador_pob(Civilizacion &c1, Civilizacion &c2)
{
    return c1.Poblacion_Total()>c2.Poblacion_Total();
}


void Menu::Ordenar_Pob()
{
    civilizaciones.sort(comparador_pob);
}

bool comparador_sal(Civilizacion &c1, Civilizacion &c2)
{
    return c1.Salud_Prom() > c2.Salud_Prom();
}

void Menu::Ordenar_Salud()
{
    civilizaciones.sort(comparador_sal);
}

void Menu::Respaldar(list <Civilizacion> &civilizaciones)
{
    ofstream archivo("C:\\Users\\Gina\\Desktop\\civilizaciones.txt", ios::out);

        if (archivo.is_open())
        {
            for (auto it = civilizaciones.begin(); it != civilizaciones.end() ; ++it) {
                Civilizacion &c = *it;
                archivo << c.getNombre() << endl;
                ofstream aldeanos ("C:\\Users\\Gina\\Desktop\\"+c.getNombre()+".txt", ios::out);
                for(size_t i = 0; i < c.Poblacion_Total(); ++i)
                {
                    Aldeano &a = c[i];
                    aldeanos << a.getNombre() << endl;
                    aldeanos << a.getEdad() << endl;
                    aldeanos << a.getGenero() << endl;
                    aldeanos << a.getSalud() << endl;
                }
                aldeanos.close();
            }
            archivo.close();
        }
}

void Menu::Recuperar(list<Civilizacion> &c)
{
    ifstream archivo("C:\\Users\\Gina\\Desktop\\civilizaciones.txt", ios_base::in);

        if (archivo.is_open())
        {
            string N;
            string linea;
            int temp;

           while (!archivo.eof())
           {
               Civilizacion civ;

               getline(archivo, N);
               if (archivo.eof()) {
                   break;
               }
               civ.setNombre(N);

               ifstream aldeanos("C:\\Users\\Gina\\Desktop\\"+civ.getNombre()+".txt", ios_base::in);
               if(aldeanos.is_open())
               {
                   Aldeano a;
                    while(!aldeanos.eof())
                    {
                        getline(aldeanos, linea);
                        if (aldeanos.eof())
                        {
                            break;
                        }
                        a.setNombre(linea);

                        getline(aldeanos, linea);
                        temp = stoi(linea);
                        a.setEdad(temp);

                        getline(aldeanos, linea);
                        a.setGenero(linea);

                        getline(aldeanos, linea);
                        temp = stoi(linea);
                        a.setSalud(temp);

                        civ.Agregar_Aldeano(a);
                    }
               }
               civilizaciones.push_back(civ);
               aldeanos.close();
           }

        }
        archivo.close();
}

void Menu::agregarb(Civilizacion &c)
{

    string id;
    double combustible;
    barco *b = new barco();

    cout << "Id: " << endl;
    getline(cin, id);
    b->setId(id);

    cout << "Combustible: " << endl;
    cin >> combustible;
    cin.ignore();
    b->setCombustible(combustible);

    b->setVelocidad(0.0);
    b->setArmadura(100.0);

    c.Agregar_Barco(b);
}

void Menu::eliminarb(Civilizacion &c)
{
    int q;
    cout << "Eliminar Barco\n" << endl;
    cout << "1.- Por Id." << endl
         << "2.- Por combustible menor a:" << endl;
    cin >> q;
    cin.ignore();

    switch(q)
    {
    case 1:
    {
        c.elim_id();
        cout << "El Barco ha sido eliminado." << endl;
        system("pause");
        break;
    }
    case 2:
    {
        c.elim_comb();
        cout << "El Barco ha sido eliminado." << endl;
        system("pause");
        break;
    }
    }
}
