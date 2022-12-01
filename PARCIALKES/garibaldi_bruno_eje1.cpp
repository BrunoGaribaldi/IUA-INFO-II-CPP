#include <iostream>
using namespace std;
struct remito{
	int numero; 
	char apellido[40];
	int ladrillos;
	float peso; 
};
struct node{
	struct remito r;
	struct node *next;
};
void push (struct node**,struct remito);
float fpeso (struct remito r);
void print (struct node*);
void fmaycarga (struct node*);
void buscar (struct node*);
int main(int argc, char *argv[]) 
{
	struct node *head=NULL;
	struct node *temp=NULL;
	struct remito r;
	char cont;
	int opt,cant;
	FILE *fp; 
	cout<<"Ingrese cuántos remitos desea cargar"<<endl; 
	cin>>cant;
	for (int ii=0;ii<cant;ii++)
	{
		cout<<"\n-----------------------------"<<endl; 
		cout<<"Remito n. "<<ii+1; 
		cout<<"\nIngrese el codigo del remito"<<endl; 
		cin>>r.numero; 
		cout<<"\nIngrese su apellido"<<endl; 
		cin>>r.apellido; 
		cout<<"\nIngrese la cantidad de ladrillos"<<endl; 
		cin>>r.ladrillos; 
		r.peso=fpeso(r);
		push(&head,r);
		
	}
	do
	{
		cout<<"\n***MENU DE OPCIONES***"<<endl; 
		cout<<"\nINGRESE:\n1:Mostrar listado de remitos\n2:Mostrar remito con más carga\n3:Mostrar remito\n4:Grabar archivo"<<endl;
		cin>>opt; 
		switch (opt){
		case 1:
			print(head);
			break;
		case 2: 
			fmaycarga(head);
			break;
		case 3:
			buscar(head);
			break;
		case 4:
			fp=fopen("./remito.txt","w");
			fprintf(fp,"%s","REMITO\tAPELLIDO\tCANT.LADRILLOS\tPESO TOTAL\n");
			temp=head;
			while(temp!=NULL)
			{
				fprintf(fp,"%d\t",temp->r.numero);
				fprintf(fp,"%s\t\t",temp->r.apellido);
				fprintf(fp,"%d\t\t",temp->r.ladrillos);
				fprintf(fp,"%f\n",temp->r.peso);
				temp=temp->next;
			}
			break; 
		default:
			cout<<"\nSe ha ingresado mal la opcion"<<endl;
			break; 
		}
		cout<<"\nPara continuar en el menu [s/n]"<<endl; 
		cin>>cont;
	} while((cont=='s')||(cont=='S'));
	return 0;
}
float fpeso (struct remito r)
{
	float peso_total;
	peso_total=r.ladrillos*0.35;
	return peso_total;
}
void push (struct node **head, struct remito r)
{
	struct node *newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode==NULL)
	{
		cout<<"\nNo hay memoria disponible";
		exit(1);
	}else{
		newnode->next=NULL; 
		newnode->r=r;
		newnode->next=*head;
		*head=newnode;
	}
}
void print (struct node* head)
{
	struct node *temp=NULL; 
	temp=head;
	while(temp!=NULL)
	{
		cout<<"\n---------------------------------------"<<endl; 
		cout<<"\nNUMERO: "<<temp->r.numero; 
		cout<<"\nAPELLIDO: "<<temp->r.apellido; 
		cout<<"\nCANTIDAD LADRILLOS: "<<temp->r.ladrillos;
		cout<<"\nPESO: "<<temp->r.peso;
		cout<<"\n---------------------------------------"<<endl; 
		temp=temp->next; 
	}
}
void fmaycarga (struct node *head)
{
	struct node *temp=NULL; 
	struct remito v;
	int ctr=0;
	temp=head;
	while(temp!=NULL)
	{
		if(ctr==0)
		{
			v=temp->r;
		}else{
			if ((temp->r.ladrillos)>v.ladrillos)
			{
				v=temp->r;
			}
		}
		ctr++;
		temp=temp->next;
	}
	cout<<"\nEL REMITO CON MAS CARGA ES "<<endl;
	cout<<"\nNUMERO: "<<v.numero; 
	cout<<"\nAPELLIDO: "<<v.apellido; 
	cout<<"\nCANTIDAD LADRILLOS: "<<v.ladrillos;
	cout<<"\nPESO: "<<v.peso;
}
void buscar (struct node *head)
{
	struct node *temp=NULL;
	int num;
	temp=head;
	cout<<"\nIngrese el numero de remito"<<endl; 
	cin>>num; 
	while(temp!=NULL)
	{
		if((temp->r.numero)==num)
		{
			cout<<"\nSE A ENCONTRADO EL REMITO"<<endl; 
			cout<<"\n---------------------------------------"<<endl; 
			cout<<"\nNUMERO: "<<temp->r.numero; 
			cout<<"\nAPELLIDO: "<<temp->r.apellido; 
			cout<<"\nCANTIDAD LADRILLOS: "<<temp->r.ladrillos;
			cout<<"\nPESO: "<<temp->r.peso;
			cout<<"\n---------------------------------------"<<endl; 
			temp=temp->next;
		}else{
			temp=temp->next;
		}
	}
}
