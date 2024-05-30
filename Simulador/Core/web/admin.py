from django.contrib import admin
from .models import Persona
from .models import Accidente_por_persona

admin.site.register(Persona)
admin.site.register(Accidente_por_persona)
