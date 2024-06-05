from rest_framework import views
from rest_framework.response import Response
from django.core import serializers
from django.http import HttpResponse
import json as js
from subprocess import PIPE, Popen
from .models import Accidente
from .models import Persona


class funcion_x(views.APIView):
    def get(self,request):
        ruta = "/home/shadom/Documents/GitHub/BootCampC/Simulador/Core/web/bin/"
        comando = "FinalRandomizer"
        res = self.__exec(ruta,comando)
        return Response(js.dumps(res))
    
class GetSimuladorDataView(views.APIView):

    def post(self,request):
        ruta = "/home/shadom/Documents/GitHub/BootCampC/Simulador/Core/web/bin/"
        comando = "FinalRandomizer"
        results = self.__exec(ruta,comando).split("/n")
        nombres_personas = set([nombre.nombre for nombre in Persona.objects.all()])
        for r in results:
            datos = r.split(',')
            print(datos)
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
                        accidente.procedimiento_aplicado = datos_accidente[3].strip('/')

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