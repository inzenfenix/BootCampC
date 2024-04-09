#ifndef _Accidents_H
#define _Accidents_H

extern char** accidentsTypes;
extern int nAccidentsTypes;

extern char*** accidents;
extern int accidentsPerType;

extern char* GetAccident(int type, int i);
extern char* GetAccidentType(int i);
extern void SetAccidents(int type);

extern char* AppliedProcedure(int i);

extern void InitializeAccidents();

#endif
