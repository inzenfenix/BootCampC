#include <stdio.h>
#include <stdlib.h>

typedef struct Fecha{
    int anio;
    int mes;
    int dia;
}Fecha;

Fecha* RandomFecha(int anio_inicial, int anio_final) {
    Fecha* fecha = (Fecha*)malloc(sizeof(Fecha));
    fecha->anio = anio_inicial + rand() % (anio_final - anio_inicial + 1);

    // PAra cuando el año es el primero o ultimo
    int mes_inicial = 1;
    int mes_final = 12;
    if (fecha->anio == anio_inicial) {
        mes_inicial = 1; // Empezar desde enero si estamos en el año_inicial
    }
    if (fecha->anio == anio_final) {
        mes_final = 5; // Terminar en mes actual, esto podemos cambiarlo cada mes o automatizarlo
    }

    // Sacamos su RandomMes
    fecha->mes = mes_inicial + rand() % (mes_final - mes_inicial + 1);

    // Se calcula la cantidad de dias porque putos meses
    int dias_en_mes;
    if (fecha->mes == 2) {
        // Ya se la saben
        if ((fecha->anio % 4 == 0 && fecha->anio % 100 != 0) || (fecha->anio % 400 == 0)) {
            dias_en_mes = 29;
        } else {
            dias_en_mes = 28;
        }
    } else if (fecha->mes == 4 || fecha->mes == 6 || fecha->mes == 9 || fecha->mes == 11) {
        dias_en_mes = 30;
    } else {
        dias_en_mes = 31;
    }

    // Se consigue el RandomDia para la RandomFecha
    fecha->dia = 1 + rand() % dias_en_mes;

    return fecha;
}

void printFecha(Fecha* fecha) {
    printf("%d-%d-%d/", fecha->anio, fecha->mes, fecha->dia);
}
