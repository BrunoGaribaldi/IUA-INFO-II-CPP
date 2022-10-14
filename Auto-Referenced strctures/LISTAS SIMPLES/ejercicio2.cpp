/*
rear un programa en la cual se solicite al usuario el ingreso de 5 valores numericos. 
Luego muestre la lista y calcule el promedio de ellos
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
	struct node *head=NULL;
	struct node *temp=NULL; 
	struct node *newnode=NULL; 
	int suma=0; 
	for (int ii=0;ii<5;ii++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		cout<<endl<<"ingrese un valor"<<endl; 
		cin>>newnode->data; 
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
	}

	cout<<"\n***IMPRESION LISTA***"<<endl; 
	temp=head; 
	while(temp!=NULL)
	{
		cout<<"\t "<<temp->data; 
		suma+=temp->data;
		temp=temp->next; 
		
	}
	free (temp);
	cout<<"\nLa suma total es "<<suma;
	return 0;
}

