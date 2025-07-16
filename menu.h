#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<string>
using namespace std;

struct menu{
    string bebidas[10];
    float preciosBebidas[10];
	string platos[10];
	float preciosPlatos[10];
	string postres[10];
	float preciosPostres[10];
    int cantB,cantP,cantC;
};

void imprimeMenu(menu &);

#endif