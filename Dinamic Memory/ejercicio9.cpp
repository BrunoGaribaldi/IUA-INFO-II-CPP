/*
Cree un programa que permita reservar memoria para arreglo de enteros 2x3. 
Luego cargar los valores de manera aleatoria. Realizar un menu de opciones que
 muestre la sumatoria, muestre todos los valores y al finalizar el programa 
libere la memoria.
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
void sum(int**,int,int);
void impr(int**,int,int);
using namespace std;

int main(int argc, char *argv[]) 
{
	srand(time(NULL)); 
	int ii=0,jj=0,m=3,n=2;
	int **a=(int**)malloc(m*sizeof(int));//aca estoy declarando las filas. 3 fil. 
	if (a==NULL)
	{
		cout<<"no hay memoria disponible"<<endl; 
		exit (0);
	}else{
		for (ii=0;ii<m;ii++)
		{
			*(a+ii)=(int*)malloc(n*sizeof(int));//inicialización de columnas. n columnas 
			if(*(a+ii)==NULL)
			{
				cout<<"memoria insuficiente"<<endl;
				exit(0);
			}
		}
	}
	for(ii=0;ii<m;ii++)
	{
		for(jj=0;jj<n;jj++)
		{
			*(*(a+ii)+jj)=rand()%10;//carga de datos
		}
	}
	
	cout<<"\n***menu de opciones***"<<endl;//hacerlo con switch y todo eso 
	sum(a,m,n);
	impr(a,m,n);
	
	for(ii=0;ii<3;ii++)
	{
		free(*(a+ii));//liberacion filas
	}
	free(a);//liberacion columna
	
	return 0;
}
void sum(int** a,int m,int n)
{
	int suma=0; 
	for(int ii=0;ii<m;ii++)
	{
		for(int jj=0;jj<n;jj++)
		{
			suma+=*(*(a+ii)+jj);
		}
	}
	cout<<"la suma de los datos del arreglo es "<<suma<<endl; 
}
void impr(int** a,int m,int n)
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
