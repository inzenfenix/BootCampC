from rest_framework import views
from rest_framework.response import Response
import json as js
from subprocess import PIPE, Popen



class GetSimuladorDataView(views.APIView):
    def get(self,request):
        ruta = "/home/shadom/Documents/GitHub/BootCampC/Simulador/Core/web/bin/"
        comando = "FinalRandomizer"
        res = self.__exec(ruta,comando)
        return Response(js.dumps(res))
    
    def __exec(self,base, cmd, params=''):
        res = Popen("{}{} {}".format(base, cmd, params), stdout=PIPE, stderr=PIPE, shell=True)
        res.wait()
        out, err = res.communicate()
        cad = ''.join(e for e in out.decode("utf-8"))
        return cad