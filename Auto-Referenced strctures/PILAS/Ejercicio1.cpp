# include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
	int info;
	struct node *ptr; 
};
int main()
{
	struct node *head=NULL; 
	struct node *temp=NULL; 
	struct node *newnode=NULL;
	int numero=0,opt=0,i=0,suma=0; 
	char cont=' '; 
	do{
		cout<<"\nQUEDAN DISPONIBLES "<<5-i<<" NODOS"<<endl; 
		cout<<"INGRESE:\n1:Cargar nodo\n2:Borrar el ultimo nodo de la pila\n3:Imprimir pila\n4:Sumar valores de la pila"<<endl;
		cin>>opt; 
		switch (opt)
		{
		case 1: //carga de nodos y datos.
			if (i<5)
			{
				i++; 
				newnode=(struct node*)malloc(sizeof(struct node)); 
				if (newnode==NULL)
				{
					cout<<"no hay memoria suficiente"<<endl; 
					exit (1);
				}
				cout<<"\nIngresar dato"<<endl; 
				cin>>numero; 
				newnode->info=numero;//acá cargo el dato a la estructura nueva.
				newnode->ptr=head;//asigno el puntero a head.
				head=newnode; //apunto head al nuevo nodo.
				//hasta acá sería la carga de la información y de los nodos o push
			}else{
				cout<<"ya se han cargado los 5 nodos"<<endl; //asi me lo pide el ejercicio
			}
			break; 
			
			
		case 2://eliminar el último de la pila
			if (head!=NULL)//es para ver que la pila no esté vacía 
			{
				temp=head; 
				head=head->ptr; //aca no pierdo la referencia del head. 
				free(temp);
				i--;
			}else{
				cout<<"pila vacia"<<endl; 
			}           
			//hasta aca sería la operación de eliminar nodos o pop
			break; 
			
		case 3://imprimir pila
			temp=head;
			while (temp!=NULL)
			{
				cout<<"Dato: "<<temp->info;
				temp=temp->ptr; 
				cout<<"\n";
			}
			//impresión de datos
			break; 
			
			
		case 4: //sumar los valores de la pila
			temp=head;
			while (temp!=NULL)
			{
				suma+=temp->info;
				temp=temp->ptr; 
			}
			cout<<"\nLa suma es "<<suma<<endl; 
			break; 
			
		default:
			cout<<"ingreso mal la opcion del menu"<<endl;
			break;
		}
		cout<<"\nPara continuar presione s";
		cin>>cont;
	}while(cont=='s');
	
	return 0;
}

