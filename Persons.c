#include "Persons.h"
#include <stdlib.h>
#include <string.h>

char** lastNames = NULL;
name* names = NULL;

int nNames = 11;

char* CreateName(int i, int j)
{
   if(names == NULL)
   {
      return "?";
   }
   
   int size = strlen(names[i].name) + strlen(lastNames[j]) + 1;
   
   char* name = (char*)malloc(sizeof(char) * size);
   
   strcpy(name, names[i].name);
   strcat(name, lastNames[j]);
   
   return name;
}

char WhichGender(int i)
{
   return names[i].gender;
}

void InitializeNames()
{
   names = (name*)malloc(sizeof(name) * nNames);
   lastNames = (char**)malloc(sizeof(char*) * nNames);  
   
   names[0].name = "Benjamin ";  
   names[0].gender = 'M';
   
   names[1].name = "Martin ";    
   names[1].gender = 'M';
   
   names[2].name = "Lucas ";   
   names[2].gender = 'M';  
   
   names[3].name = "Tomas ";   
   names[3].gender = 'M'; 
    
   names[4].name = "Alexander ";
   names[4].gender = 'M';
    
   names[5].name = "Agustina "; 
   names[5].gender = 'F'; 
   
   names[6].name = "Martina ";   
   names[6].gender = 'F'; 
   
   names[7].name = "Benjamina "; 
   names[7].gender = 'F'; 
   
   names[8].name = "Carla ";   
   names[8].gender = 'F'; 
     
   names[9].name = "Trinidad "; 
   names[9].gender = 'F';  
   names[10].name = "Mauricio Alex "; 
   names[10].gender = 'M';   
   
   lastNames[0] = "Fernandez";
   lastNames[1] = "Gomez";
   lastNames[2] = "D'Arc";
   lastNames[3] = "Del Canto";
   lastNames[4] = "Yunque";
   lastNames[5] = "Sanchez";
   lastNames[6] = "Bustamante";
   lastNames[7] = "Del Rio";
   lastNames[8] = "Silva";
   lastNames[9] = "Pavez";
   lastNames[10] = "Vasquez";
}
