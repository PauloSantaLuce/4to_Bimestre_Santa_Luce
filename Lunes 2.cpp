#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	int Ruso[5][5];
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cout<<"Ingrese un valor para la posición: "<<i+1<<" , "<<j+1<<endl;
			cin>>Ruso[i][j];
		}
	}
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cout<<Ruso[i][j]<<" ";
		}
		cout<<endl;
	}
	int suma1=0, suma2;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			int a=0;
			if(Ruso[i][j]=0){
				a=a+1;
			}
            suma1= suma1+a;
            suma2=suma1;
		}
    }
    cout<<"La cantidad de ceros que ingresó es: "<<suma1<<endl;
	
	
	
	
	return 0;
	getch();
}
