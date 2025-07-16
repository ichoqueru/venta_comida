#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Datos cliente //
struct DatosCliente {
    string nombre;
    string ubicacion;
    string alergias;
    string restriccion;
    int cumpleDia;
    int cumpleMes;
    bool esCumpleHoy = false;
};

// Datos básicos//
struct ClienteMesa {
    string nom;
    int mesa;
};


string bebidas[20];
string platos[20];
string postres[20];
int cantB = 0, cantP = 0, cantC = 0;

DatosCliente baseClientes[100];
int totalClientes = 0;

// Prototipos //
void cargarMenu();
void registrarDatosCliente();
void pedirPedido();
bool cumpleañosHoy(const string& nombre, int d, int m);

int main() {
    int op;
    do {
        system("cls");
        cout<<"----- MENU DE OPCIONES -----\n"
            <<"1) Menu del dia\n"
            <<"2) Tipo de pedido\n"
            <<"3) Imprimir boleta (pend.)\n"
            <<"4) Datos del cliente\n"
            <<"0) Salir\n"
            <<"Elige una opcion: ";
        cin>>op;

        switch(op){
        case 1: cargarMenu(); break;
        case 2: pedirPedido(); break;
        case 4: registrarDatosCliente(); break;
        }
    } while(op!=0);

    return 0;
}

void cargarMenu(){
    int tipo, cant; string nombre;
    system("cls");
    cout<<"--- MENU DEL DIA ---\n"
        <<"1) Bebidas   2) Platos   3) Postres\n"
        <<"Tipo: "; cin>>tipo;

    cout<<"Cantidad: "; cin>>cant; cin.ignore();
    for(int i=1;i<=cant;i++){
        cout<<"Nombre "<<i<<": "; getline(cin, nombre);
        switch(tipo){
        case 1: bebidas[cantB++] = nombre; break;
        case 2: platos[cantP++] = nombre; break;
        case 3: postres[cantC++] = nombre; break;
        }
    }
    system("pause");
}

void registrarDatosCliente(){
    system("cls");
    cout<<"--- REGISTRO DE DATOS DEL CLIENTE ---\n";
    DatosCliente& dc = baseClientes[totalClientes];
    cin.ignore();
    cout<<"Nombre completo                 : "; getline(cin, dc.nombre);
    cout<<"Ubicacion preferida de la mesa   : "; getline(cin, dc.ubicacion);
    cout<<"Alergias alimentarias           : "; getline(cin, dc.alergias);
    cout<<"Restriccion dietetica           : "; getline(cin, dc.restriccion);
    cout<<"Dia de cumple (1-31)            : "; cin>>dc.cumpleDia;
    cout<<"Mes de cumple (1-12)            : "; cin>>dc.cumpleMes;
    totalClientes++;
    cout<<"\n✔ Registro guardado.\n";
    system("pause");
}

void pedirPedido(){
    int tipo, nClientes;
    system("cls");
    cout<<"--- TIPO DE PEDIDO ---\n1) Delivery  2) Para la mesa\nElige: ";
    cin>>tipo;

    if(tipo==1){
        cout<<"(Simulacion de delivery sin detalles...)\n";
        system("pause");
        return;
    }

    cout<<"Cantidad de clientes: "; cin>>nClientes;
    int dia, mes;
    cout<<"Fecha de hoy (d m): "; cin>>dia>>mes;

    for(int i=0;i<nClientes;i++){
        ClienteMesa c;
        cin.ignore();
        cout<<"\nCliente "<<i+1<<" - Nombre : "; getline(cin, c.nom);
        cout<<"Número de mesa: "; cin>>c.mesa;

        if(cumpleañosHoy(c.nom, dia, mes)){
            cout<<"🎂  ¡Feliz cumpleaños! Obtiene un postre gratis.\n";
        }
    }
    system("pause");
}

bool cumpleañosHoy(const string& nombre, int d, int m){
    for(int i=0;i<totalClientes;i++){
        if(baseClientes[i].nombre == nombre &&
           baseClientes[i].cumpleDia == d &&
           baseClientes[i].cumpleMes == m){
            baseClientes[i].esCumpleHoy = true;
            return true;
        }
    }
    return false;
}
