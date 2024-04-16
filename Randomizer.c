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


/*Accidente* RandomAccidente()
{
   int i = RandomRange(0, nAccidentsTypes - 1);
   int j = RandomRange(0, accidentsPerType - 1);
   
   char* accidentType = GetAccidentType(i);
   char* description = GetAccident(i, j);
   
   i = RandomRange(0,2);
   
   char* procedure = AppliedProcedure(i);
   
   int lostDays = RandomRange(0,14);
   
   return CrearAccidente(description, accidentType, lostDays, procedure);
}*/

int main()
{
   srand((unsigned int)time(NULL));
   
   InitializeAccidents();
   InitializeNames();
   
   Persona* person = RandomPerson();
   
   PrintPersona(person);
   
   //Accidente* accidente = RandomAccidente();
   
   //PrintAccident(accidente);
}
