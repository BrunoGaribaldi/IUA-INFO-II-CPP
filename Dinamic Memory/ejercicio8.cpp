/*
Crear un programa en la cual contenga un menú de opciones con distintas operaciones: 

a. Reserva de memoria e introducción de datos enteros

b. Agregar reserva de memoria e introducción de nuevos datos enteros

c. Mostrar los datos en el orden y orden invertido al que fueron introducidos
*/

#include <iostream>
#include <stdlib.h>

using namespace std;
void cargar1 (int*,int);
void cargar2 (int*,int,int);
void imprimir (int*,int,int);
int main (int argc, char *argv[])
{
	int* p=NULL; 
	int opt=0,n=0,n1=0;
	char cont=' ';
	do{
		cout<<"ingrese:\n1:Reserva de memoria e introducción de datos\n2:Agregar reserva de memoria e introducción de nuevos datos enteros\n3:Mostrar los datos en el orden y orden invertido al que fueron introducidos"<<endl; 
		cin>>opt; 
		switch (opt){
		case 1: 
			if(p==0)
			{
			cout<<"cantidad de datos enteros a reservar"<<endl; 
			cin>>n;
			p=(int*)malloc(n*sizeof(int));
			if (p==NULL){
				cout<<"no hay memoria disponible"<<endl;
				exit (1);
			}else{
				cargar1(p,n);
			}
			}else{
				cout<<"para cargar nuevamente desde cero el vector, tenes que borrar todo. Quiere continuar?? [s/n]"<<endl; 
				cin>>cont;
				if (cont=='s')
				{
					free(p);
					cout<<"cantidad de datos enteros a reservar"<<endl; 
					cin>>n;
					p=(int*)malloc(n*sizeof(int));
					if (p==NULL){
						cout<<"no hay memoria disponible"<<endl;
						exit (1);
					}else{
						cargar1(p,n);
					}
				}
			}
			break; 
		case 2: 
			if(p==0)
			{
				cout<<"no se puede reasignar memoria sin antes haberla asignado"<<endl; 
			}else{
				cout<<"ingrese la cantidad de nueva memoria que desa agregar"<<endl; 
				cin>>n1; 
				p=(int*)realloc(p,n1*sizeof(int));
				if (p==NULL){
					cout<<"no hay memoria disponible"<<endl;
					exit (1);//no hay memoria, sale error.
				}else{
					cargar2(p,n,n1);
				}
			}
			break; 
		case 3: 
		if(p==0)
		{
			cout<<"no hay datos qué imprimir"<<endl; 
		}else{
			imprimir(p,n,n1);
		}
			break; 
		default: 
			cout<<"ingreso mal la opcion"<<endl; 
			break; 
		}
		cout<<"desea continuar en el menu? [s/n]"<<endl; 
		cin>>cont; 
	} while(cont=='s');
	free(p);
	return 0; 
}
void cargar1 (int* p,int n)
{
	cout<<"ingrese valores"<<endl;
	for(int ii=0; ii<n; ii++)
	{
		cout<<"valor "<<ii+1<<endl; 
		cin>>*(p+ii);
		cout<<"\n";
	}
}
void cargar2 (int* p,int n,int n1)
{
	cout<<"ingrese nuevos valores"<<endl;
	for(int ii=n; ii<(n+n1); ii++)
	{
		cout<<"valor "<<ii+1<<endl; 
		cin>>*(p+ii);
		cout<<"\n";
	}
}
void imprimir (int* p,int n,int n1)
{
	if(n1==0)
	{
	for(int ii=0; ii<n ; ii++)
	{
		cout<<*(p+ii)<<"\t";
	}
	}
	if (n1>0)
	{
		for(int ii=0; ii<(n+n1) ; ii++)
		{
			cout<<*(p+ii)<<"\t";
		}
	}
}
