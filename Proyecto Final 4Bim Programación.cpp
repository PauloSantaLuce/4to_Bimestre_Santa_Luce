#include<iostream>
#include<conio.h>
#include<string.h>


using namespace std;

struct contacto{
       char nombres[30];
       char apellidos[30];
       char correo[30];
       int numero;
       }contactos;


void CrearContactos();
void VerContactos();
void EditarContactos1();
void EditarContactos2();
void EditarContactos3();
void EliminarContactos1();
void EliminarContactos2();
void EliminarContactos3();

int main(){

    cout<<"\n\tAplicacion de Contactos";
    cout<<"\n\tPresiona Enter para ingresar";
    getch();
    system("cls");

    int a;
    int x;
    int z;
    do{
       cout<<"\n\tElija una opción";

       cout<<"\n\t1. Crear Contactos";
       cout<<"\n\t2. Ver Contactos";
       cout<<"\n\t3. Editar Contactos";
       cout<<"\n\t4. Eliminar Contactos";
       cout<<"\n\t5. Salir ";
       cin>>a;
       switch(a){
       case 1: {
       	CrearContactos();
            getch();
            system("cls");
            break;
            }
            case 2: {
            VerContactos();
            getch();
            system("cls");
            break;
            }
            case 3: {
            do{
			
            cout<<"\n\tElija una opción para encontrar el contacto";
cout<<"\n\t1. Por Nombre";
cout<<"\n\t2. Por apellido";
cout<<"\n\t3. Por correo";
cout<<"\n\t4. Salir ";
cin>>z;
switch(z){
	case 1: {
		EditarContactos1();
		getch();
            system("cls");
            
		break;
	}
	case 2: {
		EditarContactos2();
		getch();
            system("cls");
            
		break;
	}
	case 3: {
		EditarContactos3();
		getch();
            system("cls");
            
		break;
	}
}
} while(z != 4);
            break;
            }
            case 4: {
            do{
			
            cout<<"\n\tElija una opción para encontrar el contacto";
cout<<"\n\t1. Por Nombre";
cout<<"\n\t2. Por apellido";
cout<<"\n\t3. Por correo";
cout<<"\n\t4. Salir ";
cin>>x;
switch(x){
	case 1: {
		EliminarContactos1();
		getch();
            system("cls");
            
		break;
	}
	case 2: {
		EliminarContactos2();
		getch();
            system("cls");
            
		break;
	}
	case 3: {
		EliminarContactos3();
		getch();
            system("cls");
            
		break;
	}
}
} while(x != 4);
            break;
            }
        
        }
}
while (a != 5);
return 0;
}
void CrearContactos(){
    char s; //variable para finalizar el ingreso de los libros
    FILE *fp; ///variable que solo maneja archivos
    do{
        fp = fopen("Biblioteca.txt","a+b");
        system("cls");
        cout<<"\n\n\n\t\tRegistrar Contacto\n";
        cout<<"\n\tNombre del Contacto: ";
        cin.ignore();
        cin.getline(contactos.nombres, sizeof(contactos.nombres));
        cout<<"\n\tApellido del Contacto: ";
        cin.getline(contactos.apellidos, sizeof(contactos.apellidos));
        cout<<"\n\tCorreo: ";
        cin.getline(contactos.correo, sizeof(contactos.correo));
        cout<<"\n\tNumero: ";
        cin>>contactos.numero;
        fwrite(&contactos, sizeof(contactos),1,fp);
        fclose(fp);

        cout<<"\n\n\n\t\tIngrese un 1 para registrar otro libro, 0 para salir ";
        cin>>s;


    }while(s != '0');

}
void VerContactos() {
    FILE *fp;
    fp = fopen("Biblioteca.txt", "r+b");
    system("cls");
    cout << "\n\n\n\tVer Contactos Registrados\n";

    while (fread(&contactos, sizeof(contactos), 1, fp) == 1) {
        cout << "\nNombre del contacto: "<<contactos.nombres;
        cout << "\nApellido del contacto: "<<contactos.apellidos;
        cout << "\nCorreo del contacto: "<<contactos.correo;
        cout << "\nNumero del contacto "<<contactos.numero;
        cout << "\n";
    }
    fclose(fp);
    cout << "\nPresione cualquier tecla para salir_ ";
}
void EditarContactos1(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;

    system("cls");
    cout<<"\n\n\n\t\tActualiar Datos de un Contacto\n";
    cout<<"\n\tIngrese el nombre del contacto a actualizar: ";
    cin.ignore();
    cin.getline(buscarnombre, sizeof(buscarnombre));

    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");

    while(fread(&contactos, sizeof(contactos),1,fp)==1){
        if(strcmp(contactos.nombres,buscarnombre)==0){
            encontrado = true;
            cout<<"\n\tNuevo nombre: ";
            cin.getline(contactos.nombres, sizeof(contactos.nombres));
            cout<<"\n\tNuevo apellido: ";
            cin.getline(contactos.apellidos, sizeof(contactos.apellidos));
            cout<<"\n\tNuevo correo: ";
            cin.getline(contactos.correo, sizeof(contactos.correo));
            cout<<"\n\tNuevo numero: ";
            cin>>contactos.numero;
        }
        fwrite(&contactos, sizeof(contactos),1, tempFile);
    }
    fclose(fp);
    fclose(tempFile);

    if(encontrado){
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt","Biblioteca.txt");
        cout<<"\n\tDatos fueron actualizados...";
    }else{
        cout<<"\n\tDatos no fueron actualizados...";
    }

	}
	void EditarContactos2(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;

    system("cls");
    cout<<"\n\n\n\t\tActualiar Datos de un Contacto\n";
    cout<<"\n\tIngrese el apellido del contacto a actualizar: ";
    cin.ignore();
    cin.getline(buscarnombre, sizeof(buscarnombre));

    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");

    while(fread(&contactos, sizeof(contactos),1,fp)==1){
        if(strcmp(contactos.apellidos,buscarnombre)==0){
            encontrado = true;
            cout<<"\n\tNuevo nombre: ";
            cin.getline(contactos.nombres, sizeof(contactos.nombres));
            cout<<"\n\tNuevo apellido: ";
            cin.getline(contactos.apellidos, sizeof(contactos.apellidos));
            cout<<"\n\tNuevo correo: ";
            cin.getline(contactos.correo, sizeof(contactos.correo));
            cout<<"\n\tNuevo numero: ";
            cin>>contactos.numero;
        }
        fwrite(&contactos, sizeof(contactos),1, tempFile);
    }
    fclose(fp);
    fclose(tempFile);

    if(encontrado){
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt","Biblioteca.txt");
        cout<<"\n\tDatos fueron actualizados...";
    }else{
        cout<<"\n\tDatos no fueron actualizados...";
    }

	}
	void EditarContactos3(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;

    system("cls");
    cout<<"\n\n\n\t\tActualiar Datos de un Contacto\n";
    cout<<"\n\tIngrese el correo del contacto a actualizar: ";
    cin.ignore();
    cin.getline(buscarnombre, sizeof(buscarnombre));

    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");

    while(fread(&contactos, sizeof(contactos),1,fp)==1){
        if(strcmp(contactos.correo,buscarnombre)==0){
            encontrado = true;
            cout<<"\n\tNuevo nombre: ";
            cin.getline(contactos.nombres, sizeof(contactos.nombres));
            cout<<"\n\tNuevo apellido: ";
            cin.getline(contactos.apellidos, sizeof(contactos.apellidos));
            cout<<"\n\tNuevo correo: ";
            cin.getline(contactos.correo, sizeof(contactos.correo));
            cout<<"\n\tNuevo numero: ";
            cin>>contactos.numero;
        }
        fwrite(&contactos, sizeof(contactos),1, tempFile);
    }
    fclose(fp);
    fclose(tempFile);

    if(encontrado){
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt","Biblioteca.txt");
        cout<<"\n\tDatos fueron actualizados...";
    }else{
        cout<<"\n\tDatos no fueron actualizados...";
    }

	}
	
void EliminarContactos1(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;

    system("cls");
    cout<<"\n\n\n\t\tEliminar un contactos\n";
    cout<<"\n\tIngrese el nombre del contacto a eliminar: ";
    cin.ignore();
    cin.getline(buscarnombre,sizeof(buscarnombre));

    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");

    while (fread(&contactos,sizeof(contactos),1,fp)==1) {
        if(strcmp(contactos.nombres,buscarnombre)==0) {
            encontrado=true;
            cout<<"\n\tContacto Eliminado";
        } else {
            fwrite(&contactos,sizeof(contactos),1,tempFile);
        }
    }

    fclose(fp);
    fclose(tempFile);

    if(encontrado==true) {
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt", "Biblioteca.txt");
        cout<<"\n\tDatos fueron eliminados....";
    }else {
        cout<<"\n\tDatos no fueron eliminados: ....";
    }
} 
void EliminarContactos2(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;

    system("cls");
    cout<<"\n\n\n\t\tEliminar un contactos\n";
    cout<<"\n\tIngrese el apellido del contacto a eliminar: ";
    cin.ignore();
    cin.getline(buscarnombre,sizeof(buscarnombre));

    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");

    while (fread(&contactos,sizeof(contactos),1,fp)==1) {
        if(strcmp(contactos.apellidos,buscarnombre)==0) {
            encontrado=true;
            cout<<"\n\tContacto Eliminado";
        } else {
            fwrite(&contactos,sizeof(contactos),1,tempFile);
        }
    }

    fclose(fp);
    fclose(tempFile);

    if(encontrado==true) {
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt", "Biblioteca.txt");
        cout<<"\n\tDatos fueron eliminados....";
    }else {
        cout<<"\n\tDatos no fueron eliminados: ....";
    }
} 
void EliminarContactos3(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;

    system("cls");
    cout<<"\n\n\n\t\tEliminar un contactos\n";
    cout<<"\n\tIngrese el correo del contacto a eliminar: ";
    cin.ignore();
    cin.getline(buscarnombre,sizeof(buscarnombre));

    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");

    while (fread(&contactos,sizeof(contactos),1,fp)==1) {
        if(strcmp(contactos.correo,buscarnombre)==0) {
            encontrado=true;
            cout<<"\n\tContacto Eliminado";
        } else {
            fwrite(&contactos,sizeof(contactos),1,tempFile);
        }
    }

    fclose(fp);
    fclose(tempFile);

    if(encontrado==true) {
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt", "Biblioteca.txt");
        cout<<"\n\tDatos fueron eliminados....";
    }else {
        cout<<"\n\tDatos no fueron eliminados: ....";
    }
} 


