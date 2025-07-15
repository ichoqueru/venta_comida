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

const int MAX_ITEMS = 30;
string bebidas[MAX_ITEMS] = {"Agua mineral", "Gaseosa", "Jugo"};
float preciosBebidas[MAX_ITEMS] = {2.50, 3.00, 4.00};

string platos[MAX_ITEMS] = {"Arroz con pollo", "Lomo saltado", "Tallarines rojos"};
float preciosPlatos[MAX_ITEMS] = {12.50, 15.00, 11.00};

string postres[MAX_ITEMS] = {"Gelatina", "Flan", "Helado"};
float preciosPostres[MAX_ITEMS] = {2.00, 3.50, 4.50};

int main(){
    int op,cant,comida,pedido,cantdeli;
    string bebidas,platos,postres;
    int cantB,cantP,cantC;
    string nom;
    string direct,nomd;
    int mesa;
    int telefono,dni;
    int tipoPedido = 0, nroPedido = 1;
    cliente c;
    menu m;
    time_t t = time(0);
    tm* now = localtime(&t);

    do{
        system("cls");  
        cout<<"---------------"<<endl<<"MENU DE OPCIONES"<<endl<<"---------------"<<endl;
        cout<<"1. Encargado"<<endl;
        cout<<"2. Cliente"<<endl;
        cout<<"3. Imprimir factura"<<endl;
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
                do
                {
                 while (condition);
                ("cls");
                cout<<"---BEBIDAS---"<<endl;
                for (int i = 0; i < totalBebidas; i++) {
                cout << i + 1 << ") " << bebidas[i] << " - S/ " << fixed << setprecision(2) << preciosBebidas[i] << endl;
                }
                cout << "Seleccione una bebida (1-" << totalBebidas << "): ";
                cin >> seleccion;

                if (seleccion < 1 || seleccion > totalBebidas) {
                cout << "Opción inválida.\n";
                continue;
                }
                cout << "Cantidad: ";
                cin >> cantidad;

                m.bebidas += to_string(cantidad) + "x " + bebidas[seleccion - 1] + "\n";
                c.monto += preciosBebidas[seleccion - 1] * cantidad;

                cout << "\nDesea agregar otra bebida? (1=Si, 0=No): ";
                cin >> seleccion;

                } while (seleccion == 1);
                break;

                case 2:    //plato de fondo
                do {
                    system("cls");
                cout<<"---PLATO DE FONDO---"<<endl;
                    for (int i = 0; i < totalPlatos; i++) {
                    cout << i + 1 << ") " << platos[i] << " - S/ " << fixed << setprecision(2) << preciosPlatos[i] << endl;
                    }
                    cout << "Seleccione un plato (1-" << totalPlatos << "): ";
                    cin >> seleccion;

                    if (seleccion < 1 || seleccion > totalPlatos) {
                    cout << "Opción inválida.\n";
                    continue;
                    }

                    cout << "Cantidad: ";
                    cin >> cantidad;

                    m.platos += to_string(cantidad) + "x " + platos[seleccion - 1] + "\n";
                    c.monto += preciosPlatos[seleccion - 1] * cantidad;

                    cout << "\nDesea agregar otro plato? (1=Si, 0=No): ";
                    cin >> seleccion;

                    }while (seleccion == 1);
                    break;

                case 3:  //postres
                system("cls");
                cout<<"---POSTRES---"<<endl;
                for (int i = 0; i < totalPostres; i++) {
                cout << i + 1 << ") " << postres[i] << " - S/ " << fixed << setprecision(2) << preciosPostres[i] << endl;
                }
                cout << "Seleccione un postre (1-" << totalPostres << "): ";
                cin >> seleccion;

                if (seleccion < 1 || seleccion > totalPostres) {
                cout << "Opción inválida.\n";
                continue;
                }

                cout << "Cantidad: ";
                cin >> cantidad;

                m.postres += to_string(cantidad) + "x " + postres[seleccion - 1] + "\n";
                c.monto += preciosPostres[seleccion - 1] * cantidad;

                cout << "\nDesea agregar otro postre? (1=Si, 0=No): ";
                cin >> seleccion;

            } while (seleccion == 1);
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

                case 3:
                system("cls");
                cout << "------- FACTURA -------" << endl;
                cout << "Fecha: " << (now->tm_mday) << "/" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900) << endl;
                cout << "Numero de pedido: " << nroPedido++ << endl;
                cout << "Cliente: " << c.nom << endl;
                if (tipoPedido == 1) {
                    cout << "Direccion: " << c.direc << endl;
                    cout << "DNI: " << c.dni << endl;
                    cout << "Telefono: " << c.telefono << endl;
                } else if (tipoPedido == 2) {
                    cout << "Mesa Nro: " << c.mesa << endl;
                }
                cout << "\nBebidas:\n" << m.bebidas;
                cout << "Platos:\n" << m.platos;
                cout << "Postres:\n" << m.postres;
                cout << "\nTOTAL: S/." << fixed << setprecision(2) << c.monto << endl;
                system("pause");
                break;
            
        	}
        	system("pause");
        	break;    

    }while(op!=0);


    return 0;
}

