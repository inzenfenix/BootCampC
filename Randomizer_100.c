#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "DataStructs.h"
#include "Randomizer.h"
#include "Accidents.h"
#include "Persons.h"
#include "RutRandomizer.h"


float RandomRangeF(float min, float max)
{
   return ((float)rand()/(float)(RAND_MAX) * max) + min;
}

int RandomRange(int min, int max)
{
   return(rand() % (max - min + 1)) + min;
}

//Funcion que pasa de rut a edad
int rut_a_edad(char* rut) 
{
   char* delimiters = "-";
   
    
   int run = atoi(strtok(rut, delimiters));
   
   if(run > 22000000)
      return RandomRange(21,35);

    double potencia = pow(10, -6);
    double pendiente = 3.3363697569700348 * potencia;
    double intercepto = 1932.2573852507373;
    double anio_nacimiento = pendiente * run + intercepto; 
    int edad = 2024 - anio_nacimiento;

    return edad;
}

//Crea todo lo necesario para una persona
Persona* RandomPerson()
{   
   int i = RandomRange(0, nNames - 1);
   int j = RandomRange(0, nNames - 1);
   
   char * nombre = CreateName(i, j);
   
   char* rut = (char*)malloc(sizeof(char) * 60);
   strcpy(rut, CreateRut());

   char sexo = WhichGender(i);
   
   char* tempRut = (char*)malloc(sizeof(char) * 60);
   strcpy(tempRut, rut);
   
   int edad = rut_a_edad(tempRut);
   
   int sindical = RandomRange(0, 1);
   
   int embarazada = 0;
   
   if(sexo == 'F')
   {
      int peso = RandomRangeF(0.0, 1.0);
      if (peso <= 0.1)
      {
      	embarazada = 1;
      }
      else
      {
      	embarazada = 0;
      }
   }
   else
   {
      embarazada = 0;
   }
   
   Accidente* listaAccidentes = (Accidente*)NULL;
   Persona* proxima = (Persona*)NULL;
   
   return CrearPersona(nombre, rut, sexo, edad,
                       sindical, embarazada,
                       listaAccidentes, proxima);
   
}


Accidente* RandomAccidente(Persona* person)
{
   int peso = RandomRangeF(0, 1);
   
   int accidentTypeIndex = GetAccidentTypeIndex(person->sindical, peso);
   char* accidentType = accidentsTypes[accidentTypeIndex].Contexto;
   int j = RandomRange(0, accidentsPerType - 1);
   
   DescAccidente accidente = GetAccident(accidentTypeIndex, j);
   
   char* description = accidente.descripcion;
   int procedure = accidente.procedimiento_aplicado;
   int lostDays = accidente.dias_perdidos;
   
   return CrearAccidente(description, accidentType, lostDays, procedure);
}

int main()
{
   srand((unsigned int)time(NULL));
   
   InitializeAccidents();
   InitializeNames();
   for (int i; i < 10 ; i++){
   Persona* person = RandomPerson();
   
   PrintPersona(person);
   
   Accidente* accidente = RandomAccidente(person);
   
   person->listaAccidentes = accidente;
   
   int accidents = RandomRange(1,3);
   
   if(accidents > 1)
   {
      for(int i = 0; i < accidents - 1; i++)
      {
         person->listaAccidentes = AgregarAccidente(person->listaAccidentes, RandomAccidente(person));
      }
   }
   
   PrintAccidents(person->listaAccidentes, 1);
   printf("\n");
   }
}
