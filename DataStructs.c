#include "DataStructs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


Persona* CrearPersona(char *nombre,char *rut,char sexo,int edad,
                      int sindical,int embarazada,
                      Accidente *lista_accidentes,Persona* proxima)
{
    
    Persona * nuevaPersona = (Persona*)malloc(sizeof(Persona));

    nuevaPersona->nombre = nombre;
    
    nuevaPersona->rut = rut;
    
    nuevaPersona->edad = edad;
    
    nuevaPersona->sexo = sexo;
    
    nuevaPersona->sindical = sindical;
    
    nuevaPersona->embarazada = embarazada;
    
    nuevaPersona->listaAccidentes = lista_accidentes;
    
    nuevaPersona->proxima = proxima;
    
    return nuevaPersona;
}

void PrintPersona(Persona* person)
{
   printf("\nNombre: %s\n", person->nombre);
   printf("\nRut: %s\n", person->rut);
   printf("\nEdad: %d\n", person->edad);
   printf("\nSexo: %c\n", person->sexo);
   printf("\nSindical: %d\n", person->sindical);
   printf("\nEmbarazada: %d\n", person->embarazada);
}

Accidente* CrearAccidente(char descripcion[]) 
{
    Accidente* nuevoAccidente = (Accidente*)malloc(sizeof(Accidente));
    strcpy(nuevoAccidente->descripcion, descripcion);
    nuevoAccidente->siguiente = NULL;
    return nuevoAccidente;
}

// Función para agregar un accidente a la lista de accidentes de una persona
void AgregarAccidente(Persona * persona, char descripcion[]) 
{
    Accidente* nuevoAccidente = CrearAccidente(descripcion);
    
    nuevoAccidente->siguiente = persona->listaAccidentes;
    
    persona->listaAccidentes = nuevoAccidente;
}


/*void Test(){
    char nombre[50];
    char rut[10];
    char sexo;
    int edad;
    int sindical;
    int embarazada;

    printf("ingrese su nombre");
    scanf("%s",*nombre);
    printf("ingrese su rut");
    scanf("%s",*rut);
    printf("ingrese su sexo (M) o (H)");
    scanf("%c",&sexo);
    printf("ingrese su edad");
    scanf("%d",&edad);
    printf("Usted es Sindical?");
    scanf("%d",&sindical);
    printf("Esta embarazad@?");
    scanf("%d",&embarazada);
    Accidente *listaAccidentes = NULL; 

    crearPersona(*nombre,*rut,sexo,edad,sindical,embarazada,listaAccidentes,NULL);



}*/
