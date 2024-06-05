from django.db import models

class Accidente(models.Model):
    id = models.AutoField(primary_key=True)
    descripcion = models.CharField(max_length=10, null=True)
    contexto = models.CharField(max_length=10, null=True)   
    fecha = models.DateTimeField(auto_now_add=True)
    procedimiento_aplicado = models.BooleanField(default=True)
    dias_perdidos = models.IntegerField(default=0)

    def __str__(self):
        return f'{self.id}: ,Descripcion:{self.descripcion} ,Contexto:{self.contexto} ,Fecha:{self.fecha}'

class Persona(models.Model):
    id = models.AutoField(primary_key=True)
    nombre = models.CharField(max_length=20)
    rut = models.CharField(max_length=20)
    sexo = models.CharField(max_length=1, null=True)
    edad = models.IntegerField(default=0)
    embarazo = models.BooleanField(default=True)
    sindical = models.BooleanField(default=True)
    Accidentes = models.ForeignKey(Accidente, on_delete=models.PROTECT, null=True)
    
    def __str__(self):
        return f'{self.id}: ,Nombre:{self.nombre} ,Rut:{self.rut} ,Sexo:{self.sexo} ,Edad:{self.edad} ,Embarazo:{self.embarazo} ,Estado Sindical:{self.sindical} ,Accidente_por_personas {self.Accidentes}'

