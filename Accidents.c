#include "Accidents.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PesoAccidente * accidentsTypes = NULL;
int nAccidentsTypes = 10;

char*** accidents = NULL;
int accidentsPerType = 5;


char* GetAccident(int type, int i)
{
   return accidents[type][i];
}

PesoAccidente GetAccidentType(int i)
{
   return accidentsTypes[i];
}



void SetAccidents(int type)
{
   switch(type)
   {
      case 0:
         accidentsTypes[type].Accidentes[0].descripcion = "Piso estaba humedo y provocó una caida, la gravedad de la misma no quedó clara pero señaló tener una molestia en la espalda";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[1].descripcion = "Se produce lesión muscular mientras se levanta caja de informes";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 3;
         accidentsTypes[type].Accidentes[2].descripcion = "Quemadura producto de café derramado en las piernas mientrasse trabajaba en el escritorio ";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 2;
         accidentsTypes[type].Accidentes[3].descripcion = "Durante la mañana no se prendía el computador y al revisar la conexión eléctrica se da una descarga al momento de intentar acomodar la conexión";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 5;
         accidentsTypes[type].Accidentes[4].descripcion = "Al momento de sentarse en una silla dañanda se rompe una parte de la rueda y se sufre una contusión al caer";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 4;
         break;
      case 1:
         accidentsTypes[type].Accidentes[0].descripcion = "Durante el cruce a la ofinica de edificio al frente persona en patín choca y provoca lesión del funcionario";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 10;
         accidentsTypes[type].Accidentes[1].descripcion = "Mientras había un cambio de oficina en el mismo edificio funcionario sufre lesión en el tobillo.";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 5;
         accidentsTypes[type].Accidentes[2].descripcion = "En camino a bodega de archivos se cae un pallet de papeles sobre pie y aparentemente se sufre fractura en dedo del pie.";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 7;
         accidentsTypes[type].Accidentes[3].descripcion = "Durante traslado de puesto de trabajo a dependencia nueva se dobla el tobillo y no puede levantarse más.";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 9;
         accidentsTypes[type].Accidentes[4].descripcion = "Durante el cruce a la ofinica de edificio al frente persona en patín choca y provoca lesión del funcionario";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 2;
         break;
      case 2:
         accidentsTypes[type].Accidentes[0].descripcion = "En almuerzo preparado por la empresa se produce caida y sufrió un golpeen la zona de la frente";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[1].descripcion = "En actividad de reunión en sector del Maipo para la unificación del equipo empleado sufre esguince en actividades grupales";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 5;
         accidentsTypes[type].Accidentes[2].descripcion = "En capacitación para relaciones interpersonales sufre un golpe al momento de hacer ejercicio de confianza.";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[3].descripcion = "En fiesta de compañía cae sobre la pierna material pesado y provoca una lesión en pierna derecha";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 12;
         accidentsTypes[type].Accidentes[4].descripcion = "Mientras se celebraba almuerzo de la compañia en restaurant cae una taza hirviendo y sufre quemaduras";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 1;
         break;
      case 3:
         accidentsTypes[type].Accidentes[0].descripcion = "En reunión de sindicato una mesa plegable se rompe y cayó sobre las piernas, lesionando gravemente.";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 10;
         accidentsTypes[type].Accidentes[1].descripcion = "En reunión gremial se sufre una lesión en el tobillo al momento de bajar de tarima.";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[2].descripcion = "En el contexto de una reunión sindical se rompe maquina de café y produce quemaduras.";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[3].descripcion = "En reunión de sindicato una mesa plegable se rompe y cayó sobre las piernas, lesionando gravemente.";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 6;
         accidentsTypes[type].Accidentes[4].descripcion = "En reunión gremial se sufre una lesión en el tobillo al momento de bajar de tarima.";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 0;
         break;
      case 4:
         accidentsTypes[type].Accidentes[0].descripcion = "Empleado sufre tendinitis producido de los continuos movimientos de gillotina y manejo de papeles.";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 2;
         accidentsTypes[type].Accidentes[1].descripcion = "Empleado sufre inmovilidad de brazo derecho producido por el uso continuo de mouse sin un equipamiento adecuado.";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 5;
         accidentsTypes[type].Accidentes[2].descripcion = "Empleado sufre perdida visual considerable producido del trabajo con pantallas y mala iluminación";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[3].descripcion = "Trabajador sufre sindrome del tunel carpeano por trabajar diariamente en escritorio con una posición poco ergonomica";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 3;
         accidentsTypes[type].Accidentes[4].descripcion = "Trabajador encargado de atención al publico sufre estrés laboral por las acciones relacionadas";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 20;
         break;
      case 5:
         accidentsTypes[type].Accidentes[0].descripcion = "Trabajador sufre asalto a las afuras de oficina.";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[1].descripcion = "Empleado sufre violento ataque en transporte mientras iba camino a la oficina";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 2;
         accidentsTypes[type].Accidentes[2].descripcion = "Trabajador sufre robo de auto en camino al trabajo";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[3].descripcion = "Trabajador es apuñalado al momento de salir de su casa al trabajo";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 15;
         accidentsTypes[type].Accidentes[4].descripcion = "Empleado es golpeado para quitarle sus pertenencias en camino al trabajo";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 4;
         break;
      case 6:
         accidentsTypes[type].Accidentes[0].descripcion = "Secretaría sufre cachetada al momento de atender a cliente molesto";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[1].descripcion = "Mientras se recibia paquete de papeleria, repartidor entra en conflicto con empleado y este ultimo sufre golpes";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[2].descripcion = "Persona externa ingresa a oficina y atacó a empleado espontaneamente.";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[3].descripcion = "Empleado es atacado por cliente cuando atendía consultas extraordinarias";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[4].descripcion = "Secretaría sufre cachetada al momento de atender a cliente molesto";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 0;
         break;
      case 7:
         accidentsTypes[type].Accidentes[0].descripcion = "Empleado es golpeado por subalterno tras discutir por un proyecto";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[1].descripcion = "Trabajador es golpeado por jefe directo tras fuerte discución, investigación pendiente.";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[2].descripcion = "Empleado queda gravemente lesionado tras riña con compañero de sección";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 2;
         accidentsTypes[type].Accidentes[3].descripcion = "Tras discutir en el baño empleado es empujado por compañero terminando en grave lesión.";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 4;
         accidentsTypes[type].Accidentes[4].descripcion = "Trabajador es golpeado por jefe directo tras fuerte discución, investigación pendiente.";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 0;
         break;
      case 8:
         accidentsTypes[type].Accidentes[0].descripcion = "Empleado sufre caida en restaurant cercano a la oficina, termina llendo directamente a centro de salud.";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 2;
         accidentsTypes[type].Accidentes[1].descripcion = "Trabajador sufre quemadura en casino de la oficina durante el almuerzo.";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[2].descripcion = "Durante almuerzo, empleado sufre intoxicación severa producto de comida marina";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 3;
         accidentsTypes[type].Accidentes[3].descripcion = "Empleado sufre corte producido por un vaso quebrado, debido al fuerte sangrado acude a centro de salud";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[4].descripcion = "En camino a casino sufre lesión en el tobillo al bajar por escalera.";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 6;
         break;
      
      case 9:
         accidentsTypes[type].Accidentes[0].descripcion = "Limpiador de ventanas muere tras caer y queda cuerpo expuesto frente a oficina";
         accidentsTypes[type].Accidentes[0].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[0].dias_perdidos = 0;
         accidentsTypes[type].Accidentes[1].descripcion = "Trabajador sufre combulsiones en espacio de trabajo";
         accidentsTypes[type].Accidentes[1].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[1].dias_perdidos = 1;
         accidentsTypes[type].Accidentes[2].descripcion = "Empleado comete suicidio en espacio de trabajo, se deriva a compañero a tratamiento psicologico";
         accidentsTypes[type].Accidentes[2].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[2].dias_perdidos = 3;
         accidentsTypes[type].Accidentes[3].descripcion = "Mientras se reparaba conexión electrica electricista sufre grave electroshock, switch automatico no funcionó bien";
         accidentsTypes[type].Accidentes[3].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[3].dias_perdidos = 5;
         accidentsTypes[type].Accidentes[4].descripcion = "Motociclista choca contra ventana de oficina, no hay lesiones graves a trabajador.";
         accidentsTypes[type].Accidentes[4].procedimiento_aplicado = 0;
         accidentsTypes[type].Accidentes[4].dias_perdidos = 5;
         break;
      default:
         break;
   }
}

void InitializeAccidents()
{
   accidentsTypes = (PesoAccidente *)malloc(sizeof(PesoAccidente) * nAccidentsTypes);
   
   accidentsTypes[0].Contexto = "Accidente a causa de trabajo";
   accidentsTypes[1].Contexto = "Accidente en traslado entre dependencias";
   accidentsTypes[2].Contexto = "Accidente en el contexto de una actividad organizada por empleador";
   accidentsTypes[3].Contexto = "Accidente de dirigente sindical";
   accidentsTypes[4].Contexto = "Sintomas de enfermedad producidos por quehacer laboral";
   accidentsTypes[5].Contexto = "Violencia de tipo 1";
   accidentsTypes[6].Contexto = "Violencia de tipo 2";
   accidentsTypes[7].Contexto = "Violencia de tipo 3";
   accidentsTypes[8].Contexto = "Accidente en horario colacion";
   accidentsTypes[9].Contexto = "Situaciones disruptivas y de alta complejidad";

   accidentsTypes[0].peso = 0.30;
   accidentsTypes[1].peso = 0.38;
   accidentsTypes[2].peso = 0.48;
   accidentsTypes[3].peso = 0.51;
   accidentsTypes[4].peso = 0.60;
   accidentsTypes[5].peso = 0.65;
   accidentsTypes[6].peso = 0.74;
   accidentsTypes[7].peso = 0.84;
   accidentsTypes[8].peso = 0.96;
   accidentsTypes[9].peso = 0.99;


   accidents = (char***)malloc(sizeof(char**) * nAccidentsTypes);
   
   for(int i = 0; i < nAccidentsTypes; i++)
   {
      accidentsTypes[i].Accidentes = (DescAccidente *)malloc(sizeof(DescAccidente) * accidentsPerType);
      SetAccidents(i);
   }
      
}
