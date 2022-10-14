/*
Elaborar un sistema de stock, en la cual posee una pila de productos con los siguientes atributos: 
codigo, nombre, cantidad, precio lista. 
Desarrollar las siguientes funciones:

Agregar un nuevo producto.
Borrar el último nodo de la pila.
Mostrar el stock. 
Descontar stock.
Reponer stock.
*/
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
struct data{
	int codigo;
	string nombre;
	int cantidad;
	int precio; 
};
struct node
{
	struct data market;
	struct node *ptr;
};
int main(int argc, char *argv[]) 
{
	struct node *newnode=NULL; 
	struct node *temporary=NULL; 
	struct node *head=NULL; 
	int opt=0, i=0; 
	char cont=' ';
	do{
		cout<<"INGRESE:\n1:Cargar producto\n2:Borrar el ultimo nodo de la pila\n3:Mostrar el stock\n4:Descontar stock\n5:Reponer stock"<<endl;
		cin>>opt; 
		switch (opt)
		{
		case 1:
			newnode=(struct node*)malloc(sizeof(struct node));
			cout<<"ingrese el codigo del prudcto"<<endl; 
			cin>>newnode->market.codigo;
			cout<<"ingrese el nombre del prudcto"<<endl; 
			getline(cin,newnode->market.nombre,'.');
			cout<<"ingrese la cantidad del prudcto"<<endl; 
			cin>>newnode->market.cantidad;
			cout<<"ingrese el precio del prudcto"<<endl; 
			cin>>newnode->market.precio;
			newnode->ptr=head; 
			head=newnode;
			break; 
		case 2:
			temporary=head;
			head=head->ptr; 
			free(temporary);
			break; 
		case 3:
			temporary=head;
			while(temporary!=NULL)
			{
				cout<<"\n***Producto***"<<endl; 
				cout<<"\nCodigo del producto\n "<<temporary->market.codigo; 
				cout<<"\nNombre del producto "<<temporary->market.nombre; 
				cout<<"\nCantidad del producto\n "<<temporary->market.cantidad; 
				cout<<"\nPrecio del producto\n "<<temporary->market.precio;
				temporary=temporary->ptr;
			}
		case 4://descontar stock
			cout<<"\ningrese el número:";
			temporary=head;
			i=0;
			while(temporary!=NULL)
			{
				cout<<"\n-> "<<i<<" para "<<temporary->market.nombre<<endl; 
				temporary=temporary->ptr;
			}
			break; 
		default: 
			cout<<"se eligió mal la opción"<<endl; 
			break;
		}
		cout<<"\n[S/N]";
		cin>>cont;
	}while(cont=='s');
	return 0;
}

