#include <string>
#include <iostream>
#ifndef FACTURA_H
#define FACTURA_H
using namespace std;
class factura{
private: 
	int num; 
	string nom;
	float gb; 
	float total; 
	
	
public:
	factura(){
		cout<<"\nConstructor por defecto\n"; 
	};
	factura(int numero,string nombre,int consumido){
		cout<<"\nConstructor datos"<<endl; 
		num=numero; 
		nom=nombre; 
		gb=consumido/1000; 
		total=consumido*0.05; 
	};
	int getnum (){
		return num; 
	};
	string getnom (){
		return nom;
	};
	float getgb (){
		return gb;
	};
	float getotal(){
		return total; 
	};
	void setnum (int numero){
		num=numero;
	};
	void setnom (string nombre){
		nom=nombre;
	};
	void setgb (float consumido){
		gb=consumido/1000; 
	};
	void setotal (float consumido){
		total=consumido*0.05;
	};
};
#endif
