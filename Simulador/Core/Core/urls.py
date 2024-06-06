"""
URL configuration for Core project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from web import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('simulador/', views.GetSimuladorDataView.as_view(),name='Simulador'), #Post y Get
    path()#Servicio 1
    path(f'AccidentesEntreFechas/<desde>/<hasta>/', views.Accidentes_entre_fechas.as_view(),name='Entre anos'), #Servicio 2
    path(f'DatosFicha/<nombre>/',views.Datos_ficha.as_view(),name='Datos Ficha'), #Servicio 3
    path('Nombres/',views.Listado_personas.as_view(),name='Nombres'), #Servicio 4
    path('AccidentesPorSexo/',views.AccidentesPorSexo.as_view(),name='Accidentes Por Sexo'), #Servicio 5
    path()#Servicio 6
    path(f'AccidentesEdad/<edad>/',views.Accidentes_edad.as_view(),name='Accidentes por edad'), #servicio 7
    path('AccidentesSindical/',views.AccidentesPorSindical.as_view(),name='Accidentes Por Sindical'), #Servicio 8
    path('Procedimiento/', views.Get_Accidente_Procedimiento.as_view(),name='procedimiento'), #Servicio 9
    path(f'DiasPerdidos/<dia1>/<dia2>/', views.Get_Accidente_DiasPerdidos.as_view(),name='diasperdidos'), #Servicio 10
    path()#Servicio 11
    path(f'FechaSexoEmbarazo/<fecha>/<sexo>/',views.Fecha_sexo_embarazo.as_view(),name='Fecha sexo embarazo'), #Servicio 12
    path()#Servicio 13
    path(f'AccidenteEmbarazoDiasPerdidos/<dias>/',views.AccidenteEmbarazoDiasPerdidos.as_view(),name='Dias perdidos embarazo'), #Servicio 14
    path('AccidenteSindicalProcedimiento/',views.AccidenteSindicalProcedimiento.as_view(),name='Accidnete procedimiento sindical'), #Servicio 15
    path(f'CantidadIncidentes/<fecha_inicio>/', views.CantidadIncidentes.as_view(),name='Incidentes') #Propuesta Servicio: Cantidad de Incidentes
]
