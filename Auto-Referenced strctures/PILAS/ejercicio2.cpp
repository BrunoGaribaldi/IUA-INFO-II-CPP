#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
struct node{
	int data;
	struct node *ptr;
};
int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	struct node *newnode=NULL;
	struct node *head=NULL;
	struct node *temporary=NULL;
	for (int ii=0;ii<5;ii++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		if (newnode==NULL)
		{
			cout<<"no memory enough"<<endl;
			exit (1);
		}
		newnode->data= rand() % (10-1+1)+1;
		newnode->ptr=head;
		head=newnode; 
		if (head==NULL)
		{
			cout<<"node doesnt exist"<<endl; 
		}else{
			temporary=head;
			cout<<"\nDato: "<<temporary->data;
		}
	}
	temporary=head;
	cout<<"\n**DATOS PARES**"<<endl; 
	while(temporary!=NULL)
	{
		if (((temporary->data)%2)==0)
		{
		cout<<"\t "<<temporary->data;
		temporary=temporary->ptr;
		}
	}
	return 0;
}
