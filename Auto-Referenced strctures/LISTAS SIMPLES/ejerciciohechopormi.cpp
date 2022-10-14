/*

un ejercicio completo creado por mi

*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
struct node{
	int data; 
	struct node *next; 
};
int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	struct node *head=NULL;
	struct node *temp=NULL; 
	struct node *newnode=NULL; 
	int suma=0,opt1,opt2,i=0; 
	char cont;
do{	
	cout<<"INGRESE:\n1:crear nodo\n2:imprimir\n3:suma de datos\n4:multiplos de 5\n5:Borrar un nodo"<<endl; 
	cin>>opt1; 
	switch (opt1)
	{
		case 1: //construccion de datos
			
			cout<<"INGRESE:\n1:Ingresar nodo al final\n2:Ingresar nodo al principio"<<endl; 
			cin>>opt2; 
			switch (opt2)
			{
			case 1://nodo al final
				newnode=(struct node*)malloc(sizeof(struct node));
				newnode->data=rand()%11; 
				newnode->next=NULL; 
				if(head==NULL)
				{
					head=newnode; 
				}else{
					temp=head; 
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=newnode; 
				}
				break; 
			case 2://insercion nodo al princpio
				newnode=(struct node*)malloc(sizeof(struct node));
				newnode->data=rand()%11; 
				newnode->next=NULL; 
				if(head==NULL)
				{
					head=newnode; 
				}else{
					
					temp=newnode; 
					temp->next=head; 
					head=temp; 
				}
				break; 
			}
		break; 
			
		case 2://impresion de datos
			cout<<"\n***IMPRESION LISTA***"<<endl; 
			temp=head; 
			while(temp!=NULL)
			{
				cout<<"\t "<<temp->data; 
				temp=temp->next; 
			}
			free (temp);
		break; 
		case 3: //suma de datos
			while(temp!=NULL)
			{
				suma+=temp->data;
				temp=temp->next; 
			}
			free (temp);
			cout<<"\n***LA SUMA DE LOS VALORES ES "<<suma<<"***"<<endl;
		break; 
		case 4://impresion multiplos de 5
			cout<<"\n***IMPRESION MULTIPLOS DE 5***"<<endl; 
			while(temp!=NULL)
			{
				if(((temp->data)%5)==0)
				{
					cout<<"\t "<<temp->data; 
				}
				temp=temp->next; 
				
			}
			free (temp);
		break; 
		case 5://borado de nodos
			cout<<"INGRESE:\n1:Borrar primer nodo\n2:Borrar el último nodo"<<endl; 
			cin>>opt2; 
			switch (opt2)
			{
			case 1://borrado primer nodo
				temp=head; 
				head=head->next; 
				free (temp);
				break; 
			case 2://borrado último nodo 
				temp=head;
				newnode=temp;
				while(temp->next!=NULL)
				{
					if (i==1)
					{
						newnode=head;
					}
					if (i>=1)
					{
						newnode=newnode->next; 
					}
					temp=temp->next;
					i++;
				}
				newnode->next=NULL; 
				free(temp);
				break; 
			}
		break; 
		default:
			cout<<"\ningresó mal la opcion"<<endl; 
			break; 
	}
	cout<<"\ncont"<<endl; 
	cin>>cont; 
}while(cont=='s'||cont=='S');
	return 0;
}

