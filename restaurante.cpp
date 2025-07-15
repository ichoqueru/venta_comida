#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


struct cliente{
    string nom;
    int mesa;    
    float monto;
}mesas[200];

struct menu{
    string bebidas[10];
    float preciosBebidas[10];
	string platos[10];
	float preciosPlatos[10];
	string postres[10];
	float preciosPostres[10];
    int cantB,cantP,cantC;
};

struct info_delivery{
	string direct,nomd;
	int telefono,dni;
}entregas[200];

struct factura{
	int d,s,a,opc,cantdeli,cant;
	struct info_delivery entregas[200];
	struct cliente mesas[200];
};

void imprimeMenu(menu &);
void imprimeFactura(factura &);

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
                imprimeMenu(m);    //muestra el menu al cliente
                cout<<"\n-----------------------------------------------------------------"<<endl;
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
                }
                break;

                case 2:    //para la mesa
                system("cls");
                imprimeMenu(m);    //muestra el menu al cliente
                cout<<"\n-----------------------------------------------------------------"<<endl;
                cout<<"\n"<<"---PARA LA MESA---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>f.cant;
                cout<<"\n";
                cout<<"FECHA: ";
                cin>>f.d>>f.s>>f.a;
                for(int i=0;i<f.cant;i++){
                    cout<<"Datos del cliente "<<i+1<<"---"<<endl;
                    cin.ignore();                    
                    cout<<"Nombre del cliente: "; getline(cin,f.mesas[i].nom);
                    cout<<"Numero de mesa: "; cin>>f.mesas[i].mesa;
                    cout<<"\n";
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
				cout<<"Eliga una opccion: "; cin>>eleccion;
				switch(eleccion){
					case 1:
						system("cls");
						cout<<"----------------"<<endl<<"BOLETA"<<endl<<"----------------"<<endl;
						cout<<"1. Para la mesa"<<endl;
						cout<<"2. Delivery"<<endl;
						cout<<"Eliga el tipo de factura: "; cin>>f.opc;
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

void imprimeFactura(factura &f){
	
	if(f.opc==1){
		cout<<"FECHA: "<<f.d<<"/"<<f.s<<"/"<<f.a<<endl;
	       for(int i=0;i<f.cant;i++){           	           
              cout<<"Nombre del cliente: "<<f.mesas[i].nom<<endl;
              cout<<"Numero de mesa: "<<f.mesas[i].mesa<<endl;
              cout<<"\n";        
           }		
	}
	else{
	     if(f.opc==2){
         cout<<"FECHA: "<<f.d<<"/"<<f.s<<"/"<<f.a<<endl;
            for(int i=0;i<f.cantdeli;i++){
                cout<<"Nombre del cliente: "<<f.entregas[i].nomd<<endl;
                cout<<"Direccion: "<<f.entregas[i].direct<<endl;
                cout<<"Ingrese el DNI: "<<f.entregas[i].dni<<endl;
                cout<<"Ingrese el telefono: "<<f.entregas[i].telefono<<endl;
                cout<<"\n";			
	        } 
         }
    }
}
