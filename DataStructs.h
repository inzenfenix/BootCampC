#ifndef _DataStructs_H
#define _DataStruct_H

typedef struct Accidente Accidente;
struct Accidente {
    //char* tipo_evento;
    /* 1.accidente del trabajo
    2. accidente de trayecto
    3.incidente (un incidente es un evento que no incluye dias laborales perdidos)
    4.una enfermedad profesional.
    */
    char* contexto; //listado en el grupo
    char* descripcion; /*en caso de luego necesitar informe debe ir una pequeña descripción*/ 
    /*Fecha evento  -Se supone que no hay libreria basica de c que maneje fehcas como en datetime
    pero hay estructuras que se pueden crear para manejarlos. hay que decidir si las copiamos y usamos
    o dejamos las fehcas como string, de ser así basta con usar un fecha_inicio[10]*/
    //fecha fin investigacion, lo mismo pero para el fin de investigación de ser necesario

    int diasPerdidos; //la cantidad de dias perdidos en caso de que corresponda incidente=0

    char* procedimientoAplicado;/*Existe un “Procedimiento de actuación frente a la 
    ocurrencia de un accidente del trabajo” que se puede cumplir o no, esto varia de oficina 
    a oficina y puede llenarse con un "si","no" o "En proceso". esto ultimo pasa cuando 
    sucede en diciembre y las investigaciones no terminan de pasar*/

    
    Accidente* siguiente;
};

typedef struct Persona Persona;
struct Persona {
    char* nombre;
    char* rut;
    char sexo;
    int edad;
    int sindical;
    int embarazada;
    Accidente* listaAccidentes; 
    struct Persona * proxima;

};


extern Persona* CrearPersona(char *nombre,char *rut,char sexo,int edad,int sindical,int embarazada,Accidente *lista_accidentes,Persona *proxima);

extern void PrintPersona(Persona* person);

extern void PrintAccident(Accidente* accident);

extern Accidente* CrearAccidente(char* descripcion, char* contexto, int diasPerdidos, char* procedimientoAplicado);

extern void AgregarAccidente(Persona* persona, Accidente* accidente);

#endif
