from rest_framework import views
from rest_framework.response import Response
from django.core import serializers
from django.http import HttpResponse
from django.utils import timezone
import json as js
from subprocess import PIPE, Popen
from .models import Accidente
from .models import Persona


class Accidentes_entre_fechas(views.APIView):#Servicio 2
    def get(self,request,desde,hasta):

        if len(desde.split('-')) == 1:
            desde = timezone.datetime.strptime(f'{desde}-1-1', "%Y-%m-%d")
        if len(hasta.split('-')) == 1:
            hasta = timezone.datetime.strptime(f'{hasta}-1-1', "%Y-%m-%d")

        qs = Persona.objects.filter(Accidentes__fecha__range=(desde, hasta)).distinct().count()
        return Response(f'Hay {qs} accidentes entre {desde} y {hasta}.')
    
class Listado_personas(views.APIView): #Servicio 4
    def get(self,request):
        qs = Persona.objects.values_list('nombre',flat=True)
        qs2 = [f"{persona}" for persona in qs]
        return Response(qs2)

#Servicio 5
class AccidentesPorSexo(views.APIView):
    def get(self,request):
        qsM = Persona.objects.filter(sexo="M").count()
        qsF = Persona.objects.filter(sexo="F").count()
        return Response(f"Los hombres tuvieron: {qsM} accidentes y las mujeres: {qsF}") 

#Servicio 8
class AccidentesPorSindical(views.APIView):
    def get(self,request):
        qs = Persona.objects.filter(sindical=True).distinct()
        qs2 = [f"Nombre:{persona.nombre}, Accidente:{persona.Accidentes.descripcion}" for persona in qs]
        return Response(qs2)
    
#Propuesta Servicio: Cantidad de Incidentes
class CantidadIncidentes(views.APIView):
    def get(self,request, fecha_inicio):
        fecha_inicio = timezone.datetime.strptime(fecha_inicio, "%Y-%m-%d")  
        qi = Accidente.objects.filter(dias_perdidos=0, fecha__gte=fecha_inicio).count() #gte=greater than pa no olvidarme
        return Response(f'Desde {fecha_inicio} han habido {qi} incidentes.')

    

class Get_Accidente_Procedimiento(views.APIView): # Servicio 9
    def get(self, request):
        qs = Persona.objects.all()
        qs_r = [x for x in qs if x.Accidentes.procedimiento_aplicado == 1] # persona => accidente => procedimiento_aplicado
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')

class Get_Accidente_DiasPerdidos_range(views.APIView): # Servicio 10_v1
    def get(self, request, dia1, dia2): #dia1 = rango inferior, dia2 = rango superior
        qs = Persona.objects.all() 
        qs_r = [x for x in qs if x.Accidentes.dias_perdidos > int(dia1) and x.Accidentes.dias_perdidos < int(dia2)]
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')

class Get_Accidente_DiasPerdidos(views.APIView): # Servicio 10_v2 **funca mal usar el 10_v1
    def get(self, request, dia, condicion): # condicion => menor,mayor o igual (cualquier cosa => igual)
        qs = Persona.objects.all()
        if (condicion == 'mayor'):
            qs_r = [x for x in qs if x.Accidentes.dias_perdidos > int(dia)]
        elif (condicion == 'menor'): # retornara el dia y sus 
            qs_r = [x for x in qs if x.Accidentes.dias_perdidos < int(dia)]
        else:
            qs_r = [x for x in qs if x.Accidentes.dias_perdidos == int(dia)]
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')
    
class GetSimuladorDataView(views.APIView):

    def post(self,request):
        ruta = "/home/shadom/Documents/GitHub/BootCampC/Simulador/Core/web/bin/"
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
        print(qs)
        qs_json = serializers.serialize('json', qs)
        return HttpResponse(qs_json, content_type='application/json')

    def __exec(self,base, cmd, params=''):
        res = Popen("{}{} {}".format(base, cmd, params), stdout=PIPE, stderr=PIPE, shell=True)
        res.wait()
        out, err = res.communicate()
        cad = ''.join(e for e in out.decode("utf-8"))
        return cad  
