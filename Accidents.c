#include "Accidents.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** accidentsTypes = NULL;
int nAccidentsTypes = 10;

char*** accidents = NULL;
int accidentsPerType = 5;

char* GetAccident(int type, int i)
{
   return accidents[type][i];
}

char* GetAccidentType(int i)
{
   return accidentsTypes[i];
}

char* AppliedProcedure(int i)
{
   switch(i)
   {
      case 0:
         return "Si";
      case 1:
         return "No";
      case 2:
         return "En Proceso";
   }
}

void SetAccidents(int type)
{
   switch(type)
   {
      case 0:
         accidents[type][0] = "Piso estaba humedo y provocó una caida, la gravedad de la mismano quedó clara pero señaló tener una molestia en la espalda";
         accidents[type][1] = "Se produce lesión muscular mientras se levanta caja de informes";
         accidents[type][2] = "Quemadura producto de café derramado en las piernas mientrasse trabajaba en el escritorio ";
         accidents[type][3] = "Durante la mañana no se prendía el computador y al revisar la conexión eléctrica se da una descarga al momento de intentar acomodar la conexión";
         accidents[type][4] = "Al momento de sentarse en una silla dañanda se rompe una parte de la rueda y se sufre una contusión al caer";
         break;
      case 1:
         accidents[type][0] = "Durante el cruce a la ofinica de edificio al frente persona en patín choca y provoca lesión del funcionario";
         accidents[type][1] = "Mientras había un cambio de oficina en el mismo edificio funcionario sufre lesión en el tobillo.";
         accidents[type][2] = "En camino a bodega de archivos se cae un pallet de papeles sobre pie y aparentemente se sufre fractura en dedo del pie.";
         accidents[type][3] = "Durante traslado de puesto de trabajo a dependencia nueva se dobla el tobillo y no puede levantarse más.";
         accidents[type][4] = "Durante el cruce a la ofinica de edificio al frente persona en patín choca y provoca lesión del funcionario";
         break;
      case 2:
         accidents[type][0] = "En almuerzo preparado por la empresa se produce caida y sufrió un golpeen la zona de la frente";
         accidents[type][1] = "En actividad de reunión en sector del Maipo para la unificación del equipo empleado sufre esguince en actividades grupales";
         accidents[type][2] = "En capacitación para relaciones interpersonales sufre un golpe al momento de hacer ejercicio de confianza.";
         accidents[type][3] = "En fiesta de compañía cae sobre la pierna material pesado y provoca una lesión en pierna derecha";
         accidents[type][4] = "Mientras se celebraba almuerzo de la compañia en restaurant cae una taza hirviendo y sufre quemaduras";
         break;
      case 3:
         accidents[type][0] = "En reunión de sindicato una mesa plegable se rompe y cayó sobre las piernaslesionando gravemente.";
         accidents[type][1] = "En reunión gremial se sufre una lesión en el tobillo al momento de bajar de tarima.";
         accidents[type][2] = "En el contexto de una reunión sindical se rompe maquina de café y produce quemaduras.";
         accidents[type][3] = "En reunión de sindicato una mesa plegable se rompe y cayó sobre las piernaslesionando gravemente.";
         accidents[type][4] = "En reunión gremial se sufre una lesión en el tobillo al momento de bajar de tarima.";
         break;
      case 4:
         accidents[type][0] = "Empleado sufre tendinitis producido de los continuos movimientos de gillotina y manejo de papeles.";
         accidents[type][1] = "Empleado sufre inmovilidad de brazo derecho producido por el uso continuo de mouse sin un equipamiento adecuado.";
         accidents[type][2] = "Empleado sufre perdida visual considerable producido del trabajo con pantallas y mala iluminación";
         accidents[type][3] = "Trabajador sufre sindrome del tunel carpeano por trabajar diariamente en escritorio con una posición poco ergonomica";
         accidents[type][4] = "Trabajador encargado de atención al publico sufre estrés laboral por las acciones relacionadas";
         break;
      case 5:
         accidents[type][0] = "Trabajador sufre asalto a las afuras de oficina.";
         accidents[type][1] = "Empleado sufre violencia en transporte camino a la oficina";
         accidents[type][2] = "Trabajador sufre robo de auto en camino al trabajo";
         accidents[type][3] = "Trabajador es apuñalado al momento de salir de su casa al trabajo";
         accidents[type][4] = "Empleado es golpeado para quitarle sus pertenencias en camino al trabajo";
         break;
      case 6:
         accidents[type][0] = "Secretaría sufre cachetada al momento de atender a cliente molesto";
         accidents[type][1] = "Mientras se recibia paquete de papeleria, repartidor entra en conflicto con empleado y este ultimo sufre golpes";
         accidents[type][2] = "Persona externa ingresa a oficina y atacó a empleado";
         accidents[type][3] = "Empleado es atacado por cliente cuando atendía consultas extraordinarias";
         accidents[type][4] = "Secretaría sufre cachetada al momento de atender a cliente molesto";
         break;
      case 7:
         accidents[type][0] = "Empleado es golpeado por subalterno tras discutir por un proyecto";
         accidents[type][1] = "Trabajador es golpeado por jefe directo tras fuerte discución, investigación pendiente.";
         accidents[type][2] = "Empleado queda gravemente lesionado tras riña con compañero de sección";
         accidents[type][3] = "Tras discutir en el baño empleado es empujado por compañero terminando en grave lesión.";
         accidents[type][4] = "Trabajador es golpeado por jefe directo tras fuerte discución, investigación pendiente.";
         break;
      case 8:
         accidents[type][0] = "Empleado sufre caida en restaurant cercano a la oficina, termina llendo directamente a centro de salud.";
         accidents[type][1] = "Trabajador sufre quemadura en casino de la oficina durante el almuerzo.";
         accidents[type][2] = "Durante almuerzo, empleado sufre intoxicación severa producto de comida marina";
         accidents[type][3] = "Empleado sufre corte producido por un vaso quebrado, debido al fuerte sangrado acude a centro de salud";
         accidents[type][4] = "En camino a casino sufre lesión en el tobillo al bajar por escalera.";
         break;
      
      case 9:
         accidents[type][0] = "Limpiador de ventanas muere tras caer y queda cuerpo expuesto frente a oficina";
         accidents[type][1] = "Trabajador sufre combulsiones en espacio de trabajo";
         accidents[type][2] = "Empleado comete suicidio en espacio de trabajo, se deriva a compañero a tratamiento psicologico";
         accidents[type][3] = "Mientras se reparaba conexión electrica electricista sufre grave electroshock, switch automatico no funcionó bien";
         accidents[type][4] = "Motociclista choca contra ventana de oficina, no hay lesiones graves a trabajador.";
         break;
      default:
         break;
   }
}

void InitializeAccidents()
{
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
   
   accidents = (char***)malloc(sizeof(char**) * nAccidentsTypes);
   
   for(int i = 0; i < nAccidentsTypes; i++)
   {
      accidents[i] = (char**)malloc(sizeof(char*) * accidentsPerType);
      SetAccidents(i);
   }
      
}
