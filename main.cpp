#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	struct datos{
		char nombre[20];
		int edad;
		double altura;
		char genero[20]; 
		char tez[20];
		
	}persona[2];
	
	cout<<"Solicitando datos...\n";
	for(int i=0; i<2; i++){
		cout<<"Ingrese su nombre: ";
		cin.getline(persona[i].nombre,20,'\n');
		cout<<"Ingrese su edad ";
		cin>>persona[i].edad;
		cout<<"Ingrese su altura en cm  ";
		cin>>persona[i].altura;
		cin.ignore();
		cout<<"Ingrese su genero ";
		cin.getline(persona[i].genero,20,'\n');
		cout<<"Ingrese su tez ";
		cin.getline(persona[i].tez,20,'\n');				
	}
	
	cout<<"\nDatos personas\n";
	for(int i=0; i<2; i++){
		cout<<"\nNombre "<<persona[i].nombre;
		cout<<"\nEdad "<<persona[i].edad;
		cout<<"\nAltura "<<persona[i].altura;
		cout<<"\nGenero "<<persona[i].genero;
		cout<<"\nTez "<<persona[i].tez;
		cout<<endl;
	}
	
	
	getch();
	return 0;
}
