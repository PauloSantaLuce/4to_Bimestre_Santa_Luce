#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
int main() {
	int a;
	cout<<"Ingrese la cantidad de nombres que conformaran tu lista"<<endl;
	cin>>a;
	string lista[a];
	char nombre[100];
	char band = 'F';
	
	for(int i=0; i<a; i++){
		cout<<"ingresa el nombre que ira en la posicion "<<i+1<<endl;
		cin>>lista[i];
	} 
	
	cout<<"Dime que nombre quieres buscar"<<endl;
	cin>>nombre;
	int j;
	while((band == 'F')&&(j<5)){
		if(lista[j]==nombre){
			band ='V';
	}
	j++;
			}
		if(band == 'F'){
			cout<<"El numero a buscar no existe en el vector"<<endl;
		}
		else if(band=='V'){
			cout<<"El nombre "<<nombre<<" fue encontrado en la posicion "<<j;
		}
	return 0;
	getch();
}
