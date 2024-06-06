from rest_framework import views
from rest_framework.response import Response
from django.core import serializers
from django.http import HttpResponse
from django.utils import timezone
import json as js
from subprocess import PIPE, Popen
from .models import Accidente
from .models import Persona
from os import getcwd

# Servicio 1
class Cantidad_Accidente_total(views.APIView):
    def get(self,request):
        accidentes = Accidente.objects.all()
        accidentes_tipo_1 = [accidente for accidente in accidentes if accidente.contexto == "Accidente a causa de trabajo"]        
        accidentes_tipo_2 = [accidente for accidente in accidentes if accidente.contexto == "Accidente en traslado entre dependencias"]        
        accidentes_tipo_3 = [accidente for accidente in accidentes if accidente.contexto == "Accidente en el contexto de una actividad organizada por empleador"]
        accidentes_tipo_4 = [accidente for accidente in accidentes if accidente.contexto == "Accidente de dirigente sindical"]
        accidentes_tipo_5 = [accidente for accidente in accidentes if accidente.contexto == "Sintomas de enfermedad producidos por quehacer laboral"]
        accidentes_tipo_6 = [accidente for accidente in accidentes if accidente.contexto == "Violencia de tipo 1"]
        accidentes_tipo_7 = [accidente for accidente in accidentes if accidente.contexto == "Violencia de tipo 2"]
        accidentes_tipo_8 = [accidente for accidente in accidentes if accidente.contexto == "Violencia de tipo 3"]
        accidentes_tipo_9 = [accidente for accidente in accidentes if accidente.contexto == "Accidente en horario colacion"]
        accidentes_tipo_10 = [accidente for accidente in accidentes if accidente.contexto == "Situaciones disruptivas y de alta complejidad"]

        todo_tipo = [accidentes_tipo_1,accidentes_tipo_2,accidentes_tipo_3,accidentes_tipo_4,accidentes_tipo_5,accidentes_tipo_6,accidentes_tipo_7,accidentes_tipo_8,accidentes_tipo_9,accidentes_tipo_10]
        tipo = 0
        response = ''
        for accidente in todo_tipo:
            tipo += 1
            response += f'El {round(len(accidente)/len(accidentes)*100,2)}% de los accidentes es del tipo {tipo}.'
        return HttpResponse(response)

# Servicio 2
class Accidentes_entre_fechas(views.APIView):
    def get(self,request,desde,hasta):

        if len(desde.split('-')) == 1:
            desde = timezone.datetime.strptime(f'{desde}-1-1', "%Y-%m-%d")
        
        elif len(desde.split('-')) == 2:
            desde = timezone.datetime.strptime(f'{desde}-1', "%Y-%m-%d")
        
        else:
            desde = timezone.datetime.strptime(desde, "%Y-%m-%d") 

        if len(hasta.split('-')) == 1:
            hasta = timezone.datetime.strptime(f'{hasta}-1-1', "%Y-%m-%d")

        elif len(hasta.split('-')) == 2:
            hasta = timezone.datetime.strptime(f'{hasta}-1', "%Y-%m-%d")

        else:
            hasta = timezone.datetime.strptime(hasta, "%Y-%m-%d")                    
                                   

        qs = Persona.objects.filter(Accidentes__fecha__range=(desde, hasta)).distinct().count()
        return Response(f'Hay {qs} accidentes entre {desde} y {hasta}.')
    
# Servicio 3
class Datos_ficha(views.APIView): 
    def get(self, request, nombre):
        personas = Persona.objects.all()
        result = [persona for persona in personas if persona.nombre == nombre]
        qs_json = serializers.serialize('json', result)
        return HttpResponse(qs_json, content_type='application/json')
    
# Servicio 4   
class Listado_personas(views.APIView): 
    def get(self,request):
        nombres = Persona.objects.values_list('nombre',flat=True)
        qs2 = [f"{nombre}" for nombre in nombres]
        return Response(qs2)
    
# Servicio 5
class AccidentesPorSexo(views.APIView):
    def get(self,request):
        qsM = Persona.objects.filter(sexo="M").count()
        qsF = Persona.objects.filter(sexo="F").count()
        response_text = (
            f"Los hombres tuvieron: {qsM} accidentes\n"
            f"y las mujeres: {qsF} accidentes"
        )
        return Response(response_text)

# Servicio 6
class Cantidad_Accidentes_embarazo(views.APIView):
    def get(self,request):
        personas = Persona.objects.all()
        embarazo = [persona.Accidentes for persona in personas if persona.embarazo]
        print(embarazo)
        return Response(f'Hay {len(embarazo)} personas que sufrieron accidentes estando embarazadas, esto equivale al {len(embarazo)/len(personas)*100}% de las personas.')

# Servicio 7
class Accidentes_edad(views.APIView): 
    def get(self, request, edad):
        qs = Persona.objects.all()
        result = [x for x in qs if x.edad == edad]
        qs_json = serializers.serialize('json', result)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 8
class AccidentesPorSindical(views.APIView):
    def get(self,request):
        qs = Persona.objects.filter(sindical=True).distinct()
        qs2 = [f"Nombre:{persona.nombre}, Accidente:{persona.Accidentes.descripcion}" for persona in qs]
        return Response(qs2)

# Servicio 9
class Get_Accidente_Procedimiento(views.APIView): 
    def get(self, request):
        qs = Persona.objects.all()
        qs_r = [x for x in qs if x.Accidentes.procedimiento_aplicado == True] # persona => accidente => procedimiento_aplicado
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 10
class Get_Accidente_DiasPerdidos(views.APIView): 
    def get(self, request, dia1, dia2): #dia1 = rango inferior, dia2 = rango superior
        qs = Persona.objects.all()
        if dia1 == 'n':
            dia1 = 0
        else:
            dia1 = int(dia1)
        if dia2 == 'n':
            dia2 = 9001
        else:
            dia2 = int(dia2)

        qs_r = [x for x in qs if x.Accidentes.dias_perdidos >= dia1 and x.Accidentes.dias_perdidos <= dia2]
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')
   
# Servicio 11
class Accidentes_Fecha_Sexo(views.APIView):
    def get(self,request,sexo,desde,hasta):

        if len(desde.split('-')) == 1:
            desde = timezone.datetime.strptime(f'{desde}-1-1', "%Y-%m-%d")
        if len(hasta.split('-')) == 1:
            hasta = timezone.datetime.strptime(f'{hasta}-1-1', "%Y-%m-%d")

        cantidad = Persona.objects.filter(sexo=sexo).filter(Accidentes__fecha__range=(desde, hasta)).count()

        if sexo == "M":
            sexo = "Mujeres"
        else:
            sexo = "Hombres"
        
        return Response(f'Hay {cantidad} accidentes de {sexo} entre {desde} y {hasta}.')

# Servicio 12
class Fecha_sexo_embarazo(views.APIView): 
    def get(self, request, fecha, sexo):
        qs = Persona.objects.all()
        result = [x for x in qs if x.Accidentes.fecha == fecha and x.sexo == sexo and x.embarazo == True]
        qs_json = serializers.serialize('json', result)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 13
class Accidentes_sexo_embarazo_edad(views.APIView):
    def get(self,request,sexo,edad):
        personas = Persona.objects.filter(sexo=sexo)
        personas = [persona for persona in personas if (persona.embarazo and persona.edad == edad)]
        
        if sexo == "M":
            sexo = "Mujeres"
        else:
            sexo = "Hombres"

        return Response(f'Hay {len(personas)} {sexo} con {edad} anos que sufrieron accidentes estando embarazadas.')

# Servicio 14
class AccidenteEmbarazoDiasPerdidos(views.APIView):
    def get(self, request, dias):
        return HttpResponse(serializers.serialize('json',[persona for persona in Persona.objects.all() if persona.embarazo == True and persona.Accidentes.dias_perdidos == dias]), content_type='application/json')

# Servicio 15
class AccidenteSindicalProcedimiento(views.APIView):
    def get(self,request):
        qs = Persona.objects.filter(sindical=True).distinct()
        qs2 = []
        for persona in qs:
            accidentes_persona = [persona.Accidentes for persona in qs if persona.Accidentes.procedimiento_aplicado]
            for accidente in accidentes_persona:
                qs2.append(f"Nombre:{persona.nombre}, Accidente:{accidente.descripcion}")
        return Response(qs2)   
    
#Propuesta Servicio: Cantidad de Incidentes
class CantidadIncidentes(views.APIView):
    def get(self,request, fecha_inicio):

        if len(fecha_inicio.split('-')) == 1:
            fecha_inicio = timezone.datetime.strptime(f'{fecha_inicio}-1-1', "%Y-%m-%d")
        else:
            fecha_inicio = timezone.datetime.strptime(fecha_inicio, "%Y-%m-%d")

        qi = Accidente.objects.filter(dias_perdidos=0, fecha__gte=fecha_inicio).count() #gte=greater than pa no olvidarme
        return Response(f'Desde {fecha_inicio} han habido {qi} incidentes.')

#Post y Get
class GetSimuladorDataView(views.APIView):

    def post(self,request):
        ruta = getcwd() + "/web/bin/"
        print(ruta)
        comando = "FinalRandomizer"
        results = self.__exec(ruta,comando).split("/n")
        nombres_personas = set([nombre.nombre for nombre in Persona.objects.all()])
        for r in results:
            datos = r.split(',')
            if datos == ['']:
                continue
            if len(datos) > 1:
                for accidentes in datos[6].split('//'):
                    datos_accidente = accidentes.split('*')
                    print(datos_accidente)
                    if len(datos_accidente) > 1:
                        accidente = Accidente()
                        accidente.descripcion = datos_accidente[0].strip('/')
                        accidente.contexto = datos_accidente[1]
                        accidente.dias_perdidos = datos_accidente[2]
                        accidente.procedimiento_aplicado = datos_accidente[3]
                        print(datos_accidente[4].strip('/'))
                        if len(datos_accidente[4].split('-')) == 3:
                            accidente.fecha = datos_accidente[4].strip('/')


                        if accidente not in Accidente.objects.all():
                            accidente.save()

                        if datos[0] in nombres_personas:

                            persona = [persona for persona in Persona.objects.all() if persona.nombre == datos[0]][0]

                            print(persona,'\n\n\n\n')
                            persona.embarazo = datos[4]
                            persona.sindical = datos[5]
                            persona.Accidentes = accidente

                        else:
                            nombres_personas.add(datos[0])
                            persona = Persona()
                            persona.nombre = datos[0] 
                            persona.rut = datos[1]
                            persona.edad= datos[2]
                            persona.sexo = datos[3]
                            persona.embarazo = datos[4]
                            persona.sindical = datos[5]
                            persona.Accidentes = accidente
                        persona.save()

        return Response((results))
        
    def get(self, request):
        qs = Persona.objects.all()
        qs_json = serializers.serialize('json', qs)
        return HttpResponse(qs_json, content_type='application/json')

    def __exec(self,base, cmd, params=''):
        res = Popen("{}{} {}".format(base, cmd, params), stdout=PIPE, stderr=PIPE, shell=True)
        res.wait()
        out, err = res.communicate()
        cad = ''.join(e for e in out.decode("utf-8"))
        return cad  
