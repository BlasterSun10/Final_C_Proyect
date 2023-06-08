float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	
	do{
		printf("%s",mensaje);
		continuar=scanf("%f", &flotante);
		fflush(stdin);
	}while (continuar!=1);
	
	return flotante;
}

int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	
	do{
		printf("%s",mensaje);
		continuar=scanf("%d",&entero);
		fflush(stdin);
	}while (continuar!=1);
	
	return entero;
}

void validaCadena(const char mensaje[], const char cadena[]){
	bool bandera = true;
	while(bandera){
		printf("%s", mensaje);
		scanf("%[^\n]",cadena);
		fflush(stdin);
		if(strlen(cadena)>29){
			continue;
		}else{
			for(int i=0; i<strlen(cadena); i++){
				if(isalpha(cadena[i])|| cadena[i]==' '){
					if(i==(strlen(cadena)-1)){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
	return;
}
