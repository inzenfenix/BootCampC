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

void PrintAccident(Accidente* accident)
{
   printf("\nDescripcion: %s\n", accident->descripcion);
   printf("\nContexto: %s\n", accident->contexto);
   printf("\nDias Perdidos: %d\n", accident->diasPerdidos);
   printf("\nProcedimiento Aplicado: %d\n", accident->procedimientoAplicado);
}

Accidente* CrearAccidente(char* descripcion, char* contexto, int diasPerdidos, int procedimientoAplicado) 
{
    Accidente* nuevoAccidente = (Accidente*)malloc(sizeof(Accidente));
    
    nuevoAccidente->contexto = contexto;
    nuevoAccidente->descripcion = descripcion;
    nuevoAccidente->diasPerdidos = diasPerdidos;
    nuevoAccidente->procedimientoAplicado = procedimientoAplicado;
    
    nuevoAccidente->siguiente = NULL;
    
    return nuevoAccidente;
}

// Función para agregar un accidente a la lista de accidentes de una persona
Accidente* AgregarAccidente(Accidente * listaAccidentes, Accidente* accidente) 
{
    accidente->siguiente = listaAccidentes;
    
    
    return accidente;
}

void PrintAccidents(Accidente* accidents, int accidenteActual)
{
   if(accidents == NULL)
   {
      printf("\nFin Accidentes\n");
      return;
   }
   
   printf("\n**** ACCIDENTE %d: ****\n", accidenteActual);
   PrintAccident(accidents);
   printf("\n**** FIN ACCIDENTE %d: ****\n", accidenteActual);
   
   PrintAccidents(accidents->siguiente , ++accidenteActual);
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
