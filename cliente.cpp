#include<iostream>
#include<string>
#include<stdlib.h>
#include"menu.h"
#include"cliente.h"
using namespace std;

void realizarPedido(menu &m, cliente &c){
	int opn,cantidad,item;
	do{
		system("cls");
		imprimeMenu(m);  //muetsra el menu al cliente
		cout<<"\n-----------------------------------------------------------------"<<endl;
		cout<<"1. Agregar bebida"<<endl;
		cout<<"2. Agregar plato"<<endl;
		cout<<"3. Agregar postre"<<endl;
		cout<<"4. Finalizar pedido"<<endl;
		cout<<"Seleccione opcion: "; cin>>opn;
		
		switch(opn){
			case 1: //bebidas
			    if(m.cantB>0){
				     cout<<"Seleccione bebida (1-"<<m.cantB<<"): ";
				     cin>>item;
				     cout<<"Cantidad a pedir: ";
				     cin>>cantidad;
				
				    c.pedidos[c.cantPedidos].tipo="bebida";
				    c.pedidos[c.cantPedidos].nombre=m.bebidas[item-1];
				    c.pedidos[c.cantPedidos].precio=m.preciosBebidas[item-1];
				    c.pedidos[c.cantPedidos].cantidad=cantidad;
				    c.cantPedidos++;
			    }
			system("pause");
			break;
			
			case 2:    //platos
				if(m.cantC>0){
				     cout<<"Seleccione platillo (1-"<<m.cantC<<"): ";
				     cin>>item;
				     cout<<"Cantidad a pedir: ";
				     cin>>cantidad;
				
				    c.pedidos[c.cantPedidos].tipo="plato";
				    c.pedidos[c.cantPedidos].nombre=m.platos[item-1];
				    c.pedidos[c.cantPedidos].precio=m.preciosPlatos[item-1];
				    c.pedidos[c.cantPedidos].cantidad=cantidad;				    
				    c.cantPedidos++;
			    }
				system("pause");
				break;
				
			case 3:    //postres
				if(m.cantP>0){
				     cout<<"Seleccione postre (1-"<<m.cantP<<"): ";
				     cin>>item;
				     cout<<"Cantidad a pedir: ";
				     cin>>cantidad;
				
				    c.pedidos[c.cantPedidos].tipo="postre";
				    c.pedidos[c.cantPedidos].nombre=m.postres[item-1];
				    c.pedidos[c.cantPedidos].precio=m.preciosPostres[item-1];
				    c.pedidos[c.cantPedidos].cantidad=cantidad;
				    c.cantPedidos++;
			    }
				system("pause");
				break;
					
			case 4: //calcular el total y finaliza el pedido 
				for(int i=0;i<c.cantPedidos;i++){
			            c.monto+=c.pedidos[i].precio*c.pedidos[i].cantidad;
		        }		        
		        
		    break;
		}
		
	}while(opn!=4);	

}


void imprimeFactura(factura &f){
	system("cls");
	cout<<"----------------"<<endl<<"BOLETA"<<endl<<"----------------"<<endl;
	cout<<"\n";
	
	if(f.opc==1){
		cout<<"FECHA: "<<f.d<<"/"<<f.s<<"/"<<f.a<<endl;
	       for(int i=0;i<f.cant;i++){           	           
              cout<<"Nombre del cliente: "<<f.mesas[i].nom<<endl;
              cout<<"Mesa: "<<f.mesas[i].mesa<<endl;      
			
			  cout<<"\n---PEDIDOS---"<<endl;  //muestra el pedido
              for(int j=0; j<f.mesas[i].cantPedidos; j++){
                cout<<f.mesas[i].pedidos[j].cantidad<<" x "<<f.mesas[i].pedidos[j].nombre;
                cout<<" (S/."<<f.mesas[i].pedidos[j].precio<<") = ";
                cout<<"S/."<<f.mesas[i].pedidos[j].precio * f.mesas[i].pedidos[j].cantidad<<endl;
              }
              cout<<"TOTAL: S/."<<f.mesas[i].monto<<endl;
              cout<<"\n";  
              cout<<"----------------------------------------------------------------"<<endl;
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
				
			    cout<<"\n---PEDIDO---"<<endl;   //muestra el pedido
                for(int j=0; j<f.mesas[i].cantPedidos; j++){
                   cout<<f.mesas[i].pedidos[j].cantidad<<" x "<<f.mesas[i].pedidos[j].nombre;
                   cout<<" (S/."<<f.mesas[i].pedidos[j].precio<<") = ";
                   cout<<"S/."<<f.mesas[i].pedidos[j].precio * f.mesas[i].pedidos[j].cantidad<<endl;
                }
                cout<<"TOTAL: S/."<<f.mesas[i].monto<<endl;
                cout<<"\n";		
                cout<<"----------------------------------------------------------------"<<endl;
	        } 
         }
    }
}
