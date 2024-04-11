#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "rut_randomizer.h" 

int randomRange(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

Nodo * insert(int dato, Nodo *lista){
	Nodo *n = (Nodo *)malloc(sizeof(Nodo));
	n->dato = dato;
	n->proximo = NULL;
	n->anterior = NULL;

	if (lista == NULL){	
		return n;
	}else if (lista->proximo == NULL){
		lista->proximo = n;
		n->anterior = lista;
		return lista;
	}else{
		Nodo *temp = lista->proximo; 
		n->proximo = temp;
		
		lista->proximo->anterior = n;
		lista->proximo=n;
		
		n->anterior = lista;
		return lista;
	}
}

int extract(Nodo **lista){
	if (*lista == NULL){
		return -1;
	}else{
		Nodo *temp = *lista;		
		int dato = temp->dato;
		
		*lista = temp->proximo;
		(*lista)->anterior = NULL;

		free(temp);
		return dato;
	}
}

Nodo * gotoLast(Nodo * tope){
	if (tope->proximo == NULL){
		return tope;
	}	
	gotoLast(tope->proximo);
}

int count(Nodo *list) {
	if (list == NULL){
		return 0;
	}
    return count(list->proximo) + 1;
}

// funciones de RUT
void printRut(Nodo *rut,int len,int pos, int verificador) {
    if (rut==NULL){
        printf("\nEl digito verificador es: %d \n", verificador);
        return;
    }
    printf("%d", rut->dato);
    printRut(rut->proximo,len,pos+1, verificador);
}

// funcion rut verificador
int rut_verificador(Nodo * rut_inv){
    int len = count(rut_inv) - 1;
    int mult = 1;
    int suma_total = 0;
    int diferencia;
    int digito_mult;
    // ciclo
    for (int var=len;var>=0;var--) {
        if (mult + 1 > 7) {
            mult = 1;
        }
        mult++;
        digito_mult = rut_inv->dato * mult;
        suma_total += digito_mult;
        diferencia = suma_total - ((suma_total/11) * 11);
        rut_inv = rut_inv->proximo;
    }

    if (11 - diferencia == 0) {
        return 0;
    }
    else{
        if (11 - diferencia == 10) {
            return 99;
        }
        else{
            return 11-diferencia;
        }
    }
}
// funcion formato
char * formato_rut(Nodo *nodo, int digito, char * cadena, int len) {
    int n = count(nodo);
    if (nodo == NULL) {   
        char guion[2] = "-";
        char digito_char[2];
        char cadena_copia[20];
        char cadena_copia2[20];
        strcpy(cadena_copia, cadena);
        strcat(cadena, guion);
        strcpy(cadena_copia2, cadena);
        sprintf(cadena_copia2, "%d", digito);
        strcat(cadena, cadena_copia2);
        return cadena;
    }
    if (n != len) {
        char cadena_copia[20];
        strcpy(cadena_copia, cadena);
        sprintf(cadena_copia, "%d", nodo->dato);
        strcat(cadena, cadena_copia);
    }
    else {
        sprintf(cadena, "%d", nodo->dato);
    }
    return formato_rut(nodo->proximo, digito, cadena, len);
}


// funcion principal
char * create_rut() {
    Nodo *rut = NULL;
    rut = insert(randomRange(0,2), rut);
    if (rut->dato == 0) {
        rut = insert(randomRange(5,9), rut);
    }
    else {
        rut = insert(randomRange(0,9), rut);
        }
    for (int var=0;var<=5;var++) {
        rut = insert(randomRange(0,9), rut);
    }
    // eliminador primer digito if 0
    if (rut->dato == 0) {
        extract(&rut);
    }
    int len = count(rut);
    // digito verificador
    Nodo *rut_inverso = gotoLast(rut);
    int digito_verificador = rut_verificador(rut_inverso);

    len = count(rut);
    //printRut(rut,len,0, digito_verificador);
    char cadena[20];
    char * resultado;
    resultado = formato_rut(rut, digito_verificador, cadena, len);
    return resultado;
}
/*
void main() {
    srand(time(0));
    char * rut = create_rut();
    printf("El rut es: %s\n", rut);
}*/