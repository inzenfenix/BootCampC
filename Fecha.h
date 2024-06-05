#ifndef _Fecha_H
#define _Fecha_H


typedef struct Fecha Fecha;
struct Fecha{
    int anio;
    int mes;
    int dia;
}Fecha;

extern Fecha* RandomFecha(int anio_inicial, int anio_final);

extern void printFecha(Fecha fecha);

#endif
