#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStructs.h"
#include "Randomizer.h"
#include "Accidents.h"
#include "Persons.h"

float RandomRangeF(float min, float max)
{
   return ((float)rand()/(float)(RAND_MAX) * max) + min;
}

int RandomRange(int min, int max)
{
   return(rand() % (max - min + 1)) + min;
}

Persona* RandomPerson()
{   
   int i = RandomRange(0, nNames - 1);
   int j = RandomRange(0, nNames - 1);
   
   char * nombre = CreateName(i, j);
   
   char* rut = "1";

   char sexo = CreateGender(i);
   
   int edad = RandomRange(21, 63);
   
   int sindical = RandomRange(0, 1);
   
   int embarazada = 0;
   
   if(sexo == 'F')
   {
      embarazada = RandomRange(0, 1);
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

int main()
{
   srand((unsigned int)time(NULL));
   
   InitializeAccidents();
   InitializeNames();
   
   Persona* person = RandomPerson();
   
   PrintPersona(person);
}
