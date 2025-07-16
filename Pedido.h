#ifndef  Pedido_h
#define Pedido_h
#include<iostream>
#include<string>
using namespace std;

struct ClienteMesa {          
    string nom;
    int    mesa;
};

struct DatosCliente {         
    string nombre;
    string ubicacion;
    string alergias;
    string restriccion;
    int    cumpleDia;
    int    cumpleMes;
    bool   esCumpleHoy = false;
};




void cargarMenu();
void registrarDatosCliente();             
void pedirPedido();
bool cumpleañosHoy(const string& nombre, int d, int m); 

#endif