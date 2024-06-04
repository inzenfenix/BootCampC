from rest_framework import views
from rest_framework.response import Response
from django.core import serializers
from django.http import HttpResponse
import json as js
from subprocess import PIPE, Popen
from .models import Accidente_por_persona
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
        print(results)
        for r in results:
            datos = r.split(',')
            print(datos,'datos')
            if len(datos) > 1:
                print(datos[0])
                persona = Persona()
                #persona.id = 
                persona.nombre = datos[0] 
                persona.rut = datos[1]
                persona.edad= datos[2]
                persona.sexo = datos[3]
                persona.embarazo = datos[4]
                persona.sindical = datos[5]
                #persona.Accidentes = 
                if not (persona in Persona.objects.all()):
                    persona.save()
                    print(persona)
                else:
                    print('esa persona ya esta')

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