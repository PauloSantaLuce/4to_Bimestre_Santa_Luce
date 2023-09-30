#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	struct persona{
	char nombre[20];
	int edad;
	double altura;
	char tez[20];
	char nacionalidad[20];
	char genero[20];
}persona2[2];
//persona1 = {"Wicho",12,1.62,"Blanco Albino","Tactic","Pansexual"};
 
	
	/*cout<<"Datos Personales"<<endl;
	cout<<"Nombre: "<<persona1.nombre<<endl;
	cout<<"Edad "<<persona1.edad<<endl;
	cout<<"Altura "<<persona1.altura<<endl;
	cout<<"Tez "<<persona1.tez<<endl;
	cout<<"Nacionalidad "<<persona1.nacionalidad<<endl;
	cout<<"Genero "<<persona1.genero<<endl;*/
	for(int i=0; i<2; i++){
		cout<<"Ingrese su nombre: ";
		cin.getline(persona2[i].nombre,20,'\n');
		cout<<"\n Ingrese su edad: ";
		cin.getline(persona2[i].edad,'\n');
		
	}
	
	getch();
	return 0;
}
