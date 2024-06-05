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
    path('simulador/', views.GetSimuladorDataView.as_view(),name='Simulador'),
    path(f'entre/<desde>/<hasta>/', views.Accidentes_entre_fechas.as_view(),name='Entre anos'), #Servicio 2
    path('Nombres',views.Listado_personas.as_view(),name='Nombres'), #Servicio 4
    path('AccidentesPorSexo/',views.AccidentesPorSexo.as_view(),name='Accidentes Por Sexo'),
    path('AccidentesSindical/',views.AccidentesPorSindical.as_view(),name='Accidentes Por Sindical'), #Servicio 8
    path('procedimiento/', views.Get_Accidente_Procedimiento.as_view(),name='procedimiento'), #Servicio 9
    path(f'diasperdidos/<dia1>/<dia2>/', views.Get_Accidente_DiasPerdidos_range.as_view(),name='diasrango'), #Servicio 10.1
    path(f'diasperdidos/<dia>/<condicion>/', views.Get_Accidente_DiasPerdidos.as_view(),name='dias'), #Servicio 10.2
]
