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
	struct node *temp2=NULL; 
	int opt1,opt2,i=0, caso;
	char cont; 
	do{	
		cout<<"INGRESE:\n1:crear nodo\n2:imprimir\n3:Borrar nodo"<<endl; 
		cin>>opt1; 
		switch (opt1)
		{
		case 1:
			cout<<"INGRESE:\n1:Ingresar nodo al final\n2:Ingresar nodo al diome"<<endl; 
			cin>>opt2; 
			switch (opt2)
			{
			case 1: //crear nodos
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
				i++;
				break; 
			case 2://meter un nodo al medio de otro
				newnode=(struct node*)malloc(sizeof(struct node));
				newnode->data=rand()%11; 
				newnode->next=NULL; 
				if(head==NULL)
				{
					head=newnode; 
				}else{
					cout<<"\nHay "<<i<<" nodos existentes, ingrese en qué posicion desea ingrear el nuevo nodo"<<endl;
					cin>>caso;
					temp=head;
					for(int ii=0;ii<(caso+1);ii++)
					{
						if(ii==1)
						{
							temp2=head;
						}
						if(ii>1)
						{
							temp2=temp2->next;
						}
						temp=temp->next;
					}
					temp2=newnode; 
					newnode->next=temp; 
				}
				break; 
			}
		break; 
		case 2:
			cout<<"\n***IMPRESION LISTA***"<<endl; 
			temp=head; 
			while(temp!=NULL)
			{
				cout<<"\t "<<temp->data; 
				temp=temp->next; 
			}
			free (temp);
			break; 
		case 3:
			break; 
		}
		cout<<"\ncont s"<<endl; 
		cin>>cont; 
	}while(cont=='s'||cont=='S');
	return 0;
}

