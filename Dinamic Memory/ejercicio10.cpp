/*
	Programa que pide al usuario los datos del tamaño del arreglo, que pueda cambiar el tamaño y pueda imprimir
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void asign (int**,int,int*);
void cargar (int**,int,int);
void imprimir (int**,int,int);
void asign1 (int**,int,int*);
void cargar1 (int**,int,int,int,int);
void imprimir1 (int**,int,int);
int main(int argc, char *argv[])
{
	int m=0,m1=0,n1=0,n=0; 
	cout<<"ingrese la cantidad de filas que quiere que su arreglo tenga"<<endl;
	cin>>m;
	int **a=(int**)malloc(m*sizeof(int));
	if(a==NULL)
	{
		cout<<"no hay memoria disponible"<<endl; 
		exit (0);
	}else{
		asign(a,m,&n);
		cargar(a,m,n);
		imprimir(a,m,n);
	}
	cout<<"ingrese la cantidad de filas que quiere que tenga su arreglo ahora."<<endl; 
	cin>>m1;
	a=(int**)realloc(a,m*sizeof(int));
	if(a==NULL)
	{
		cout<<"no hay memoria disponible"<<endl; 
		exit (0);
	}else{
		asign1(a,m1,&n1);
		cargar1(a,m,m1,n,n1);
		imprimir1(a,m1,n1);
	}
	return 0;
}
void asign (int** a,int m,int* n)
{
	cout<<"ingrese la cantidad de columnas del arreglo"<<endl; 
	cin>>*n;
	for (int ii=0;ii<m;ii++)
	{
		*(a+ii)=(int*)malloc(*n*sizeof(int));//inicilización de columnas. 
		if(*(a+ii)==NULL)
		{
			cout<<"memoria insuficiente"<<endl;
			exit(0);
		}
	}
}
void cargar (int** a,int m,int n)
{
	srand(time(NULL)); 
	for(int ii=0;ii<m;ii++)
	{
		for(int jj=0;jj<n;jj++)
		{
			*(*(a+ii)+jj)=rand()%10;//carga de datos
		}
	}
}
void imprimir (int** a,int m,int n)//impresión datos. 
{
	for(int ii=0;ii<m;ii++)
	{
		for(int jj=0;jj<n;jj++)
		{
			cout<<"\t"<<*(*(a+ii)+jj);
		}
		cout<<"\n";
	}
}
void asign1 (int** a,int m1 ,int* n1)
{
	cout<<"ingrese la cantidad de columnas del nuevo arreglo"<<endl; 
	cin>>*n1;
	for (int ii=0;ii<m1;ii++)
	{
		*(a+ii)=(int*)realloc(a,*n1*sizeof(int));//inicilización de columnas. 
		if(*(a+ii)==NULL)
		{
			cout<<"memoria insuficiente"<<endl;
			exit(0);
		}
	}
}
void cargar1 (int** a,int m,int m1,int n,int n1)
{
	srand(time(NULL)); 
	for(int ii=m;ii<(m+m1);ii++)
	{
		for(int jj=n;jj<(n+n1);jj++)
		{
			*(*(a+ii)+jj)=rand()%10;//carga de datos
		}
	}
}
void imprimir1 (int** a,int m1,int n1)
{
	for(int ii=0;ii<m1;ii++)
	{
		for(int jj=0;jj<n1;jj++)
		{
			cout<<"\t"<<*(*(a+ii)+jj);
		}
		cout<<"\n";
	}
}
