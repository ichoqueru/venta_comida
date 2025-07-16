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