#include<iostream>
#include<string>
#include"menu.h"
using namespace std;

void imprimeMenu(menu &m){
	cout<<"----------------"<<endl<<"Carta del dia"<<endl<<"----------------"<<endl;
	
	if(m.cantB>0){
		cout<<"---BEBIDAS---"<<endl;
    	for(int i=0;i<m.cantB;i++){
    	   cout<<"Bebida "<<i+1<<": "<<m.bebidas[i]<<" - S/."<<m.preciosBebidas[i]<<endl;
		}
    }
    
    if(m.cantC>0){
    	cout<<"\n---PLATO DE FONDO---"<<endl;
        for(int i=0;i<m.cantC;i++){
            cout<<"Platillo "<<i+1<<": "<<m.platos[i]<<" - S/."<<m.preciosPlatos[i]<<endl;
        }          
    }
    
    if(m.cantP>0){
    	cout<<"\n---POSTRES---"<<endl;
        for(int i=0;i<m.cantP;i++){
            cout<<"Postres "<<i+1<<": "<<m.postres[i]<<" - S/."<<m.preciosPostres[i]<<endl;
        }          
    }
        
}

void registrarBebidas(menu &m){
    system("cls");
    cout<<"---BEBIDAS---"<<endl;
    cout<<"Ingrese la cantidad de bebidas: ";
    cin>>m.cantB;
    cin.ignore();

    for(int i=0;i<m.cantB;i++){
        cout<<"Bebida "<<i+1<<": ";
        getline(cin, m.bebidas[i]);

        cout<<"Precio de "<<m.bebidas[i]<<": ";
        cin>>m.preciosBebidas[i];
        cin.ignore();
        cout<<"\n";
    }
}

void registrarPlatos(menu &m){
    system("cls");
    cout<<"---PLATO DE FONDO---"<<endl;
    cout<<"Ingrese la cantidad de platillos: "; cin>>m.cantC;
    cin.ignore();
    for(int i=0;i<m.cantC;i++){
        cout<<"Platillo "<<i+1<<": "; getline(cin,m.platos[i]);   //nombre del platillo
                    
        cout<<"Precio de "<<m.platos[i]<<": ";
        cin>>m.preciosPlatos[i];
        cin.ignore();
        cout<<"\n";               
                   
    }
}

void registrarPostres(menu &m){
    system("cls");
    cout<<"---POSTRES---"<<endl;
    cout<<"Ingrese la cantidad de postres: "; cin>>m.cantP;
    cin.ignore();
    for(int i=0;i<m.cantP;i++){
        cout<<"Postre "<<i+1<<": "; getline(cin,m.postres[i]);   //nombre del postre
                    
        cout<<"Precio de "<<m.postres[i]<<": ";
        cin>>m.preciosPostres[i];
        cin.ignore();
        cout<<"\n";                    
    }
}
