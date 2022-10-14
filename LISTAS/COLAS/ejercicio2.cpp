#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
struct node{
	int data;
	struct node *link;
};
int main(int argc, char *argv[])
{
	srand(time(NULL));
	struct node *front=NULL; 
	struct node *back=NULL; 
	struct node *temp=NULL; 
	for (int ii=0;ii<5;ii++)
	{
		cout<<"\n Nodo "<<ii+1<<" :";
		temp=(struct node*)malloc(sizeof(struct node));
		if (temp==NULL)
		{
			cout<<"No hay memoria suficiente para cargar nodos"; 
			exit(1);
		}
		temp->data=rand () % 11;
		temp->link=NULL; 
		cout<<" "<<temp->data; 
		if ((front==NULL)&&(back==front))
		{
			back=temp; 
			front=back; 
		}else{
			back->link=temp; 
			back=temp; 
		}
	}
	cout<<"\n***Valores pares***"<<endl; 
	temp=front; 
	while(temp!=NULL)
	{
		if (((temp->data)%2)==0)
		{	
		cout<<"\t "<<temp->data; 
		}
		temp=temp->link;
	}
	
	return 0;
}

