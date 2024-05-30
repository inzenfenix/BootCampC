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
        results = self.__exec(ruta,comando).split("\n")
        for r in results:
            datos = r.split(',')
            if len(datos) > 1:
                print(datos[1])
                persona = Persona()
                persona.id = datos[0]
                persona.nombre = datos[1] 
                persona.rut = datos[2]
                persona.sexo = datos[3]
                persona.edad= datos[4]
                persona.embarazo = datos[5]
                persona.sindical = datos[6]
                persona.Accidentes = datos[7]
                persona.save()   
        return Response(js.dumps(results))
        
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