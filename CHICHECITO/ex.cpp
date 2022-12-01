#include <iostream>
<string.h>
<ctime>
//////////////////////////////////

ARCHIVOS
FILE *fp; 
fp=fopen("./nombre.txt","x")
fclose(fp)
FEOF==0
fputs("cadena"variable,fp)					fgets(variable,tam,fp)
fprintf(fp,"%d",lo qu quieras)			    fscanf(fp,"%d",donde)
remove(fp); //remover archivos
while(!feof(fp))
//////////////////////////////////
STRINGS
	
strcpy(s1,s2)copia
strcat(s1,s2)concatena al final
strlen(s1) el largo de una string
strcmp(s1,s2)->compara. 0 cadenas iguales -------->>>>> otra forma if(cadena=="hola")
puedo acceder a cada letra usando [posicion ej. 2]
//////////////////////////////////

PILAS/STACKS

solo necesito un newnode, un temp, y un stackptr; 

push								pop acordate siempre de preguntar si las listas estan vacias
newnode->next=stackptr;				temp=stackptr;
stackptr=newnode; 					stackptr=stackptr->next;
									free(temp)
//////////////////////////////////
										
LISTAS
push acordate en todas de igualar el newnode->next a nulll all principio. 
pop
	
///////////////////////////////

COLAS/FIFO

NECESITO UN FRONT UN BACK UN NEWNODE Y UN TEMP.
push									pop
	
if(back==null)							temp=front
back=newnode=front						front=front->link
else									if front=null
back->next=newnode						back=null
back=newnode;							free(temp);
/////////////////////////////////////////
CLASES
	class perro{
	private: 
		string nombre; 
		string raza; 
		int edad; 
	public: 
		perro(string n,string r,int e){
			nombre=n;
			raza=r;
			edad=e;
		};
		perro(){
		};
		void setnombre (string nombree){
			nombre=nombree;
		};
			string getnombre(){
				return nombre; 
			};
				string toString(){
					string cadena=nombre+"\t"+raza+"\t"+std::to_string(edad); 
					return cadena; 
				};
					
					int main(int argc, char *argv[]) {
						perro p1("juan","dogo",37);
						cout<<p1.toString()<<endl;
						perro p2;
						p2.setnombre("gola");
						cout<<p2.getnombre();
						return 0;
					}
					
El metodo constructor no devuelve ningun tipo de dato, ni siquiera void 
metodo destructor ~NOMBRE CLASE()
					NOMBRE CLASE::~NOMBRE CLASE(){
					cout<<"ejecutando destructor";
					}
					
Al igual que las estructuras, para entrar a las funciones uso el operador punto. 
En el caso de que quiera usar un puntero, uso ->
NOMBRE CLASE *ptr; 
NOMBRE CLASE a; 
ptr=&a;

despues tenemos el puntero this que no se para que es

--->>>>>separar clases en archivos
	

/////////////////////////////////////
					
CASTEO 
float f;
int ii=4; 
f=(float)ii/3;

///////////////////////////////

ARREGLOS Y PUNTEROS
-->Arreglos una dimensión 
	int total[5]; 
	int *ptr=NULL; 
	ptr=total; 
	ptr++; [1]
	ptr++; [2]
	ptr--; [1]
	
	o
	(ptr+1)
	
-->Arreglos dos dimensiones 
	*(*nums) [0][0]
	*(*nums+1) [0][1]
	*(*(nums+1)+1); [1][1]
		
///////////////////////////////
punteros a funciones cuaaac
		
///////////////////////////////
	MEMORIA DINAMICA 
	
	-->una dimensión; 
	
	malloc
		
	int *p=NULL; 
	p=(int *)malloc(cantidad*sizeof(int));//cantidad es la cantidad de elementos que quiero guardar. 
	checknull
	*(p+ii)=dato;
	
	realloc
	p=(int *)malloc(15*sizeof(int)); 
	p=(int *)realloc(p,25*sizeof(int));//antes tenia 15, ahora le reasigno 25, es decir que le agrego 10 mas
	for (int ii=0;ii<10;ii++)
	{
		*(p+ii+14)=valor; 
	}
	
	-->dos dimensiones
	hay uno hecho....
	
///////////////////////////////
		
		typedef es una forma de llamar de otra forma a un tipo de dato
		Por ejemplo si no quiero llamar mas int, puedo hacer lo siguiente
		typedef int var; ahora en vez de poner int, puedo poner var y lo va a tomar como int. 
		ej: 
		var hola=0,chau=0,quetal=0; 
		
		lo mismo pasa en las estructuras, en vez de llamar 10000 veces struct node por ejemplo, puedo hacer lo siguiente:
		typedef struct node cba. cada vez que yo escriba cba, lo va a tomar como si hubiese escrito struct node. 
			
///////////////////////////////		

estructuras: 
			
arreglos 
struct measurment array[4];
	
punteros, funciones y paso por referencia: 
	
void carga (struct calificaciones *);
struct calificaciones c;
struct calificaciones *p;
p=&c;
carga (p);
void carga (struct calificaciones *c){//acordate de que cuando usamos punteros en las estructuras, hay que usar ->
	
}

/////////////////////

calificadores de acceso


//////////////////////////////////////////

	
crear nuestras librerias
--->en el .h
#ifndef lib_h//nombre 
#define lib_h//nombre 
using namespace std;

codigo
#endif
	
--->en el .c
#include "lib.h"//el nombre que le puse a mi libreria
