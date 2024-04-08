#ifndef Persons_H
#define Persons_H

typedef struct Name name;

struct Name
{
   char* name;
   char gender;   
};

extern name* names;
extern char** lastNames;

extern int nNames;

extern char* CreateName(int i, int j);
extern char CreateGender(int option);

extern void InitializeNames();

#endif
