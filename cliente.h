#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
#include<string>
#include"menu.h"
using namespace std;

struct pedido{
	string tipo;
	string nombre;
	float precio;
	int cantidad;
};

struct cliente{
    string nom;
    int mesa;    
    float monto;
    int cantPedidos;
    struct pedido pedidos[20];
};


struct info_delivery{
	string direct,nomd;
	int telefono,dni;
};

struct factura{
	int d,s,a,opc,cantdeli,cant;
	info_delivery entregas[200];
	cliente mesas[200];
};

void imprimeFactura(factura &);
void realizarPedido(menu &, cliente &);


#endif