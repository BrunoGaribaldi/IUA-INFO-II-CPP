#include <iostream>
#include <string>
#include "factura.h"
using namespace std;

int main(int argc, char *argv[])
{	
	int num;
	string ap; 
	int mb; 
	factura f1;
	cout<<"Ingrese el número de factura"; 
	cin>>num; 
	cout<<"\nIngrese el apellido"<<endl; 
	cin>>ap; 
	cout<<"\nIngrese la cantidad de mb consumidos"<<endl; 
	cin>>mb; 
	f1.setnum(num);
	f1.setnom(ap);
	f1.setgb(mb);
	f1.setotal(mb);
	cout<<f1.getnum();
	cout<<f1.getnom();
	cout<<f1.getgb();
	cout<<f1.getotal();
	factura f2 (num,ap,mb);
	cout<<f2.getnum();
	cout<<f2.getnom();
	cout<<f2.getgb();
	cout<<f2.getotal();
	
	return 0;
}

