//Registro de datos listita
Usuario *registro(){
	decomain();
	int opc,hold=1,ase; //*
	srand (time(NULL));
	Usuario *nuevo = new Usuario;
	
	bool bandera = true; //*
	while(bandera){
		nuevo->idUsuario=1000+rand()%(9999-1000)+1;
		if(ase != 0){
			Usuario *auxiliar = primero;
			while(auxiliar!=NULL){
				if(nuevo->idUsuario != auxiliar->idUsuario){
					auxiliar = auxiliar->sig;
					bandera = false;
				}else{
					bandera = true;
					break;
				}
			}
		}else{
			bandera=false;
		}
	} //*
	
	gotoxy(45,5);
	cout<<"Nombre: ";
	cin>>nuevo->nombre;
	gotoxy(45,6);
	cout<<"Apellido: ";
	cin>>nuevo->apellido;
	gotoxy(45,7);
	nuevo->edad=validaEntero("Edad: ");
	gotoxy(45,7);
	gotoxy(45,8);
	cout<<"Telefono: "; 
	cin>>nuevo->telefono;
	gotoxy(45,9);
	cout<<"Correo electronico: ";
	cin>>nuevo->correo;
	gotoxy(45,10);
	cout<<"Direccion: ";
	cin>>nuevo->dir;
	fflush(stdin);
	gotoxy(45,11);
	cout<<"Username: ";
	cin>>nuevo->username;
	gotoxy(45,12);
	cout<<"Password: ";
	cin>>nuevo->pass;
	nuevo->estado="Activo";
	while(hold==1){
		gotoxy(45,14);
		cout<<"Perfil: ";gotoxy(45,13);cout<<"1.-Administrador";gotoxy(45,14);cout<<"2.-Ejecutivo";gotoxy(45,15);cout<<"R= ";
		cin>>opc;
		gotoxy(40,28);
		cout<<"                                               ";
		switch(opc){
			case 1:
				{
					nuevo->perfil=Administrador;
					hold=0;
					break;
				}
			case 2:
				{
					nuevo->perfil=Ejecutivo;
					hold=0;
					break;
				}
			default:
				{
					gotoxy(45,28);
					cout<<"Ingrese una opcion valida"<<endl;
					break;
				}
		}
	}
	
	nuevo->sig=NULL;
	ase=1;
	return nuevo;
}

//_______________________________________________________________________
void agregarFinal(){
	Usuario *nuevo = registro();
	Usuario *aux = NULL;
	if(primero==NULL){
		primero=nuevo;
	}
	else{
		aux=primero;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
	}
}

void agregarFinalmod(Usuario *primero){
	system("cls");
	Usuario *nuevo = registro();
	Usuario *aux = primero;
	if(primero==NULL){
		primero=nuevo;
	}
	else{
		aux=primero;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}	
		aux->sig=nuevo;
	}
	system("cls");
}


void agregarAlistita(Usuario *primero){
	system("cls");
	decomain();
	struct Usuario *auxiliar=primero;
	bool bandera=true;
	int pos = 0;
	int i = 1;
	gotoxy(45,5);
	pos = validaEntero("Posicion: ");
	if(pos==1){
		Usuario *nuevo = registro();
		nuevo->sig=primero;
		primero=nuevo;
	}else{
		while(auxiliar!=NULL){
			if(i == (pos-1) ){
				Usuario *nuevo = registro();
				nuevo->sig = auxiliar->sig;
				auxiliar->sig = nuevo;
				bandera=false;
				break;	
			}else{
				auxiliar = auxiliar->sig;
				i++;
			}
		}
		if(bandera){
			gotoxy(30,28);
			cout<<"La posicion NO existe, el nodo se agrega al final de la lista"<<endl;
			getch();
			agregarFinalmod(primero);
		}
	}
	getchar();
}

//_______________________________________________________________________
//Escritura de archivos (listitas)
void archivoEscritura(Usuario *primero,int id){
	Usuario *aux=primero;
	char arch[20];
	itoa(id,arch,10);
	strcat(arch,".xls");
	ofstream archivo(arch);
	
	while(aux!=NULL){
		archivo<<aux->idUsuario<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->apellido<<"\t";
		archivo<<aux->edad<<"\t";
		archivo<<aux->telefono<<"\t";
		archivo<<aux->correo<<"\t";
		archivo<<aux->dir<<"\t";
		archivo<<aux->username<<"\t";
		archivo<<aux->pass<<"\t";
		archivo<<aux->estado<<"\t";		
		archivo<<aux->perfil<<endl;
		ultimo=aux;
		aux=aux->sig;
	}
	archivo.close();
}

void modificalistita(Usuario *primero, int estado,int aa){
	struct Usuario *auxiliar=primero;
	int folmod,op,hold=1,mod=1,bb=aa+3,opc;
	
	gotoxy(45,aa+3);
	cout<<"ID's de la lista seleccionada";
	while(primero!=NULL){
		bb+=1;
		gotoxy(45,bb);
		cout<<primero->idUsuario<<" -----> "<<primero->nombre;
		primero=primero->sig;
	}

		while(mod==1){
		gotoxy(45,bb+1);
		folmod=validaEntero("Selecciona el ID del Usuario a modificar: ");
		gotoxy(3,28);
		cout<<"                                           ";
		bool bandera = true;
		while(bandera){
		primero=auxiliar;
			while(primero!=NULL){
				if(folmod != primero->idUsuario){
					primero=primero->sig;
					bandera=false;
				}else{
					bandera = true;
					break;
				}
			}
			if(bandera==false){
				gotoxy(3,28);
				cout<<"El ID no esta registrado"<<endl;
			}else{
				bandera=false;
				mod=2;
			}
		}
	}
	system("cls");
	decomain();
	hold=1;
	while(auxiliar!=NULL){
		if(auxiliar->idUsuario==folmod){
			if(estado==1){
				gotoxy(45,3);
				cout<<"Nombre: ";
				cin>>auxiliar->nombre;
				gotoxy(45,4);
				cout<<"Apellido: ";
				cin>>auxiliar->apellido;
				gotoxy(45,5);
				auxiliar->edad=validaEntero("Edad: ");
				gotoxy(45,6);
				cout<<"Telefono: ";
				cin>>auxiliar->telefono;
				gotoxy(45,7);
				cout<<"Correo electronico: ";
				cin>>auxiliar->correo;
				gotoxy(45,8);
				cout<<"Direccion: ";
				cin>>auxiliar->dir;
				gotoxy(45,9);
				cout<<"Username: ";
				cin>>auxiliar->username;
				gotoxy(45,10);
				cout<<"Password: ";
				cin>>auxiliar->pass;
				
				while(hold==1){
				gotoxy(45,12);
				cout<<"Perfil: ";gotoxy(45,13);cout<<"1.-Administrador";gotoxy(45,14);cout<<"2.-Ejecutivo";gotoxy(45,15);cout<<"R= ";
				cin>>opc;
				gotoxy(40,28);
				cout<<"                                               ";
				switch(opc){
					case 1:
						{
							auxiliar->perfil=Administrador;
							hold=0;
							break;
						}
					case 2:
						{
							auxiliar->perfil=Ejecutivo;
							hold=0;
							break;
						}
					default:
						{
							gotoxy(45,28);
							cout<<"Ingrese una opcion valida"<<endl;
							break;
						}
					}
				}
			}
			if(estado==2){
				gotoxy(45,10);
				cout<<"Estado del usuario: ";
				cin>>auxiliar->estado;
			}			
		}	
		auxiliar=auxiliar->sig;
	}
	system("cls");
}

//Modificar datos de una lista
void ModificarList(int estado,int dpn){
	Usuario *aux = NULL;
	Listas *auxListota=primLista;
	int listmod,folmod,mod=1,aa=3;
	
	decomain();
	gotoxy(45,3);
	cout<<"Id de Listas";
	while(auxListota!=NULL){
		aa+=1;
		gotoxy(45,aa);
		cout<<auxListota->idListas<<endl;
		auxListota=auxListota->sig;
	}

	while(mod==1){
		gotoxy(45,aa+1);
		listmod=validaEntero("Selecciona la LISTOTA a modificar: ");
		gotoxy(44,28);
		cout<<"                             ";
		bool bandera = true;
		while(bandera){
			auxListota=primLista;
				while(auxListota!=NULL){
					if(listmod != auxListota->idListas){
						auxListota=auxListota->sig;
						bandera=false;
					}else{
						bandera = true;
						break;
					}
				}
				if(bandera==false){
					gotoxy(45,28);
					cout<<"El ID no esta registrado"<<endl;
				}else{
					bandera=false;
					mod=2;
				}
			}
		}
	
	auxListota=primLista;
	
	while(auxListota!=NULL){
		if(auxListota->idListas==listmod){
			break;
		}
		auxListota=auxListota->sig;
	}	
	if(dpn==1){
		modificalistita(auxListota->lista,estado,aa);
	}
	
	if(dpn==2){
		agregarAlistita(auxListota->lista);
	}
	archivoEscritura(auxListota->lista, auxListota->idListas);
}

//Lectura de datos
Usuario *archivoLectura(int id){
	Usuario *primero=NULL;
	Usuario *aux=NULL;
	Usuario *nuevo=NULL;

	char archivo[20];
	itoa(id,archivo,10);
	strcat(archivo,".xls");

	ifstream arch(archivo);
	string linea, c;
	
	cout<<id<<endl;
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch,linea)){
			nuevo = new Usuario;
			stringstream lee(linea);
			
			lee>>nuevo->idUsuario;
			getline(lee,c,'\t');
			getline(lee,nuevo->nombre,'\t');
			getline(lee,nuevo->apellido,'\t');
			lee>>nuevo->edad;
			getline(lee,c,'\t');
			lee>>nuevo->telefono;
			getline(lee,c,'\t');
			getline(lee,nuevo->correo,'\t');
			getline(lee,nuevo->dir,'\t');
			getline(lee,nuevo->username,'\t');
			getline(lee,nuevo->pass,'\t');
			getline(lee,nuevo->estado,'\t');
			getline(lee,nuevo->perfil,'\n');
			
			nuevo->sig=NULL;
			if(primero==NULL){
				primero = nuevo;
			}else{
				aux=primero;
				while(aux->sig!=NULL){
					aux=aux->sig;
				}
				aux->sig=nuevo;
			}
		}
	}
	arch.close();
	return primero;
}

void escrituraListatxt(){
	Listas *aux=primLista;
	
	ofstream archivo("ListaDeusuarios.txt");
	while(aux!=NULL){
		archivo<<aux->idListas<<"\n";
		aux=aux->sig;
	}
	archivo.close();
}

//Lectura de LISTOTAS
void lecturaLista(){
	Listas *nuevo=NULL;
	
	ifstream arch("ListaDeusuarios.txt");
	string linea, c;
	
	if(arch.fail()) cerr<<"No se encuentra ninguna lista"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo=new Listas;
			stringstream lee(linea);
			
			lee>>nuevo->idListas;
			getline(lee,c,'\n');
			
			nuevo->lista=archivoLectura(nuevo->idListas);
			
			nuevo->sig=NULL;
			
			if(primLista==NULL){
				primLista=nuevo;
				ultLista=nuevo;
			}
			else{
				ultLista->sig=nuevo;
				ultLista=nuevo;
			}
		}
	}
	arch.close();	
}

//Mostrar listitas
void mostrar_lista(Usuario *primero){
	struct Usuario *auxiliar=primero;
	cout<<" \n"<<endl;
	cout<<"Mostrando la lista completa"<<endl;
	SetConsoleTextAttribute(hd, 12);
	cout<<"--ID--"<<setw(11);
	cout<<"Nombre"<<setw(15);
	cout<<"Apellido"<<setw(11);
	cout<<"Edad"<<setw(15);
	cout<<"Telefono"<<setw(20);
	cout<<"Correo"<<setw(20);
	cout<<"Direccion"<<setw(20);
	cout<<"Username"<<setw(15);
	cout<<"Password"<<setw(15);
	cout<<"Estado"<<setw(13);
	cout<<"Perfil"<<endl;
	
	SetConsoleTextAttribute(hd, 9);
	while(auxiliar!=NULL){
		cout<<auxiliar->idUsuario<<setw(11);
		cout<<auxiliar->nombre<<setw(15);
		cout<<auxiliar->apellido<<setw(11);
		cout<<auxiliar->edad<<setw(15);
		cout<<auxiliar->telefono<<setw(20);
		cout<<auxiliar->correo<<setw(20);
		cout<<auxiliar->dir<<setw(20);
		cout<<auxiliar->username<<setw(15);
		cout<<auxiliar->pass<<setw(15);
		cout<<auxiliar->estado<<setw(13);
		cout<<auxiliar->perfil<<endl;
		auxiliar=auxiliar->sig;
	}	
}

//Mostrar LISTOTA
void mostrar_listas(){
	system("cls");
	struct Listas *aux=primLista;	
	
	aux=primLista;
	while(aux!=NULL){
		SetConsoleTextAttribute(hd, 10);
		cout<<endl<<"ID de la lista: "<<aux->idListas;
		mostrar_lista(aux->lista);
		aux=aux->sig;
	}
	getch();
}

//Agregar LISTOTA
void agregarLista(){
	srand (time(NULL));
	Listas *nuevo = new Listas;

	cout<<"Agregando lista a la LISTA"<<endl;
	
	int ase;//*
	bool bandera = true; 
	while(bandera){
		nuevo->idListas=10000+rand()%(99999-10000)+1;
		if(ase != 0){
			Listas *auxiliar = primLista;
			while(auxiliar!=NULL){
				if(nuevo->idListas!= auxiliar->idListas){
					auxiliar = auxiliar->sig;
					bandera = false;
				}else{
					bandera = true;
					break;
				}
			}
		}else{
			bandera=false;
		}
	} //*

	int sigue=1;
	
	primero=NULL;
	ultimo=NULL;
	while(sigue==1){
		system("cls");
		decomain();
		agregarFinal();
		gotoxy(45,26);
		sigue = validaEntero("Tecla 1 para agregar otro: ");
		system("cls");
	}
	
	nuevo->sig=NULL;
	nuevo->lista=primero;
	archivoEscritura(primero, nuevo->idListas);
	
	if(primLista==NULL){
		primLista=nuevo;
		ultLista=nuevo;
	}else{
		ultLista->sig=nuevo;
		ultLista=nuevo;
		
	}
}
//_________________________Its a secret__________________________________________
void direccioneschiquitas(Usuario *primero){
	struct Usuario *auxiliar=primero;
	cout<<" \n"<<endl;
	SetConsoleTextAttribute(hd, 12);
	cout<<"Ubicacion"<<setw(10);
	cout<<"--ID--"<<setw(11);
	cout<<"Nombre"<<setw(15);
	cout<<"Estado"<<setw(13);
	cout<<"Perfil"<<setw(20);
	cout<<"Siguiente"<<endl;
	
	SetConsoleTextAttribute(hd, 9);
	while(auxiliar!=NULL){
		cout<<auxiliar<<setw(10);
		cout<<auxiliar->idUsuario<<setw(11);
		cout<<auxiliar->nombre<<setw(15);
		cout<<auxiliar->estado<<setw(13);
		cout<<auxiliar->perfil<<setw(20);
		cout<<auxiliar->sig<<endl;
		auxiliar=auxiliar->sig;
	}	
	
	cout<<endl<<"Primer nodo: "<<primero;
	auxiliar=primero;
	while(auxiliar->sig!=NULL){
		auxiliar=auxiliar->sig;
	}	
	cout<<endl<<"Ultimo nodo: "<<auxiliar;
	
	getch();
	system("cls");
}
void direcciones(){
	system("cls");
	struct Listas *aux=primLista;
	cout<<"Ubicacion Lista: "<<setw(20);
	cout<<"Lista(Pimer nodo): "<<setw(20);
	cout<<"Siguiente: "<<endl;
	
	while(aux!=NULL){
		cout<<aux<<setw(20);
		cout<<aux->lista<<setw(20);
		cout<<aux->sig<<endl;
		aux=aux->sig;
	}
	cout<<endl<<"Primer LISTA: "<<primLista;
	cout<<endl<<"Ultima LISTA: "<<ultLista;
	
	aux=primLista;
	while(aux!=NULL){
		cout<<endl<<"ID de la lista: "<<aux->idListas;
		direccioneschiquitas(aux->lista);
		aux=aux->sig;
	}
}
//________________________________________________________________________________

//Menu administrador
void menuadmin(string name){
	system("cls");
	int op=1;
	decomain();
	gotoxy(40,10);
	cout<<"--->Bienvenido Aministrador "<<name<<"<---";
	while(op!=0){
		decomain();
		gotoxy(40,12);
		cout<<"1.- Consultar Listas";gotoxy(40,13);cout<<"2.-Agregar Nueva lista";gotoxy(40,14);cout<<"3.-Modificar registro completo";gotoxy(40,15);cout<<"4.-Agregar registro a una lista";gotoxy(40,16);cout<<"5.-Cambiar estado de cuenta";gotoxy(40,17);cout<<"0.-Salir";
		gotoxy(40,18);
		op = validaEntero("Que desea hacer: ");
		switch(op){
			case 1:
				{
					system("cls");
					mostrar_listas();
					system("cls");
					break;
				}
			case 2:
				{
					system("cls");
					decomain();
					agregarLista();
					escrituraListatxt();
					break;	
				}
			case 3:
				{
					system("cls");
					ModificarList(1,1);
					break;
				}
			case 4:
				{
					system("cls");
					ModificarList(1,2);
					break;
				}
			case 5:
				{
					system("cls");
					ModificarList(2,1);
					break;
				}
			case 0:
				{
					system("cls");
					break;
				}
			case 2428:
				{
					system("cls");
					direcciones();
					break;
				}
			default:
				{
					cout<<"Ingrese una opcion valida"<<endl;
				}
		}
		
	}
}


//Menu ejecutivo
void menuejec(string name){
	system("cls");
	int op=1;
	decomain();
	gotoxy(40,10);
	cout<<"--->Bienvenido Ejecutivo "<<name<<"<---";
	while(op!=0){
		decomain();
		gotoxy(40,12);
		cout<<"1.- Consultar Listas de clientes";gotoxy(40,13);cout<<"2.- Registrar nueva lista";gotoxy(40,14);cout<<"3.- Modificar datos del cliente";gotoxy(40,15);cout<<"4.- Agregar registro a una lista";gotoxy(40,16);cout<<"5.- Cambiar estado de un contrato";gotoxy(40,17);cout<<"0.-Salir";
		gotoxy(40,18);
		op = validaEntero("Que desea hacer: ");
		switch(op){
			case 1:
				{
					system("cls");
					mostrar_listasCli();
					system("cls");
					break;
				}
			case 2:
				{
					system("cls");
					agregarListaCli();
					escrituraListaClitxt();
					break;	
				}
			case 3:
				{
					system("cls");
					ModificarListCli(1,1);
					break;
				}
			case 4:
				{
					system("cls");
					ModificarListCli(1,2);
					break;
				}
			case 5:
				{
					system("cls");
					ModificarListCli(2,1);
					break;
				}
			case 2428:
				{
					system("cls");
					Direccionescli();
					break;
				}
			case 0:
				{
					system("cls");
				//	printf("Hasta pronto");
					break;
				}
			default:
				{
					cout<<"Inserte una opcion valida"<<endl;
					break;
				}
		}	
	}
}


//--------------------------------------------------------------------------
