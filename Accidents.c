#include "Accidents.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** accidentsTypes = NULL;
int nAccidentsTypes = 0;

char*** accidents = NULL;
int accidentsPerCategory = 0;

void PrintAccidentsTypes(char** accidents)
{
   if(accidents == NULL)
   {
      return;
   }
}

char* GetAccident(int type, int i)
{
   return accidents[type][i];
}

void SetAccidents(int type)
{
   switch(type)
   {
      case 1:
         accidents[type][0] = "Resbalon";
         accidents[type][1] = "Desgaste por movimientos repetitivos";
         accidents[type][2] = "Quemadura de grado 1";
         break;
      case 2:
         break;
      case 3:
         break;
      case 4:
         break;
      case 5:
         break;
      case 6:
         break;
      case 7:
         break;
      case 8:
         break;
      case 9:
         break;
      default:
         break;
   }
}

void InitializeAccidents()
{
   nAccidentsTypes = 10;
   accidentsTypes = (char**)malloc(sizeof(char*) * nAccidentsTypes);
   
   accidentsTypes[0] = "Accidente a causa de trabajo";
   accidentsTypes[1] = "Accidente en traslado entre dependencias";
   accidentsTypes[2] = "Accidente en el contexto de una actividad organizada por empleador";
   accidentsTypes[3] = "Accidente de dirigente sindical";
   accidentsTypes[4] = "Sintomas de enfermedad producidos por quehacer laboral";
   accidentsTypes[5] = "Violencia de tipo 1";
   accidentsTypes[6] = "Violencia de tipo 2";
   accidentsTypes[7] = "Violencia de tipo 3";
   accidentsTypes[8] = "Accidente en horario colacion";
   accidentsTypes[9] = "Situaciones disruptivas y de alta complejidad";
   
   accidentsPerCategory = 3;
   accidents = (char***)malloc(sizeof(char**) * nAccidentsTypes);
   
   for(int i = 0; i < nAccidentsTypes; i++)
   {
      accidents[i] = (char**)malloc(sizeof(char*) * accidentsPerCategory);
      SetAccidents(i);
   }
      
}
