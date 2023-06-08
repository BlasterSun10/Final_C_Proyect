void decomain(){
	SetConsoleTextAttribute(hd, 5);
	
	for(int a=0;a<120;a++){
		
		gotoxy(a,29);
		printf("%c",207);
		
		if(a<30){
			gotoxy(0,a);
			printf("%c",207);
			
			fflush(stdin);
			
			gotoxy(119,a);
			printf("%c",207);
		}
		
		gotoxy(a,0);
		printf("%c",207);
	}
	
	gotoxy(50,13);
	SetConsoleTextAttribute(hd, 11);
}

void decoprint(){
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hd, 14);
	
	for(int a=0;a<120;a++){
		
		gotoxy(a,29);
		printf("%c",177);
		
		if(a<30){
			gotoxy(0,a);
			printf("%c",177);
			
			fflush(stdin);
			
			gotoxy(119,a);
			printf("%c",177);
		}
		
		gotoxy(a,0);
		printf("%c",177);
	}
	
	gotoxy(50,13);
	SetConsoleTextAttribute(hd, 11);
}

void PrincipioMenu(){
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hd, 11);
	for(int a=0;a<120;a++){	//Bordes
		
		gotoxy(a,29);
		printf("%c",207);
		
		if(a<30){
			gotoxy(0,a);
			printf("%c",207);
			
			fflush(stdin);
			
			gotoxy(119,a);
			printf("%c",207);
		}
		
		gotoxy(a,0);
		printf("%c",207);
	}
	SetConsoleTextAttribute(hd, 21);
	gotoxy(50,3);
	cout<<"Bienvenido cliente"<<endl;
	SetConsoleTextAttribute(hd, 13);
	for(int c=5;c<10;c++){	//Letras en y
		gotoxy(35,c);
		printf("%c",186);
		
		gotoxy(45,c);
		printf("%c",186);

		gotoxy(50,c);
		printf("%c",186);
		
		gotoxy(53,c);
		printf("%c",186);
		
		gotoxy(59,c);
		printf("%c",186);
		
		gotoxy(62,c);
		printf("%c",186);
		
		gotoxy(69,c);
		printf("%c",186);
		
		gotoxy(75,c);
		printf("%c",186);
	}
	
	for(int d=36;d<42;d++){ //B
		gotoxy(d,5);
		printf("%c",205);
		
		gotoxy(d,9);
		printf("%c",205);
		
		gotoxy(d,7);
		printf("%c",205);
		
	}
	
	for(int AA=46;AA<50;AA++){	//A
		gotoxy(AA,5);
		printf("%c",205);
		
		gotoxy(AA,7);
		printf("%c",205);
	}
	//_______________individuales_____________________________
	gotoxy(42,6);		//B
	printf("%c",186);
	gotoxy(42,8);
	printf("%c",186);
	
	int p=54,q=5;			//N
	while(p!=59){
		gotoxy(p,q);
		printf("%c",187);
		p++;
		q++;
	}
	
	for(int e=63;e<=66;e++){		//C
		gotoxy(e,5);
		printf("%c",205);
		gotoxy(e,9);
		printf("%c",205);
	}
	
	for(int o=70;o<75;o++){			//O
		gotoxy(o,5);
		printf("%c",205);
		gotoxy(o,9);
		printf("%c",205);
	}
	//____________________________________________
	//_________________Esquinas Pulidas_____________
	gotoxy(35,5);		//B
	printf("%c",201);
	gotoxy(35,9);
	printf("%c",200);
	gotoxy(35,7);
	printf("%c",204);
	
	gotoxy(45,5);			//A
	printf("%c",201);
	gotoxy(50,5);
	printf("%c",187);
	gotoxy(45,7);
	printf("%c",204);
	gotoxy(50,7);
	printf("%c",185);
	
	gotoxy(53,5);		//N
	printf("%c",201);
	gotoxy(59,9);
	printf("%c",188);
	
	gotoxy(58,9);
	printf("%c",200);
	
	gotoxy(62,5);		//C
	printf("%c",201);
	gotoxy(62,9);
	printf("%c",200);
	
	gotoxy(69,9);			//o
	printf("%c",200);
	gotoxy(69,5);
	printf("%c",201);
	gotoxy(75,9);
	printf("%c",188);
	gotoxy(75,5);
	printf("%c",187);
	
	//______________________________________________
	SetConsoleTextAttribute(hd, 23);
	gotoxy(45,15);
	printf("Bruno Axel Puente Luna 177876");
	gotoxy(45,16);
	printf("Uriel Montejano Briano 177771");
	SetConsoleTextAttribute(hd, 10);
	getch();
	system("cls");
}

void cuadrologin(){
	//241
	SetConsoleTextAttribute(hd, 8);
	for(int a=10;a<17;a++){
		gotoxy(45,a);
		printf("%c",241);
		gotoxy(78,a);
		printf("%c",241);
	}
	for(int b=45;b<79;b++){
		gotoxy(b,10);
		printf("%c",241);
		gotoxy(b,16);
		printf("%c",241);
	}
}
