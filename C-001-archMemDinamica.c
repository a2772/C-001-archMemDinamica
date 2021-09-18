#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 200
#define M 9

//Función para encontrar la cadena
int strcmp2(char*, char*);
int main(){
	
	

///Variables
	FILE *archivo = NULL,*reserva = NULL;//File, uno para el programa y otro para palabras reservadas
	int i,j,rows,nReservadas,*nLine;//Contador auxiliar, lo usamos en los for y en otras cosas
	char *content;//Arreglo donde almacenaremos el contenido del archivo
	char **cntFile,**cntRes;//Matriz dinámica
	printf("Objetivo: Programa que muestre las l%cneas del c%cdigo que contengan palabras reservadas\n",161,162);
	
	
	
///Archivo del programa
	archivo = fopen("Programa.txt","r");//Abrimos el archivo
	if(archivo==NULL){//En caso de que haya error
    	printf("No se puede abrir el fichero. \n");
    	exit(1);
	}
	rewind(archivo);//Regresamos el cursor al inicio del archivo
	content = (char*)malloc(N*sizeof(char));//Asignamos el tamaño al arreglo
	//Ahora recuperamos el contenido en nuestro arreglo
	i=0;
	printf("\t***Archivo con el programa original***\n-----------------------------------------------\n");
	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		i++;//Por cada linea incrementamos el contador
 		printf("%s",content);
 	}
 	//Asignamos tamaño a nuestra matriz, con el número de filas
 	i--;
 	cntFile = (char**)malloc(i*sizeof(char*));
 	if(cntFile==NULL)
 		exit(1);
	rewind(archivo);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tamaño a cada fila
 	i=0;
 	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		cntFile[i]=(char*)malloc(sizeof(content)*sizeof(char));//Asignamos la fila
 		if(cntFile[i]==NULL)
 			exit(1);
 		//Asignamos el contenido
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	rewind(archivo);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tamaño a cada fila
 	i=0;
 	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		//Asignamos el contenido
 		strcpy(cntFile[i],content);
 		strcat(cntFile[i],""+'\0');
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	rows=i;//Guardamos el número de filas
	//Cerramos archivo
	fclose(archivo);
	
	
	
///Archivo de palabras reservadas
	reserva = fopen("palabrasreservadas.txt","r");//Abrimos el archivo de palabras reservadas
	if(reserva==NULL){//En caso de que haya error
    	printf("No se puede abrir el fichero de reservadas. \n");
    	exit(1);
	}
	rewind(reserva);//Regresamos el cursor al inicio del archivo
	content = (char*)malloc(M*sizeof(char));//Asignamos el tamaño al arreglo, lo reutilizamos
	//Ahora recuperamos el contenido en nuestro arreglo
	i=0;
	printf("\t***Palabras reservadas***\n-----------------------------------------------\n");
	while (feof(reserva) == 0){
 		fgets(content,M*sizeof(char),reserva);
 		i++;//Por cada linea incrementamos el contador
 		printf("%s",content);
 	}
 	//Asignamos tamaño a nuestra matriz, con el número de filas
 	i--;
 	cntRes = (char**)malloc(i*sizeof(char*));
 	if(cntRes==NULL)
 		exit(1);
	rewind(reserva);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tamaño a cada fila
 	i=0;
 	while (feof(reserva) == 0){
 		fgets(content,M*sizeof(char),reserva);
 		cntRes[i]=(char*)malloc(M*sizeof(char));//Asignamos la fila
 		if(cntRes[i]==NULL)
 			exit(1);
 		//Asignamos el contenido
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	rewind(reserva);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tamaño a cada fila
 	i=0;
 	while (feof(reserva) == 0){
 		fgets(content,M*sizeof(char),reserva);
 		//Asignamos el contenido
 		strcpy(cntRes[i],content);
 		strcat(cntRes[i],""+'\0');
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	nReservadas=i;//Guardamos el número de filas
	//Cerramos archivo
	fclose(reserva);
	
	
	
///Match con palabras reservadas e impresión final
	for(i=0;i<rows;i++){
		printf("%s",cntFile[i]);
	}
	/*
	int cRes=0;
	for(i=0;i<rows;i++) {
		for(j=0;j<nReservadas;j++){
			if((strstr(cntFile[i],cntRes[j]))!=NULL) {//Si es palabra reservada
				j=nReservadas;
				cRes++;
			}
		}
	}
	nLine = (int*)malloc(cRes*sizeof(int));
	//Ubicamos las líneas con palabras reservadas y las almacenamos en la matriz
	
	
	
	cRes=0;//Lo reutilizamos para nLine
	for(i=0;i<rows;i++) {
		for(j=0;j<nReservadas;j++){
			if(!(strcmp2(cntFile[i],cntRes[j]))) {//Si es palabra reservada
				printf("%s",cntFile[i]);
				nLine[cRes]=i;
				cntRes++;
				j=nReservadas;
			}
		}
	}
	///Imprimimos las líneas con palabras reservadas
	printf("\t***Lineas con palabras reservadas***\n-----------------------------------------------\n");
	for(i=0;i<cRes;i++) {
		printf("%i) %s",(i+1),cntFile[nLine[i]]);
	}
	
	
	
	///Liberamos memoria dinámica	
	free(cntRes);
	free(content);
	free(cntFile);*/
	return 0;
}
int strcmp2(char* cadena, char* palabra){
    int i, j = 0;
    for(i=0;i<strlen(cadena);i++){
        if(palabra[j] == cadena[i]){
            ++j;
            if(j == strlen(palabra))
                return (2 + i - j);
        }
        else j = 0;
    }
    return -1;
}
