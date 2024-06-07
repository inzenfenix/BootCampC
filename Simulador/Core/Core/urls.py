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
    path('PorcentajeAccidentes/', views.Cantidad_Accidentes_total.as_view(),name='Cantidad Accidente por tipo'), #Servicio 1
    path(f'AccidentesEntreFechas/<desde>/<hasta>/', views.Accidentes_entre_fechas.as_view(),name='Entre años'), #Servicio 2
    path(f'DatosFicha/<nombre>/', views.Datos_ficha.as_view(),name='Datos Ficha'), #Servicio 3
    path('Nombres/', views.Listado_personas.as_view(),name='Nombres'), #Servicio 4
    path('CantidadAccidentesPorSexo/', views.Cantidad_Accidentes_PorSexo.as_view(),name='Cantidad Accidentes Por Sexo'), #Servicio 5
    path('CantidadAccidentesEmbarazo/', views.Cantidad_Accidentes_embarazo.as_view(),name='Cantidad accidentes embarazo'), #Servicio 6
    path(f'CantidadAccidentesEdad/<edad_min>/<edad_max>/', views.Cantidad_Accidentes_edad.as_view(),name='Accidentes por edad'), #servicio 7
    path('AccidentesSindical/', views.Accidentes_PorSindical.as_view(),name='Accidentes Por Sindical'), #Servicio 8
    path('Procedimiento/', views.Get_Accidentes_Procedimiento.as_view(),name='Procedimiento'), #Servicio 9
    path('SinProcedimiento/', views.Get_Accidentes_Sin_Procedimiento.as_view(),name='Sin Procedimiento'), #Servicio 9.1
    path(f'DiasPerdidos/<dia_min>/<dia_max>/', views.Get_Accidentes_DiasPerdidos.as_view(),name='Dias Perdidos'), #Servicio 10
    path(f'AccidentesFechaSexo/<sexo>/<desde>/<hasta>/', views.Accidentes_Fecha_Sexo.as_view(),name='Accidente fecha sexo'), #Servicio 11
    path(f'CantidadAccidentesFechaSexo/<sexo>/<desde>/<hasta>/', views.Cantidad_Accidentes_Fecha_Sexo.as_view(),name='Cantidad Accidentes fecha sexo'), #Servicio 11.1
    path(f'FechaSexoEmbarazo/<desde>/<hasta>/<sexo>/', views.Accidentes_Fecha_sexo_embarazo.as_view(),name='Fecha sexo embarazo'), #Servicio 12
    path(f'AccidenteFechaEmbarazoEdad/<sexo>/<edad_min>/<edad_max>/', views.Accidentes_sexo_embarazo_edad.as_view(),name="Accidentes sexo embarazo edad"), #Servicio 13
    path(f'AccidenteEmbarazoDiasPerdidos/<dia_min>/<dia_max>/', views.Accidentes_Embarazo_DiasPerdidos.as_view(),name='Dias perdidos embarazo'), #Servicio 14
    path('AccidenteSindicalProcedimiento/', views.Accidentes_SindicalProcedimiento.as_view(),name='Accidnete procedimiento sindical'), #Servicio 15
    path(f'CantidadIncidentes/<fecha_inicio>/', views.CantidadIncidentes.as_view(),name='Incidentes'), #Propuesta Servicio: Cantidad de Incidentes
    path(f'Accidentes/<name>/', views.Accidentes_nombre.as_view(),name='Accidentes de __')#Propuesta Servicio: Accidentes de una persona
]
