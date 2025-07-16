#include<iostream>
#include<string>
#include<stdlib.h>
#include"menu.h"
#include"cliente.h"
#include"pedido.h"
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
        cout<<"0. Salir"<<endl;
        cout<<"Elige un usuario: "; cin>>op;
        switch(op){
            case 1:  //encargado
            	do{
            		system("cls");  
                    cout<<"---------------"<<endl<<"ENCARGADO"<<endl<<"---------------"<<endl;
                    cout<<"---MENU DEL DIA---"<<endl;
                    cout<<"1. Bebidas"<<endl;
                    cout<<"2. Plato de fondo"<<endl;
                    cout<<"3. Postres"<<endl;
                    cout<<"0. Volver al menu principal"<<endl;
                    cout<<"Elija el tipo de comida: "; cin>>comida;
                    cout<<endl<<"------------------------------------------------------------"<<endl;
            
                    switch(comida){                    	
                        case 1:   //bebidas
                        
                        system("cls");                        
                        cout<<"---BEBIDAS---"<<endl;
                        cout<<"Ingrese la cantidad de bebidas: "; cin>>m.cantB;
                        cin.ignore();
                        for(int i=0;i<m.cantB;i++){
                            cout<<"Bebida "<<i+1<<": "; getline(cin,m.bebidas[i]);   //nombre de la bebida
                    
                            cout<<"Precio de "<<m.bebidas[i]<<": "; 
					        cin>>m.preciosBebidas[i];
					        cin.ignore();
					        cout<<"\n";
                        }
                
                        break;

                        case 2:    //plato de fondo
                        
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
			             
                		break;

                		case 3:  //postres
                		
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
                
                		break;
            		
            		}				            

                }while(comida!=0);
				break;   
                                      

            case 2:   //cliente        
            system("cls");
            cout<<"---------------"<<endl<<"CLIENTE"<<endl<<"---------------"<<endl;
            cout<<"---TIPO DE PEDIDO---"<<endl;
            cout<<"1) Delivery"<<endl;
            cout<<"2) Para la mesa"<<endl;
            cout<<"Elige el tipo de pedido: "; cin>>pedido;
            
            switch(pedido){
                case 1:  //delivery
                system("cls");               
                cout<<"\n"<<"---DELIVERY---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>f.cantdeli;
                cout<<"\n";
                cout<<"FECHA: ";
                cin>>f.d>>f.s>>f.a;
                f.opc=2;
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
                imprimeFactura(f);  //entrega la boleta
                break;

                case 2:    //para la mesa
                system("cls");
                cout<<"\n"<<"---PARA LA MESA---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>f.cant;
                cout<<"\n";
                cout<<"FECHA: ";
                cin>>f.d>>f.s>>f.a;
                f.opc=1;
                for(int i=0;i<f.cant;i++){
                    cout<<"Datos del cliente "<<i+1<<"---"<<endl;
                    cin.ignore();                    
                    cout<<"Nombre del cliente: "; getline(cin,f.mesas[i].nom);
                    cout<<"Numero de Mesa: "; cin>>f.mesas[i].mesa;
                    cout<<"\n";
                    
                    realizarPedido(m,f.mesas[i]);   //realizar el pedido
                    system("cls");
                }   
                imprimeFactura(f); //entrega la boleta
                break;
            
        	}
        	system("pause");
        	break;
        	
 
        }    

        case 4: {
                int n, diaHoy, mesHoy;
                cout << "---REGISTRO DE DATOS DEL CLIENTE---\n";
                cout << "¿Cuantos clientes desea registrar?: "; cin >> n;
                cout << "Ingrese la fecha de hoy (DD MM): "; cin >> diaHoy >> mesHoy;
                cin.ignore();
                for (int i = 0; i < n; i++) {
                    cout << "\nCliente " << i + 1 << ":\n";
                    cout << "Nombre: "; getline(cin, datos[i].nombre);
                    cout << "Direccion: "; getline(cin, datos[i].direccion);
                    cout << "Telefono: "; cin >> datos[i].telefono;
                    cout << "DNI: "; cin >> datos[i].dni;
                    cin.ignore();
                    cout << "Alergias: "; getline(cin, datos[i].alergias);
                    cout << "Restricciones dieteticas: "; getline(cin, datos[i].restricciones);
                    cout << "Fecha de cumpleaños (DD MM): "; cin >> datos[i].diaCumple >> datos[i].mesCumple;

                    if (datos[i].diaCumple == diaHoy && datos[i].mesCumple == mesHoy) {
                        cout << "¡Feliz cumpleaños " << datos[i].nombre << "! Recibes un postre GRATIS. \n";
                    }
                }
                system("pause");
                break;
            }

            case 0:
                cout << "Gracias por usar el sistema.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
                system("pause");
                break;
        }
       

    }while(op!=0);


    return 0;
}





