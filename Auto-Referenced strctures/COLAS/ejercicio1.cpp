/*
Crear un programa con el siguiente menu de opciones: 

Agregar un nodo a la cola. (se deben agregar 5 valores)
Borrar el primer nodo de la cola.
Imprimir cola.
Suma de los valores de la cola.


*/

#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next; 
};
int main(int argc, char *argv[])
{
	struct node *front=NULL;
	struct node *newnode=NULL;
	struct node	*back=NULL; 
	struct node *temp=NULL;
	int opt=0, valor=0;  
	char cont=' '; 
	do{
		cout<<"INGRESE:\n1:Cargar nodo\n2:Borrar el primer nodo de la cola\n3:Imprimir cola\n4: Sumar elementos de la cola"<<endl;
		cin>>opt; 
		
		switch (opt)
		{
		case 1://cargar nodo
			cout<<"ingrese el valor deseado"<<endl;
			cin>>valor; 
			newnode=(struct node*)malloc(sizeof(struct node));
			if (newnode==NULL)
			{
				cout<<"no hay memoria suficiente"<<endl; 
				exit (1);
			}else{
				newnode->data=valor; 
				newnode->next=NULL;//APUNTO EL PUNTERO DEL NODO A NULL 
				if (back==NULL)//si no existe ningun nodo creado
				{
					back=newnode; 
					front=back; 
				}else{
					back->next=newnode; 
					back=newnode; 
				}
			}
			break; 
		case 2: //elminar front
				if((front==back)&&(back==NULL))
				{
					cout<<"la cola está vacía"<<endl;
				}
				temp=front;
				front = front->next;
				if(front==NULL){
					back=NULL;
				}
				free(temp);
			break;
		case 3://impresion
			temp=front;
			while(temp!=NULL){
				cout<<"\n dato "<<temp->data;
				temp=temp->next;
			}
			free(temp);
			break;
		case 4://sumatoria
			temp=front;
			while(temp!=NULL){
				sum+=temp->data;
				temp=temp->next;
			}
			free(temp);
			cout<<"\nla suma es "<<sum;
			break; 
		}
		cout<<"\ncont s"<<endl; 
		cin>>cont;
	}while(cont=='s');
	
	return 0;
}

