#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


struct cliente{
    string nom;
    int mesa;    
    float monto;
}clientes[200];

struct menu{
    string bebidas, platos, postres;
    int cantB,cantP,cantC;
};

struct delivery{
	string direct,nomd;
	int telefono,dni;
}delivery[200];

int main(){
    int op,cant,comida,pedido,cantdeli;
    string bebidas,platos,postres;
    int cantB,cantP,cantC;
    string nom;
    string direct,nomd;
    int mesa;
    int telefono,dni;
    

    do{
        system("cls");  
        cout<<"---------------"<<endl<<"MENU DE OPCIONES"<<endl<<"---------------"<<endl;
        cout<<"1. Encargado"<<endl;
        cout<<"2. Cliente"<<endl;
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
                cout<<"Ingrese la cantidad de bebidas: "; cin>>cantB;
                cin.ignore();
                for(int i=0;i<cantB;i++){
                    cout<<"Bebida "<<i+1<<": "; getline(cin,bebidas);
                }
                break;

                case 2:    //plato de fondo
                system("cls");
                cout<<"---PLATO DE FONDO---"<<endl;
                cout<<"Ingrese la cantidad de platillos: "; cin>>cantC;
                cin.ignore();
                for(int i=0;i<cantC;i++){
                    cout<<"Platillo "<<i+1<<": "; getline(cin,platos);
                }                
                break;

                case 3:  //postres
                system("cls");
                cout<<"---POSTRES---"<<endl;
                cout<<"Ingrese la cantidad de postres: "; cin>>cantP;
                cin.ignore();
                for(int i=0;i<cantP;i++){
                    cout<<"Postre "<<i<<": "; getline(cin,postres);
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
                cout<<"---DELIVERY---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>cantdeli;
                for(int i=0;i<cantdeli;i++){
                cout<<"Datos del cliente "<<i+1<<"---"<<endl;
                cin.ignore();
                cout<<"Nombre del cliente: "; getline(cin,delivery[i].nomd);
                cout<<"Direccion: "; getline(cin,delivery[i].direct);
                cout<<"Ingrese el DNI: "; cin>>delivery[i].dni;
                cout<<"Ingrese el telefono: "; cin>>delivery[i].telefono;
                cout<<"\n";
                }
                break;

                case 2:    //para la mesa
                system("cls");
                cout<<"---PARA LA MESA---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>cant;
                for(int i=0;i<cant;i++){
                    cout<<"Datos del cliente "<<i+1<<"---"<<endl;
                    cin.ignore();                    
                    cout<<"Nombre del cliente: "; getline(cin,clientes[i].nom);
                    cout<<"Numero de mesa: "; cin>>clientes[i].mesa;
                    cout<<"\n";
                }                
                break;
            
        	}
        	system("pause");
        	break;
        }    
       

    }while(op!=0);


    return 0;
}

