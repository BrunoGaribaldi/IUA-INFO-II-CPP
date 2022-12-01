#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
		int numero;
		srand(time(NULL)); //Funcion para generar numeros random
		
		cout<<"NUMEROS RANDOM - ¿COMO DEFINIR EL RANGO?"<<endl;
		cout<<"\nCaso 1: Numeros random entre el 0 y 99."<<endl;
		for(int i=0; i<10; i++){
			numero = rand() % 10;//hasta+1
			cout<<numero<<"  ";
		}
		
		cout<<"\n\nCaso 2: Numeros random entre 1 y 100."<<endl;
		for(int i=0; i<10; i++){
			numero = rand() % 100 + 1;//hasta+desde
			cout<<numero<<"  ";
		}
		
		cout<<"\n\nCaso 3: Numeros random entre 1990 y 2020."<<endl;
		for(int i=0; i<10; i++){
			numero = rand() % 30 + 1990;//(hasta-desde+1)+desde
			cout<<numero<<"  ";
		}
	return 0;
}

