/*
Uriel Montejano Briano 177771
Bruno Axel Puente Luna 177876
Universidad Politécnica de San Luis Potosí
16/11/2022
*/

#include "libreria.h"

int login(Usuario *primero,string usuario,string contrasena){
	struct Usuario *login=primero;
	int opc;
	while(login!=NULL){
		if((usuario==login->username) and (contrasena==login->pass) and (login->perfil==Administrador)){
			fflush(stdin);
			system("cls");
			menuadmin(login->nombre);
			break;
		}
		if((usuario==login->username) and (contrasena==login->pass) and (login->perfil==Ejecutivo)){
			fflush(stdin);
			system("cls");
			menuejec(login->nombre);
			break;
		}
		if(login==NULL){
			break;
		}
		login=login->sig;
	}
}

int main(){
	PrincipioMenu();
	
	primLista=NULL;
	ultLista=NULL;
	
	primListacli=NULL;
	ultListacli=NULL;
	
	lecturaLista();
	lecturaListaCli();
	
	int cont=0,hold=1,opc;
	while(hold==1){
		system("cls");
		decoprint();
		cuadrologin();
		string usuario,contrasena;
		gotoxy(50,12);
		cout<<"Usuario: ";
		cin>>usuario;
		gotoxy(50,14);
		cout<<"Contraseña: ";
		cin>>contrasena;
		
		struct Listas *aux=primLista;	
		while(aux!=NULL){
			check=login(aux->lista,usuario,contrasena);
			aux=aux->sig;
		}
		if(check==false){
			cout<<"Ingrese un usuario valido"<<endl;
		}
		if(check==true){
			cout<<"Hasta luego"<<endl;
		}
		aux=primLista;
		system("cls");
		decoprint();
		cuadrologin();
		gotoxy(50,12);
		cout<<"1.-Ingresar a una cuenta"; gotoxy(50,13); cout<<"2.-Salir"; gotoxy(50,14);cout<<"R= ";
		cin>>opc;
		switch(opc){
			case 1:
				{
					hold=1;
					break;
				}
			case 2:
				{
					hold=0;
					break;
				}
			default:
				{
					cout<<"Ingrese una opcion valida"<<endl;
					break;
				}
		}
	}
	return 0;
}
