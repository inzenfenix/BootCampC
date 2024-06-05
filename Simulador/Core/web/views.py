from rest_framework import views
from rest_framework.response import Response
from django.core import serializers
from django.http import HttpResponse
from django.utils import timezone
import json as js
from subprocess import PIPE, Popen
from .models import Accidente
from .models import Persona

#Servicio 2
class Accidentes_entre_fechas(views.APIView):
    def get(self,request,desde,hasta):

        if len(desde.split('-')) == 1:
            desde = timezone.datetime.strptime(f'{desde}-1-1', "%Y-%m-%d")
        if len(hasta.split('-')) == 1:
            hasta = timezone.datetime.strptime(f'{hasta}-1-1', "%Y-%m-%d")

        qs = Persona.objects.filter(Accidentes__fecha__range=(desde, hasta)).distinct().count()
        return Response(f'Hay {qs} accidentes entre {desde} y {hasta}.')
 
class Datos_ficha(views.APIView): #Servicio 3
    def get(self, request, nombre):
        qs = Persona.object.all()
        result = [x for x in qs if x.nombre == nombre]
        qs_json = serializers.serialize('json', qs)
        return HttpResponse(qs_json, content_type='application/json')
    
 #Servicio 4   
class Listado_personas(views.APIView): 
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
    
    
#Idea de cambio para una mejor presentación
'''

class AccidentesPorSexo(views.APIView):
    def get(self,request):
        qsM = Persona.objects.filter(sexo="M").count()
        qsF = Persona.objects.filter(sexo="F").count()
        response_text = (
            f"Los hombres tuvieron: {qsM} accidentes\n"
            f"y las mujeres: {qsF} accidentes"
        )
        return Response(response_text)

'''

class Accidentes_edad(views.APIView): #Servicio 7
    def get(self, request, Edad):
        qs = Persona.object.all()
        result = [x for x in qs if x.edad == Edad]
        qs_json = serializers.serialize('json', qs)
        return HttpResponse(qs_json, content_type='application/json')

#Servicio 8
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
        qs_r = [x for x in qs if x.Accidentes.dias_perdidos > int(dia1) and x.Accidentes.dias_perdidos < int(dia2)]
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')
    
class Fecha_sexo_embarazo(views.APIView): #Servicio 12
    def get(self, request, fecha, sexo):
        qs = Persona.object.all()
        result = [x for x in qs if x.Accidentes.fecha == fecha and x.sexo == sexo and x.embarazo == True]
        qs_json = serializers.serialize('json', qs)
        return HttpResponse(qs_json, content_type='application/json')
    
#Servicio 15
class AccidenteSindicalProcedimiento(views.APIView):
    def get(self,request):
        qs = Persona.objects.filter(sindical=True).distinct()
        qs2 = []
        for persona in qs:
            accidentes_persona = persona.accidentes.filter(procedimiento_aplicado=True)
            for accidente in accidentes_persona:
                qs2.append(f"Nombre:{persona.nombre}, Accidente:{accidente.descripcion}")
        return Response(qs2)   
    
    
#Propuesta Servicio: Cantidad de Incidentes
class CantidadIncidentes(views.APIView):
    def get(self,request, fecha_inicio):
        fecha_inicio = timezone.datetime.strptime(fecha_inicio, "%Y-%m-%d")  
        qi = Accidente.objects.filter(dias_perdidos=0, fecha__gte=fecha_inicio).count() #gte=greater than pa no olvidarme
        return Response(f'Desde {fecha_inicio} han habido {qi} incidentes.')


    
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
