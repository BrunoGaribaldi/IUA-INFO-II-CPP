#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *ptr;
};
int main(int argc, char *argv[])
{
	struct node *newnode=NULL; 
	struct node *temporary=NULL; 
	struct node *head=NULL; 
	int opt=0,num=0,i=0; 
	char cont=' '; 
	do{
		cout<<"INGRESE:\n1:Cargar nodo\n2:Borrar el ultimo nodo de la pila\n3:Imprimir pila\n4:Tamaño de la pila\n5:Ultimo valor de la pila\n6:Borrar toda la pila, liberar memoria"<<endl;
		cin>>opt; 
		
			switch (opt)
			{
				case 1:
					if (i==5)
					{
						cout<<"\nYa se han creado los 5 nodos"<<endl; 
					}else{
					cout<<"\nNODO NUMERO "<<i+1<<endl;
					cout<<"\ningrese un numero"<<endl; 
					cin>>num;
					newnode=(struct node*)malloc(sizeof(struct node));
					if (newnode==NULL){
						cout<<"no hay memoria suficiente"<<endl; 
					}else{
						newnode->data=num; 
						newnode->ptr=head; 
						head=newnode;
						i++;
					}
					}
					break;
				case 2:
					if (head==NULL)
					{
						cout<<"no hay nodos que eliminar"<<endl; 
					}else{
						temporary=head;
						head=head->ptr;
						free(temporary);
						i--;
					}
					break;
				case 3:
					temporary=head; 
					while(temporary!=NULL)
					{
						cout<<" "<<temporary->data<<endl; 
						temporary=temporary->ptr;
					};
					break;
				case 4:
					cout<<"\nel tamaño de la pila es de "<<i<<" nodos"<<endl; 
					break;
				case 5:
					temporary=head; 
					while(temporary->ptr!=NULL)
					{
						temporary=temporary->ptr;
					}
					cout<<"El ultimo es "<<temporary->data<<endl; 
					break;
				case 6: 
					while(head!=NULL)
					{
						temporary=head; 
						head=head->ptr;
						free(temporary);
					}
					cout<<"\npila vacía"<<endl; 
					break;
				default:
					cout<<"ingreso mal la opcion del menu"<<endl;
					break;
			}
		cout<<"\n[S/N]";
		cin>>cont;
	}while(cont=='s');

	return 0;
}

