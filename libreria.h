#include <iostream> //cout, cin, fixed, endl
#include <stdlib.h> //malloc
#include <iomanip> //setw
#include <locale.h> //setlocale
#include <windows.h> //SetConsole
#include <string> //string
#include <fstream> //para ifstream
#include <stdio.h>//
#include <time.h>//
#include <conio.h>//
#include <ctype.h>//
#include <string.h>//
#include <istream>
#include <sstream>

using namespace std;

string estado="Activo",Ahorro="Ahorro",Credito="Credito",Debito="Debito",Creditohipotecario="Cre_hipo",ahorradOR="ahorrador",Ahorrador="Ahorrador",deudOR="deudor",DEudor="Deudor",Activo="Activo",Inactivo="Inactivo",En_Deuda="En deuda",Cancelado="Cancelado",Sin_Deuda="Sin Deuda",Administrador="Administrador",Ejecutivo="Ejecutivo";
int long long cardnumber;
bool check;

struct Usuario{
	int idUsuario;
	string nombre;
	string apellido;
	int edad;
	string telefono;
	string correo;
	string dir;
	string username;
	string pass;
	string estado;
	string perfil;
	
	Usuario *sig; 
}*primero, *ultimo;

struct Contrato{
	string estadoContra;
	string tipClien;
	string tipotarcli;
	string hipotecaref;
	string fechaA;
	float CanAhorro;
	int interes;
	float prestamo;
	float anio;
	//float mes;
};

struct Cliente{
	int idCliente;
	string nombrecli;
	string apellidocli;
	string telefonocli;
	string refecli;
	string tel_refecli;
	int long long tarjetacli;
	Contrato deal;
	
	Cliente *next; 
}*primerocli, *ultimocli;

struct Listas{
	int idListas;
	Usuario *lista;
	Listas *sig;
}*primLista, *ultLista;

struct ListasClientes{
	int idListasCli;
	Cliente *listacli;
	ListasClientes *next;
}*primListacli, *ultListacli;

HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x,int y)
 { 
 HANDLE hcon; 
 hcon = GetStdHandle(STD_OUTPUT_HANDLE); 
 COORD dwPos; 
 dwPos.X = x; 
 dwPos.Y= y; 
 SetConsoleCursorPosition(hcon,dwPos); 
 }
 
 
#include "validacion.h"
#include "decoracion.h"
#include "archivosCli.h"
#include "archivos.h"
