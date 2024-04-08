#ifndef _Accidents_H
#define _Accidents_H

extern char** accidentsTypes;
extern int nAccidentsTypes;

extern char*** accidents;
extern int accidentsPerCategory;

extern char* GetAccident(int type, int i);
extern void SetAccidents(int type);

extern void PrintAccident(char* accident);

extern void InitializeAccidents();

#endif
