from rest_framework import views
from rest_framework.response import Response
from django.core import serializers
from django.http import HttpResponse
from django.utils import timezone
from subprocess import PIPE, Popen
from .models import Accidente
from .models import Persona
from os import getcwd
import random
import json as js
import pytz

#Funcion que fecha la fecha
def fechar_fecha(fecha):
    utc=pytz.UTC
    if len(fecha.split('-')) == 1:
        fecha = timezone.datetime.strptime(f'{fecha}-1-1', "%Y-%m-%d")
    
    elif len(fecha.split('-')) == 2:
        fecha = timezone.datetime.strptime(f'{fecha}-1', "%Y-%m-%d")
        
    else:
        fecha = timezone.datetime.strptime(fecha, "%Y-%m-%d") 

    return utc.localize(fecha)

# Servicio 1
class Cantidad_Accidentes_total(views.APIView):
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
        desde = fechar_fecha(desde)
        hasta = fechar_fecha(hasta)
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
class Cantidad_Accidentes_PorSexo(views.APIView):
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
class Cantidad_Accidentes_edad(views.APIView): 
    def get(self, request, edad_min, edad_max):
        personas = Persona.objects.all()
        result = len([persona for persona in personas if persona.edad >= int(edad_min) and persona.edad <= int(edad_max)])
        return Response(f'Han ocurrido {result} accidentes a personas entre {edad_min} y {edad_max} años.')

# Servicio 8
class Accidentes_PorSindical(views.APIView):
    def get(self,request):
        qs = Persona.objects.filter(sindical=True).distinct()
        qs2 = [f"Nombre:{persona.nombre}, Accidente:{persona.Accidentes.descripcion}" for persona in qs]
        return Response(qs2)

# Servicio 9
class Get_Accidentes_Procedimiento(views.APIView): 
    def get(self, request):
        personas = Persona.objects.all()
        qs_r = [persona for persona in personas if persona.Accidentes.procedimiento_aplicado] # persona => accidente => procedimiento_aplicado
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')
    
# Servicio 9.1  Literalmente lo contrario xd    
class Get_Accidentes_Sin_Procedimiento(views.APIView):
    def get(self,request):
        personas = Persona.objects.all()
        qs_r = [persona for persona in personas if not persona.Accidentes.procedimiento_aplicado] # persona => accidente => procedimiento_aplicado
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 10
class Get_Accidentes_DiasPerdidos(views.APIView): 
    def get(self, request, dia_min, dia_max):
        accidentes = Accidente.objects.all()
        if dia_min == 'n':
            dia_min = 0
        else:
            dia_min = int(dia_min)
        if dia_max == 'n':
            dia_max = 9001
        else:
            dia_max = int(dia_max)

        qs_r = [accidente for accidente in accidentes if accidente.dias_perdidos >= dia_min and accidente.dias_perdidos <= dia_max]
        qs_json = serializers.serialize('json', qs_r)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 11
class Accidentes_Fecha_Sexo(views.APIView):
    def get(self,request,sexo,desde,hasta):
        desde = fechar_fecha(desde)
        hasta = fechar_fecha(hasta)

        

        qs = [accidente for accidente in Accidente.objects.all() if accidente.fecha >= desde and accidente.fecha <= hasta]
        qs_json = serializers.serialize('json', qs)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 11.1 Dice cantidad envez de accidentes
class Cantidad_Accidentes_Fecha_Sexo(views.APIView):
    def get(self,request,sexo,desde,hasta):

        desde = fechar_fecha(desde)
        hasta = fechar_fecha(hasta)

        cantidad = Persona.objects.filter(sexo=sexo).filter(Accidentes__fecha__range=(desde, hasta)).count()

        if sexo == "M":
            sexo = "Mujeres"
        else:
            sexo = "Hombres"
        
        return Response(f'Hay {cantidad} accidentes de {sexo} entre {desde} y {hasta}.')

# Servicio 12
class Accidentes_Fecha_sexo_embarazo(views.APIView): 
    def get(self, request, desde, hasta, sexo):
        personas = Persona.objects.all()
        desde = fechar_fecha(desde)
        hasta = fechar_fecha(hasta)

        result = [persona.Accidentes for persona in personas if (persona.Accidentes.fecha >= desde and persona.Accidentes.fecha <= hasta and persona.sexo == sexo and persona.embarazo)]
        qs_json = serializers.serialize('json', result)
        return HttpResponse(qs_json, content_type='application/json')

# Servicio 13 
class Accidentes_sexo_embarazo_edad(views.APIView):
    def get(self,request,sexo,edad_min, edad_max):
        personas = Persona.objects.filter(sexo=sexo)
        personas = [persona for persona in personas if (persona.embarazo and persona.edad>= int(edad_min) and persona.edad <= int(edad_max))]
        
        if sexo == "M":
            sexo = "Mujeres"
        else:
            sexo = "Hombres"

        return Response(f'Hay {len(personas)} {sexo} entre {edad_min} y {edad_max} años que sufrieron accidentes estando embarazadas.')
    
# Servicio 14
class Accidentes_Embarazo_DiasPerdidos(views.APIView):
    def get(self, request, dia_min, dia_max):
        return HttpResponse(serializers.serialize('json',[persona for persona in Persona.objects.all() if persona.embarazo and persona.Accidentes.dias_perdidos >= int(dia_min) and persona.Accidentes.dias_perdidos <= int(dia_max)]), content_type='application/json')

# Servicio 15
class Accidentes_SindicalProcedimiento(views.APIView):
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

        fecha_inicio = fechar_fecha(fecha_inicio)

        accidentes = Accidente.objects.filter(dias_perdidos=0, fecha__gte=fecha_inicio).count() #gte=greater than pa no olvidarme
        return Response(f'Desde {fecha_inicio} han habido {accidentes} incidentes.')
    

#Propuesta Servicio: Accidentes de una persona
class Accidentes_nombre(views.APIView):
    def get(self,request,name):
        personas = Persona.objects.filter(nombre=name)
        result = [f'Accidentes de {name}']
        for persona in personas:
            result.append(f'Accidente{persona.Accidentes}')
        return Response(result)
    
#Propuesta Servicio: Aplicar Procedimiento:
class Aplicar_Procedimiento(views.APIView):
    def get(self,request,name,num_accidente):
        personas = Persona.objects.filter(nombre=name)
        accidentes = [persona.Accidentes for persona in personas]
        accidente = accidentes[int(num_accidente)-1]
        accidente.procedimiento_aplicado = True
        accidente.save()
        return Response(f'El Procedimiento ha sido exitosamente aplicado.')


#Post y Get
class GetSimuladorDataView(views.APIView):

    def post(self,request):
        ruta = getcwd() + "/web/bin/"
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
                    if len(datos_accidente) > 1:
                        accidente = Accidente()
                        accidente.descripcion = datos_accidente[0].strip('/')
                        accidente.contexto = datos_accidente[1]
                        accidente.dias_perdidos = datos_accidente[2]
                        accidente.procedimiento_aplicado = datos_accidente[3]
                        if len(datos_accidente[4].split('-')) == 3:
                            accidente.fecha = datos_accidente[4].strip('/')
                        accidente.save()
                        
                        is_new_person = 1 > random.randint(0,9)
                        if (datos[0] in nombres_personas and not is_new_person):

                            persona_datos = Persona.objects.filter(nombre=datos[0])[0]
                            persona = Persona()
                            
                            persona.nombre = persona_datos.nombre
                            persona.rut = persona_datos.rut
                            diferencia_de_tiempo = int(accidente.fecha.split('-')[0]) - int(str(persona_datos.Accidentes.fecha).split('-')[0])
                            persona.edad= persona_datos.edad + diferencia_de_tiempo
                            persona.sexo = persona_datos.sexo
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

