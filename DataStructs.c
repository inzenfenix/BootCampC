#include "DataStructs.h"
#include <stdio.h>
#include <stdlib.h>
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
   printf("%s,%s,%d,%c,%d,%d,", person->nombre,person->rut,person->edad,person->sexo,person->sindical,person->embarazada);

}

void PrintAccident(Accidente* accident)
{
   printf("/%s*%s*%d*%d*", accident->descripcion,accident->contexto,accident->diasPerdidos,accident->procedimientoAplicado);

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

      return;
   }
   
   PrintAccident(accidents);
   
   
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
