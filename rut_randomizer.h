#ifndef _rut_randomizer_h
#define _rut_randomizer_h

typedef struct Nodo{
	int dato;
	struct Nodo * proximo;
	struct Nodo * anterior;
}Nodo;

extern char * create_rut();



#endif