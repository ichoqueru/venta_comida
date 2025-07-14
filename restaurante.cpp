#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct cliente{
    string direc,nom;
    int telefono,mesa,dni;    
    float monto;
};

struct menu{
    string bebidas, platos, postres;
};

int main(){
    int op,cant,comida,cantB,cantP,cantC,pedido,cantdeli;
    string bebidas, platos, postres;
    string direc,nom;
    int telefono,mesa,dni;    

    do{
        system("cls");
        cout<<"-----MENU DE OPCIONES-----"<<endl;
        cout<<"1) Menu del dia"<<endl;        
        cout<<"2) Tipo de pedido"<<endl;
        cout<<"Elige una opcion: "; cin>>op;

        switch(op){
            case 1:
            system("cls");
            cout<<"---MENU DEL DIA---"<<endl;
            cout<<"1) Bebida"<<endl;
            cout<<"2) Plato de fondo"<<endl;
            cout<<"3) Postre"<<endl;
            cout<<"Eliga el tipo de comida: "<<comida<<endl;
            switch(comida){
                case 1: 
                cout<<"---Bebidas---"<<endl;
                cout<<"Ingrese la cantidad de bebidas: "; cin>>cantB;
                cin.ignore();
                for(int i=1;i<=cantB;i++){
                    cout<<"Bebida "<<i<<": "; getline(cin,bebidas);
                }
                system("pause");
                break;

                case 2: 
                cout<<"---Plato de fondo---"<<endl;
                cout<<"Ingrese la cantidad de platillos: "; cin>>cantC;
                cin.ignore();
                for(int i=1;i<=cantC;i++){
                    cout<<"Platillo "<<i<<": "; getline(cin,platos);
                }
                system("pause");
                break;

                case 3:
                cout<<"Ingrese la cantidad de postres: "; cin>>cantP;
                cin.ignore();
                for(int i=1;i<=cantP;i++){
                    cout<<"Postre "<<i<<": "; getline(cin,postres);
                }
                system("pause");
                break;

            }
            system("pause");
            break;

            case 2:
            cout<<"---TIPO DE PEDIDO---"<<endl;
            cout<<"1) Delivery"<<endl;
            cout<<"2) Para la mesa"<<endl;
            cout<<"Eliga el tipo de pedido: "; cin>>pedido;

            switch(pedido){
                case 1:
                cout<<"---DELIVERY---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>cantdeli;
                for(int i=0;i<cant;i++){
                cout<<"Datos del cliente"<<i<<"---"<<endl;
                cin.ignore();
                cout<<"Nombre del cliente: "; getline(cin,nom);
                cout<<"Direccion: "; getline(cin,direc);
                cout<<"Ingrese el DNI: "; cin>>dni;
                cout<<"Ingrese el telefono: "; cin>>telefono;
                }
                system("pause");
                break;

                case 2: 
                cout<<"---PARA LA MESA---"<<endl;
                cout<<"Cantidad de clientes: "; cin>>cant;
                for(int i=0;i<cant;i++){
                    cout<<"Datos del cliente "<<i<<"---"<<endl;
                    cin.ignore();                    
                    cout<<"Nombre del cliente: "; getline(cin,nom);
                    cout<<"Numero de mesa: "; cin>>mesa;
                }                
                system("pause");
                break;
            }

        }


    }while(op!=0);

    return 0;
}
