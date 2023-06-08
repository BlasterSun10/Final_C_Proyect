int generartarjeta(){
    int i;
    srand (time(NULL));
    cardnumber = rand() % 9 + 1;
    for (i = 0; i < 15; i++)
    {
        cardnumber *= 10;
        cardnumber += rand() % 10;
    }
    return cardnumber;
}

void makedeal(Cliente *trato){
	int opc,hold=1;
	trato->deal.estadoContra=estado;
	
	while(hold==1){
		gotoxy(44,25);
		cout<<"                                                      ";
		gotoxy(45,10);
		cout<<"Tipo de cliente:";gotoxy(45,11);cout<<"1.-Ahorrador";gotoxy(45,12);cout<<"2.-Deudor";gotoxy(45,13);cout<<"R= ";
		cin>>opc;
		switch(opc){
			case 1:
				{
					trato->deal.tipClien=Ahorrador;
					hold=0;
					break;
				}
			case 2:
				{
					trato->deal.tipClien=DEudor;
					hold=0;
					break;
				}
			default:
				{
					gotoxy(45,25);
					cout<<"Inserte una opcion valida";
					break;
				}
		}
	}
	
	opc=0;
	hold=1;
	gotoxy(45,14);
	cout<<"Fecha: ";
	cin>>trato->deal.fechaA;
	do{
		gotoxy(44,28);
		cout<<"                                                          ";
		fflush(stdin);
		gotoxy(45,15);
		cout<<"Tipo de tarjeta del cliente: ";
		gotoxy(45,16);
		cout<<"1.-Ahorro";gotoxy(45,17);cout<<"2.-Credito";gotoxy(45,18);cout<<"3.-Debito";gotoxy(45,19);cout<<"4.-Credito hipotecario";gotoxy(45,20);cout<<"R= ";
		cin>>opc;
		switch(opc){
			case 1:
				{
					trato->deal.prestamo=0;
					trato->deal.tipotarcli=Ahorro;
					gotoxy(45,21);
					trato->deal.CanAhorro=validaFlotante("Cantidad a ahorrar: ");
					trato->deal.interes=10;
					gotoxy(45,22);
					cout<<"Interes sobre ahorro es del 10% por mes";
					trato->deal.anio=0.1*trato->deal.CanAhorro;
					gotoxy(45,23);
					cout<<"Cantidad acumulada dentro de un año: $"<<trato->deal.anio;
					hold=0;
					break;
				}
			case 2:
				{
					trato->deal.CanAhorro=0;
					trato->deal.tipotarcli=Credito;
					fflush(stdin);
					gotoxy(45,21);
					trato->deal.prestamo=validaFlotante("Cantidad de prestamo: ");
					trato->deal.interes=15;
					gotoxy(45,22);
					cout<<"Interes de credito es del 15% por mes";
					trato->deal.anio=0.15*trato->deal.prestamo;
					gotoxy(45,23);
					cout<<"Cantidad de cobro anual por uso de la tarjeta: $"<<trato->deal.anio;
					hold=0;
					break;
				}
			case 3:
				{
					trato->deal.tipotarcli=Debito;
					hold=0;
					break;
				}
			case 4:
				{
					trato->deal.CanAhorro=0;
					trato->deal.tipotarcli=Creditohipotecario;
					gotoxy(45,21);
					cout<<"Que bien va a hipotecar el cliente?: ";
					cin>>trato->deal.hipotecaref;
					gotoxy(45,22);
					trato->deal.prestamo=validaEntero("Valor del avaluo dado: ");
					trato->deal.interes=20;
					gotoxy(45,23);
					cout<<"Interes de la hipoteca es del 20% por mes";
					trato->deal.anio=0.20*trato->deal.prestamo;
					gotoxy(45,24);
					cout<<"Cantidad de cobro anual por la hipoteca: $"<<trato->deal.anio;
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
	}while(hold==1);
	getch();
	system("cls");
	decomain();
	fflush(stdin);
}

Cliente *registroCli(){
	Cliente *nuevo = new Cliente;
	decomain();
	srand (time(NULL));
	fflush(stdin);
	
	int ase;//*
	bool bandera = true; 
	while(bandera){
		nuevo->idCliente=1000+rand()%(9999-1000)+1;
		if(ase != 0){
			Cliente *auxiliar = primerocli;
			while(auxiliar!=NULL){
				if(nuevo->idCliente!= auxiliar->idCliente){
					auxiliar = auxiliar->next;
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
	cin>>nuevo->nombrecli;
	gotoxy(45,6);
	cout<<"Apellido: ";
	fflush(stdin);
	cin>>nuevo->apellidocli;
	gotoxy(45,7);
	cout<<"Telefono: ";
	fflush(stdin);
	cin>>nuevo->telefonocli;
	gotoxy(45,8);
	cout<<"Referencia: ";
	fflush(stdin);
	cin>>nuevo->refecli;
	gotoxy(45,9);
	cout<<"Telefono de referencia: ";
	fflush(stdin);
	cin>>nuevo->tel_refecli;
	//----------------randtarjeta-------------------
	generartarjeta();
	nuevo->tarjetacli=cardnumber;
	//----------------------------------------------

	makedeal(nuevo);
	nuevo->next=NULL;
	return nuevo;
}

void agregarFinalCli(){
	Cliente *nuevo = registroCli();
	Cliente *aux = primerocli;
	if(primerocli==NULL){
		primerocli=nuevo;
	}
	else{
		aux=primerocli;
			while(aux->next!=NULL)
				aux=aux->next;
				
		aux->next=nuevo;
	}
}

void agregarFinalClimod(Cliente *primerocli){
	Cliente *nuevo = registroCli();
	Cliente *aux = primerocli;
	if(primerocli==NULL){
		primerocli=nuevo;
	}
	else{
		aux=primerocli;
			while(aux->next!=NULL)
				aux=aux->next;
				
		aux->next=nuevo;
	}
}

void agregarAlistitaCli(Cliente *primerocli){
	system("cls");
	decomain();
	struct Cliente *auxiliar=primerocli;
	bool bandera=true;
	int pos = 0;
	int i = 1;
	gotoxy(45,5);
	pos = validaEntero("Posicion: ");
	system("cls");
	if(pos==1){
		Cliente *nuevo = registroCli();
		nuevo->next=primerocli;
		primerocli=nuevo;
	}else{
		while(auxiliar!=NULL){
			if(i == (pos-1) ){
				Cliente *nuevo = registroCli();
				nuevo->next = auxiliar->next;
				auxiliar->next = nuevo;
				bandera=false;
				break;	
			}else{
				auxiliar = auxiliar->next;
				i++;
			}
		}
		if(bandera){
			gotoxy(30,28);
			cout<<"La posicion no existe, el nodo se agrega al final de la lista"<<endl;
			agregarFinalClimod(primerocli);
		}
	}
	getchar();
}

void archivoEscrituraCli(Cliente *primerocli,int id){
	Cliente *aux=primerocli;
	char arch[20];
	itoa(id,arch,10);
	strcat(arch,".xls");
	ofstream archivo(arch);
	
	while(aux!=NULL){
		archivo<<aux->idCliente<<"\t";
		archivo<<aux->nombrecli<<"\t";
		archivo<<aux->apellidocli<<"\t";
		archivo<<aux->telefonocli<<"\t";
		archivo<<aux->refecli<<"\t";
		archivo<<aux->tel_refecli<<"\t";
		archivo<<aux->tarjetacli<<"\t";
		
		archivo<<aux->deal.tipotarcli<<"\t";
		archivo<<aux->deal.estadoContra<<"\t";
		archivo<<aux->deal.fechaA<<"\t";
		archivo<<aux->deal.tipClien<<"\t";
		archivo<<aux->deal.CanAhorro<<"\t";
		archivo<<aux->deal.prestamo<<"\t";
		archivo<<aux->deal.interes<<"\t";
		archivo<<aux->deal.anio<<"\t";
		archivo<<aux->deal.hipotecaref<<endl;
		
		ultimocli=aux;
		aux=aux->next;
	}
	
	archivo.close();
}

void modificalistitaCli(Cliente *primerocli, int estado,int aa){
	struct Cliente *auxiliar=primerocli;
	int folmod,op,hold=1,mod=1,bb=aa+3;
	gotoxy(45,aa+3);
	cout<<"ID's de la lista seleccionada"<<endl;
	while(primerocli!=NULL){
		bb+=1;
		gotoxy(45,bb);
		cout<<primerocli->idCliente<<" -----> "<<primerocli->nombrecli<<endl;
		primerocli=primerocli->next;
	}
	//-------------------------------------------------------------------------
	while(mod==1){
		gotoxy(45,bb+1);
		folmod=validaEntero("Selecciona el ID del Usuario a modificar: ");
		gotoxy(45,28);
		cout<<"                                           ";
		bool bandera = true;
		while(bandera){
		primerocli=auxiliar;
			while(primerocli!=NULL){
				if(folmod != primerocli->idCliente){
					primerocli=primerocli->next;
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
	//-------------------------------------------------------------------------
	system("cls");
	decomain();
	primerocli=auxiliar;
	int opc;
	hold=1;
	while(auxiliar!=NULL){
		if(auxiliar->idCliente==folmod){
			if(estado==1){
				gotoxy(45,3);
				cout<<"Telefono Cliente: ";
				cin>>auxiliar->telefonocli;
				gotoxy(45,4);
				cout<<"Referencia: ";
				cin>>auxiliar->refecli;
				gotoxy(45,5);
				cout<<"Telefono Referencia: ";
				cin>>auxiliar->tel_refecli;
				gotoxy(45,6);
				while(hold==1){
					gotoxy(45,7);
					cout<<"Tipo de cliente:";gotoxy(45,8);cout<<"1.-Ahorrador";gotoxy(45,9);cout<<"2.-Deudor";gotoxy(45,10);cout<<"R= ";
					cin>>opc;
					switch(opc){
						case 1:
							{
								auxiliar->deal.tipClien=Ahorrador;
								hold=0;
								break;
							}
						case 2:
							{
								auxiliar->deal.tipClien=DEudor;
								hold=0;
								break;
							}
						default:
							{
								break;
							}
					}
				}
			}
			if(estado==2){
				while(hold==1){
					gotoxy(45,3);
					cout<<"Estado del contrato:";gotoxy(45,4);cout<<"1.-Activo";gotoxy(45,5);cout<<"2.-Inactivo";gotoxy(45,6);cout<<"3.-En deuda";gotoxy(45,7);cout<<"4.-Cancelado";gotoxy(45,8);cout<<"5.-Sin deuda";gotoxy(45,9);cout<<"R= ";
					cin>>op;
					switch(op){
						case 1:
							{
								auxiliar->deal.estadoContra=Activo;
								hold=0;
								break;
							}
						case 2:
							{
								auxiliar->deal.estadoContra=Inactivo;
								hold=0;
								break;
							}
						case 3:
							{
								auxiliar->deal.estadoContra=En_Deuda;
								hold=0;
								break;
							}
						case 4:
							{
								auxiliar->deal.estadoContra=Cancelado;
								hold=0;
								break;
							}
						case 5:
							{
								auxiliar->deal.estadoContra=Sin_Deuda;
								hold=0;
								break;
							}
						default:
							{
								break;
							}
					}
				}
			}
		}
		auxiliar=auxiliar->next;
	}
	system("cls");
}

void ModificarListCli(int estado,int dpn){
	Cliente *aux = NULL;
	ListasClientes *auxListota=primListacli;
	int listmod,folmod,mod=1,aa=3;
	
	decomain();
	gotoxy(45,3);
	cout<<"Id de Listas"<<endl;
	while(auxListota!=NULL){
		aa+=1;
		gotoxy(45,aa);
		cout<<auxListota->idListasCli<<endl;
		auxListota=auxListota->next;
	}
//------------------------------------------------------------------------------------------------
	while(mod==1){
		gotoxy(45,aa+1);
		listmod=validaEntero("Selecciona la LISTOTA a modificar: ");
		gotoxy(44,28);
		cout<<"                             ";
		bool bandera = true;
		while(bandera){
			auxListota=primListacli;
				while(auxListota!=NULL){
					if(listmod != auxListota->idListasCli){
						auxListota=auxListota->next;
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
	//-------------------------------------------------------------------------------------------
	auxListota=primListacli;
	
	while(auxListota!=NULL){
		if(auxListota->idListasCli==listmod){
			break;
		}
		auxListota=auxListota->next;
	}	
	if(dpn==1){
		modificalistitaCli(auxListota->listacli,estado,aa);
	}
	if(dpn==2){
		agregarAlistitaCli(auxListota->listacli);
	}
	archivoEscrituraCli(auxListota->listacli, auxListota->idListasCli);
}

Cliente *archivoLecturaCli(int id){
	Cliente *primerocli=NULL;
	Cliente *aux=NULL;
	Cliente *nuevo=NULL;

	char archivo[20];
	itoa(id,archivo,10);
	strcat(archivo,".xls");

	ifstream arch(archivo);
	string linea, c;

	cout<<id<<endl;
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch,linea)){
			nuevo = new Cliente;
			stringstream lee(linea);

			lee>>nuevo->idCliente;
			getline(lee,c,'\t');
			getline(lee,nuevo->nombrecli,'\t');
			getline(lee,nuevo->apellidocli,'\t');
			lee>>nuevo->telefonocli;
			getline(lee,c,'\t');
			getline(lee,nuevo->refecli,'\t');
			lee>>nuevo->tel_refecli;
			getline(lee,c,'\t');
			lee>>nuevo->tarjetacli;
			getline(lee,c,'\t');
			
			getline(lee,nuevo->deal.tipotarcli,'\t');
            getline(lee,nuevo->deal.estadoContra,'\t');
            getline(lee,nuevo->deal.fechaA,'\t');
            getline(lee,nuevo->deal.tipClien,'\t');
            
            lee>>nuevo->deal.CanAhorro;
            getline(lee,c,'\t');
            lee>>nuevo->deal.prestamo;
            getline(lee,c,'\t');
            lee>>nuevo->deal.interes;
            getline(lee,c,'\t');
            lee>>nuevo->deal.anio;
            getline(lee,c,'\t');
            getline(lee,nuevo->deal.hipotecaref,'\n');
			
			nuevo->next=NULL;
			
			if(primerocli==NULL){
				primerocli= nuevo;
				ultimocli=nuevo;
			}else{
				aux=primerocli;
				while(aux->next!=NULL)
					aux=aux->next;
				
				aux->next=nuevo;
			}
		}
	}
	arch.close();
	return primerocli;
}

void escrituraListaCli(){
	ListasClientes *aux=primListacli;
	
	ofstream archivo("ListaDeListasCli.xls");
	while(aux!=NULL){
		archivo<<aux->idListasCli<<"\n";
		aux=aux->next;
	}
	archivo.close();
}

void escrituraListaClitxt(){
	ListasClientes *aux=primListacli;
	
	ofstream archivo("ListaDeListasCli.txt");
	while(aux!=NULL){
		archivo<<aux->idListasCli<<"\n";
		aux=aux->next;
	}
	archivo.close();
}

void lecturaListaCli(){
	ListasClientes *nuevo=NULL;
	
	ifstream arch("ListaDeListasCli.txt");
	string linea, c;
	
	if(arch.fail()) cerr<<"No se encuentra ninguna lista"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo=new ListasClientes;
			stringstream lee(linea);
			
			lee>>nuevo->idListasCli;
			getline(lee,c,'\n');
			
			nuevo->listacli=archivoLecturaCli(nuevo->idListasCli);
			
			nuevo->next=NULL;
			
			if(primListacli==NULL){
				primListacli=nuevo;
				ultListacli=nuevo;
			}
			else{
				ultListacli->next=nuevo;
				ultListacli=nuevo;
			}
		}
	}
	arch.close();	
}

void mostrar_listaCli(Cliente *primerocli){
	struct Cliente *auxiliar=primerocli;
	cout<<" "<<endl;
	SetConsoleTextAttribute(hd, 12);
	cout<<"--ID--"<<setw(10);
	cout<<"Nombre"<<setw(15);
	cout<<"Apellido"<<setw(20);
	cout<<"Telefono"<<setw(15);
	cout<<"Referencia"<<setw(15);
	cout<<"Tel Ref"<<setw(21);
	cout<<"No. de tarjeta"<<setw(15);
	cout<<"Est Contrat"<<endl;

	SetConsoleTextAttribute(hd, 9);
	while(auxiliar!=NULL){
		cout<<auxiliar->idCliente<<setw(11);
		cout<<auxiliar->nombrecli<<setw(15);
		cout<<auxiliar->apellidocli<<setw(20);
		cout<<auxiliar->telefonocli<<setw(15);
		cout<<auxiliar->refecli<<setw(15);
		cout<<auxiliar->tel_refecli<<setw(21);
		cout<<auxiliar->tarjetacli<<setw(15);
		cout<<auxiliar->deal.estadoContra<<endl;
		auxiliar=auxiliar->next;
	}	
	
	cout<<" "<<endl;
}

void checarcontrato(Cliente *primerocli){
	struct Cliente *auxiliar=primerocli;
	cout<<" "<<endl;
	SetConsoleTextAttribute(hd, 12);
	cout<<"--ID--"<<setw(10);
	cout<<"Nombre"<<setw(15);
	cout<<"Fecha"<<setw(20);
	cout<<"No. de tarjeta"<<setw(20);
	cout<<"Tip Tarjeta"<<setw(12);
	cout<<"Prestamo"<<setw(15);
	cout<<"Est Contrato"<<setw(15);
	cout<<"Tip Cliente"<<setw(10);
	cout<<"Interes"<<setw(12);
	cout<<"IGA"<<setw(10);			//Ingreso generado en un año
	cout<<"DGA"<<setw(10);			//Deuda generada en un año
	cout<<"Hipoteca"<<endl;
	
	SetConsoleTextAttribute(hd, 9);
	while(auxiliar!=NULL){
		cout<<auxiliar->idCliente<<setw(10);
		cout<<auxiliar->nombrecli<<setw(15);
		cout<<auxiliar->deal.fechaA<<setw(20);
		cout<<auxiliar->tarjetacli<<setw(20);
		cout<<auxiliar->deal.tipotarcli<<setw(12);
		cout<<auxiliar->deal.prestamo<<setw(15);
		cout<<auxiliar->deal.estadoContra<<setw(15);
		cout<<auxiliar->deal.tipClien<<setw(10);
		cout<<auxiliar->deal.interes<<"%"<<setw(12);
		if((auxiliar->deal.tipClien==DEudor)||(auxiliar->deal.tipClien==deudOR)){
			cout<<" "<<setw(10);
			cout<<auxiliar->deal.anio<<setw(10);
		}else{
			cout<<auxiliar->deal.anio<<setw(10);
			cout<<" "<<setw(10);
		}
		cout<<auxiliar->deal.hipotecaref<<endl;
		auxiliar=auxiliar->next;
	}
	
	cout<<" "<<endl;
}

void filtrar(Cliente *primerocli,int DEAH){
	struct Cliente *auxiliar=primerocli;
	cout<<" "<<endl;
	SetConsoleTextAttribute(hd, 12);
	cout<<"--ID--"<<setw(10);
	cout<<"Nombre"<<setw(15);
	cout<<"Fecha"<<setw(20);
	cout<<"No. de tarjeta"<<setw(20);
	cout<<"Tip Tarjeta"<<setw(12);
	cout<<"Prestamo"<<setw(15);
	cout<<"Est Contrato"<<setw(15);
	cout<<"Tip Cliente"<<setw(10);
	cout<<"Interes"<<setw(12);
	cout<<"IGA"<<setw(10);			//Ingreso generado en un año
	cout<<"DGA"<<setw(10);			//Deuda generada en un año
	cout<<"Hipoteca"<<endl;
	if(DEAH==2){
		auxiliar=primerocli;
		if(auxiliar->deal.tipClien==DEudor){
			SetConsoleTextAttribute(hd, 9);
			while(auxiliar!=NULL){
				cout<<auxiliar->idCliente<<setw(10);
				cout<<auxiliar->nombrecli<<setw(15);
				cout<<auxiliar->deal.fechaA<<setw(20);
				cout<<auxiliar->tarjetacli<<setw(20);
				cout<<auxiliar->deal.tipotarcli<<setw(12);
				cout<<auxiliar->deal.prestamo<<setw(15);
				cout<<auxiliar->deal.estadoContra<<setw(15);
				cout<<auxiliar->deal.tipClien<<setw(10);
				cout<<auxiliar->deal.interes<<"%"<<setw(12);
				if((auxiliar->deal.tipClien==DEudor)||(auxiliar->deal.tipClien==deudOR)){
					cout<<" "<<setw(10);
					cout<<auxiliar->deal.anio<<setw(10);
				}else{
					cout<<auxiliar->deal.anio<<setw(10);
					cout<<" "<<setw(10);
				}
				cout<<auxiliar->deal.hipotecaref<<endl;
				auxiliar=auxiliar->next;
			}
			cout<<" "<<endl;
		}
	}
	if(DEAH==1){
		auxiliar=primerocli;
		if(auxiliar->deal.tipClien==Ahorrador){
			SetConsoleTextAttribute(hd, 9);
			while(auxiliar!=NULL){
				cout<<auxiliar->idCliente<<setw(10);
				cout<<auxiliar->nombrecli<<setw(15);
				cout<<auxiliar->deal.fechaA<<setw(20);
				cout<<auxiliar->tarjetacli<<setw(20);
				cout<<auxiliar->deal.tipotarcli<<setw(12);
				cout<<auxiliar->deal.prestamo<<setw(15);
				cout<<auxiliar->deal.estadoContra<<setw(15);
				cout<<auxiliar->deal.tipClien<<setw(10);
				cout<<auxiliar->deal.interes<<"%"<<setw(12);
				if((auxiliar->deal.tipClien==DEudor)||(auxiliar->deal.tipClien==deudOR)){
					cout<<" "<<setw(10);
					cout<<auxiliar->deal.anio<<setw(10);
				}else{
					cout<<auxiliar->deal.anio<<setw(10);
					cout<<" "<<setw(10);
				}
				cout<<auxiliar->deal.hipotecaref<<endl;
				auxiliar=auxiliar->next;
			}
			cout<<" "<<endl;
		}
	}
}

void mostrar_listasCli(){
	system("cls");
	struct ListasClientes *aux=primListacli;
	int opc,hold=1,aa=0;
	
	aux=primListacli;
	while(aux!=NULL){
		SetConsoleTextAttribute(hd, 10);
		cout<<endl<<"ID de la lista: "<<aux->idListasCli;
		mostrar_listaCli(aux->listacli);
		aa+=5;
		aux=aux->next;
	}
	
	do{
		gotoxy(40,aa+2);
		SetConsoleTextAttribute(hd, 14);
		cout<<"1.-Checar contratos";gotoxy(40,aa+3);cout<<"2.-Filtrar por Ahorradores";gotoxy(40,aa+4);cout<<"3.-Filtrar por Deudores";gotoxy(40,aa+5);cout<<"0.-Salir";gotoxy(40,aa+6);cout<<"R=";
		cin>>opc;
		aa=0;
		system("cls");
		switch(opc){
			case 1:
				{
					aux=primListacli;
					while(aux!=NULL){
						SetConsoleTextAttribute(hd, 10);
						cout<<endl<<"ID lista: "<<aux->idListasCli;
						checarcontrato(aux->listacli);
						aa+=7;
						aux=aux->next;
					}
					break;
				}
			case 2:
				{
					aux=primListacli;
					while(aux!=NULL){
						SetConsoleTextAttribute(hd, 10);
						cout<<endl<<"ID lista: "<<aux->idListasCli;
						filtrar(aux->listacli,1);
						aa+=7;
						aux=aux->next;
					}
					break;
				}
			case 3:
				{
					aux=primListacli;
					while(aux!=NULL){
						SetConsoleTextAttribute(hd, 10);
						cout<<endl<<"ID lista: "<<aux->idListasCli;
						filtrar(aux->listacli,2);
						aa+=7;
						aux=aux->next;
					}
					break;
				}
			case 0:
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
	}while(hold==1);
}

void agregarListaCli(){
	srand (time(NULL));
	ListasClientes *nuevo = new ListasClientes;

	int ase;//*
	bool bandera = true; 
	while(bandera){
		nuevo->idListasCli=10000+rand()%(99999-10000)+1;
		if(ase != 0){
			ListasClientes *auxiliar = primListacli;
			while(auxiliar!=NULL){
				if(nuevo->idListasCli!= auxiliar->idListasCli){
					auxiliar = auxiliar->next;
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
	
	primerocli=NULL;
	ultimocli=NULL;
	while(sigue==1){
		system("cls");
		decomain();
		agregarFinalCli();
		gotoxy(45,26);
		sigue = validaEntero("Tecla 1 para agregar otro: ");
		system("cls");
	}
	
	nuevo->next=NULL;
	nuevo->listacli=primerocli;
	archivoEscrituraCli(primerocli, nuevo->idListasCli);
	
	if(primListacli==NULL){
		primListacli=nuevo;
		ultListacli=nuevo;
	}else{
		ultListacli->next=nuevo;
		ultListacli=nuevo;
	}
}

void dirCli(Cliente *primerocli){
	struct Cliente *auxiliar=primerocli;
	cout<<" "<<endl;
	SetConsoleTextAttribute(hd, 12);
	cout<<"Ubicacion"<<setw(10);
	cout<<"--ID--"<<setw(10);
	cout<<"Nombre"<<setw(15);
	cout<<"Apellido"<<setw(20);
	cout<<"Telefono"<<setw(15);
	cout<<"Referencia"<<setw(15);
	cout<<"Tel Ref"<<setw(21);
	cout<<"No. de tarjeta"<<setw(15);
	cout<<"Est Contrat"<<setw(15);
	cout<<"Siguiente"<<endl;

	SetConsoleTextAttribute(hd, 9);
	while(auxiliar!=NULL){
		cout<<auxiliar<<setw(10);
		cout<<auxiliar->idCliente<<setw(11);
		cout<<auxiliar->nombrecli<<setw(15);
		cout<<auxiliar->apellidocli<<setw(20);
		cout<<auxiliar->telefonocli<<setw(15);
		cout<<auxiliar->refecli<<setw(15);
		cout<<auxiliar->tel_refecli<<setw(21);
		cout<<auxiliar->tarjetacli<<setw(15);
		cout<<auxiliar->deal.estadoContra<<setw(15);
		cout<<auxiliar->next<<endl;
		auxiliar=auxiliar->next;
	}	
	
	cout<<endl<<"Primer nodo: "<<primerocli;
	auxiliar=primerocli;
	while(auxiliar->next!=NULL)
		auxiliar=auxiliar->next;
		
	cout<<endl<<"Ultimo nodo: "<<auxiliar;
	cout<<" "<<endl;
}

void Direccionescli(){
	system("cls");
	struct ListasClientes *aux=primListacli;
	cout<<"Ubicacion Lista: "<<setw(20);
	cout<<"Lista(Pimer nodo): "<<setw(20);
	cout<<"Siguiente: "<<endl;
	
	while(aux!=NULL){
		cout<<aux<<setw(20);
		cout<<aux->listacli<<setw(20);
		cout<<aux->next<<endl;
		aux=aux->next;
	}
	cout<<endl<<"Primer LISTA: "<<primListacli;
	cout<<endl<<"Ultima LISTA: "<<ultListacli;
	
	aux=primListacli;
	while(aux!=NULL){
		SetConsoleTextAttribute(hd, 10);
		cout<<endl<<"ID de la lista: "<<aux->idListasCli;
		dirCli(aux->listacli);
		aux=aux->next;
	}
	getch();
	system("cls");
}
