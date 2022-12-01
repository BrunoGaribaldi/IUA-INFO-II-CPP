#include <iostream>
#include <string>
using namespace std;
class remito{
private:
	int numero;
	string apellido;
	int ladrillos;
	float peso;
public: 
	remito()
	{
		cout<<"\nINSTANCIANDO, CONSTRUCTOR POR DEFECTO"<<endl; 
	};
	remito(int _num, string _ap, int _lad, float _p){
		cout<<"\nINSTANCIANDO, CONSTRUCTOR CON DATOS"<<endl; 
		numero=_num;
		apellido=_ap;
		ladrillos=_lad;
		peso=_p;
	};
	void numsetter (int numeroo){
		numero=numeroo; 
	}
	int numgetter (){
		return numero;
	}
	void apsetter (string apellidoo){
		apellido=apellidoo; 
	}
	string apgetter (){
		return apellido;
	}
	void ladsetter (int ladrilloo){
		ladrillos=ladrilloo; 
	}
	int ladgetter (){
		return ladrillos;
	}
	void psetter (float pesoo){
		peso=pesoo; 
	}
	float pgetter (){
		return peso;
	}
	string toString(){
		string cadena=apellido+"\t"+std::to_string(numero)+"\t"+std::to_string(ladrillos)+"\t\t"+std::to_string(peso); 
		return cadena; 
	};
	~remito(){
		cout<<"\nIniciciando destructor"<<endl; 
	}
};
int main(int argc, char *argv[])
{
	string apellido; 
	int num,cant; 
	float peso; 
	remito r1(1,"garibaldi",20,300);
	cout<<"APELLIDO\tNUMERO\tCANT.LADRILLOS\tPESO"<<endl;
	cout<<r1.toString()<<endl;
	remito r2;
	cout<<"\nIngrese el apellido"<<endl; 
	cin>>apellido;
	r2.apsetter(apellido);
	cout<<"\nIngrese el numero de remito"<<endl; 
	cin>>num;
	r2.numsetter(num);
	cout<<"\ningrese la cantidad de ladrillos"<<endl; 
	cin>>cant; 
	r2.ladsetter(cant);
	peso=cant*0.35;
	r2.psetter(peso);
	cout<<"APELLIDO: ";
	cout<<r2.apgetter()<<endl;
	cout<<"NUMERO DE REMITO: ";
	cout<<r2.numgetter()<<endl;
	cout<<"CANTIDAD DE LADRILLOS: ";
	cout<<r2.ladgetter()<<endl;
	cout<<"PESO: ";
	cout<<r2.pgetter()<<endl;
	return 0;
}

