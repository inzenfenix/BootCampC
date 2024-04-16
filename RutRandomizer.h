#ifndef _RutRandomizer_h
#define _RutRandomizer_h

typedef struct Nodo Nodo;

struct Nodo{
	int dato;
	Nodo * proximo;
	Nodo * anterior;
};

extern char* CreateRut();


#endif
