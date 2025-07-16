#include<iostream>
#include<string>
#include<stdlib.h>
#include"menu.h"
#include"cliente.h"
using namespace std;



int main(){
    int op,comida,pedido,eleccion;
    string bebidas[10];
    float preciosBebidas[10];
	string platos[10];
	float preciosPlatos[10];
	string postres[10];
	float preciosPostres[10];
    int cantB,cantP,cantC;
    string nom;
    string direct,nomd;
    int mesa;
    int telefono,dni;
    menu m;
    int d,s,a,opc,cant,cantdeli;
    factura f;
    cliente c;
    string tipo;
	string nombre;
	float precio;
	int cantidad;
    struct cliente mesas[200];
    struct info_delivery entregas[200];

    do{
        system("cls");  
        cout<<"---------------"<<endl<<"MENU DE OPCIONES"<<endl<<"---------------"<<endl;
        cout<<"1. Encargado"<<endl;
        cout<<"2. Cliente"<<endl;
        cout<<"3. Imprimir boleta"<<endl;
        cout<<"Eliga un usuario: "; cin>>op;
        switch(op){
            case 1:
            system("cls");  //encargado
            cout<<"---------------"<<endl<<"ENCARGADO"<<endl<<"---------------"<<endl;
            cout<<"---MENU DEL DIA---"<<endl;
            cout<<"1. Bebidas"<<endl;
            cout<<"2. Plato de fondo"<<endl;
            cout<<"3. Postres"<<endl;
            cout<<"Eliga el tipo de comida: "; cin>>comida;
            
            switch(comida){
                case 1:   //bebidas
                registrarBebidas(m);
                break;

                case 2:    //plato de fondo
                registrarPlatos(m);       
                break;

                case 3:  //postres
                registrarPostres(m);
                break;

            }                        
            system("pause");
            break;

            case 2:   //cliente        
            system("cls");
            cout<<"---------------"<<endl<<"CLIENTE"<<endl<<"---------------"<<endl;
            cout<<"---TIPO DE PEDIDO---"<<endl;
            cout<<"1) Delivery"<<endl;
            cout<<"2) Para la mesa"<<endl;
            cout<<"Eliga el tipo de pedido: "; cin>>pedido;
            
            switch(pedido){
                case 1:  //delivery
                system("cls");               
                cout<<"\n"<<"---DELIVERY---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>f.cantdeli;
                cout<<"\n";
                cout<<"FECHA: ";
                cin>>f.d>>f.s>>f.a;
                for(int i=0;i<f.cantdeli;i++){
                cout<<"Datos del cliente "<<i+1<<"---"<<endl;                
                cin.ignore();
                cout<<"Nombre del cliente: "; getline(cin,f.entregas[i].nomd);
                cout<<"Direccion: "; getline(cin,f.entregas[i].direct);
                cout<<"Ingrese el DNI: "; cin>>f.entregas[i].dni;
                cout<<"Ingrese el telefono: "; cin>>f.entregas[i].telefono;
                cout<<"\n";
                
                realizarPedido(m,f.mesas[i]); //realizar el pedido
                }
                break;

                case 2:    //para la mesa
                system("cls");
                cout<<"\n"<<"---PARA LA MESA---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>f.cant;
                cout<<"\n";
                cout<<"FECHA: ";
                cin>>f.d>>f.s>>f.a;
                for(int i=0;i<f.cant;i++){
                    cout<<"Datos del cliente "<<i+1<<"---"<<endl;
                    cin.ignore();                    
                    cout<<"Nombre del cliente: "; getline(cin,f.mesas[i].nom);
                    cout<<"Numero de Mesa: "; cin>>f.mesas[i].mesa;
                    cout<<"\n";
                    
                    realizarPedido(m,f.mesas[i]);   //realizar el pedido
                }   
                break;
            
        	}
        	system("pause");
        	break;
        	
        	case 3:
        		system("cls");
        		cout<<"\n---Desea imprimir la boleta?---"<<endl;
				cout<<"1. si"<<endl;
				cout<<"2. no"<<endl;
				cout<<"Eliga una opcion: "; cin>>eleccion;
				switch(eleccion){
					case 1:
						system("cls");
						cout<<"----------------"<<endl<<"BOLETA"<<endl<<"----------------"<<endl;
						cout<<"1. Para la mesa"<<endl;
						cout<<"2. Delivery"<<endl;
						cout<<"Eliga el tipo de boleta: "; cin>>f.opc;
						cout<<"\n";
						imprimeFactura(f);
						system("pause");
						break;
					
					case 2:




						break;
						
					default:
						cout<<"Opcion no valida"<<endl;
						system("pause");
						break;
				
				}	 
				system("pause");       
        		break;
        }    
       

    }while(op!=0);


    return 0;
}






