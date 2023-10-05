#include <iostream>
#include "Cola.h"

using namespace std;

int main(){
	
	Cola MiCola;
    Constancia x;
    
    int opcion = 0, resultado;
    
    while(opcion != 5){
    	cout<<"1- Dar de alta alumno (enqueue)"<<endl;
    	cout<<"2- Elaborar constancia (dequeue)"<<endl;
    	cout<<"3- Buscar Constancia"<<endl;
    	cout<<"4- Busqueda Binaria"<<endl;
    	cout<<"5- Salir"<<endl;
    	cout<<"Opcion: ";
    	cin>>opcion;
    	
    	switch(opcion){
    		case 1:
    			cin>>x;
    			MiCola.enqueue(x);
    			break;
    		case 2:
    			if(MiCola.vacia()){
    				cout<<"La Cola esta vacia"<<endl;
				}else
    				cout<<MiCola.dequeue()<<endl;
    			break;
    		case 3:
    			cout<<"Ingrese los datos de la constancia a buscar:"<<endl;
    			cin>>x;
    			resultado = MiCola.busquedaLineal(x);
    			if(resultado == -1){
    				cout<<"No se encontro la constancia"<<endl;
				}else
					cout<<"Posicion: "<<resultado<<endl;
				break;
    		case 4:
    			cout<<"Ingrese los datos de la constancia a buscar:"<<endl;
    			cin>>x;
    			resultado = MiCola.busquedaBinaria(x);
    			if(resultado == -1){
    				cout<<"No se encontro la constancia"<<endl;
				}else
					cout<<"Posicion: "<<resultado<<endl;
    			break;
    		case 5:
    			cout<<"Saliendo..."<<endl;
    			break;
    		default:
    			cout<<"Seleccione una opcion correcta.."<<endl;
    			break;
		}
	}
	
	return 0;
}
