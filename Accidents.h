#ifndef _Accidents_H
#define _Accidents_H

extern PesoAccidente accidentsTypes;
extern int nAccidentsTypes;

extern char*** accidents;
extern int accidentsPerType;

extern char* GetAccident(int type, int i);
extern PesoAccidente GetAccidentType(int i);
extern void SetAccidents(int type);

extern char* AppliedProcedure(int i);

extern void InitializeAccidents();

typedef enum prodcedimiento_aplicado procedimiento_aplicado;

enum procedimiento_aplicado{
	Si,
	No,
	En_Proceso
};

typedef struct DescAccidente DescAccidente;

struct DescAccidente{
	char * descripcion;
	enum procedimiento_aplicado procedimiento_aplicado;
	int dias_perdidos;
	
};

typedef struct PesoAccidente PesoAccidente;
	
struct PesoAccidente{
	char * Contexto;
	float peso;
	DescAccidente * Accidentes;
};



#endif
