from django.db import models

class Accidente(models.Model):
    id = models.AutoField(primary_key=True)
    descripcion = models.CharField(max_length=10, null=True)
    contexto = models.CharField(max_length=10, null=True)   
    fecha = models.DateTimeField(auto_now_add=True)
    procedimiento_aplicado = models.BooleanField(default=True)

    def __str__(self):
        return f'{self.id} {self.descripcion} {self.contexto} {self.fecha}'

class Persona(models.Model):
    id = models.AutoField(primary_key=True)
    nombre = models.CharField(max_length=20)
    rut = models.CharField(max_length=20)
    sexo = models.CharField(max_length=1, null=True)
    embarazo = models.BooleanField(default=True)
    sindical = models.BooleanField(default=True)
    edad = models.IntegerField(default=0)
    dias_perdidos = models.IntegerField(default=0)
    accidentes = models.ForeignKey(Accidente, on_delete=models.PROTECT, null=True)
    
    def __str__(self):
        return f'{self.id} {self.nombre} {self.rut} {self.sexo} {self.embarazo} {self.accidentes.procedimiento_aplicado} {self.sindical} {self.edad} {self.dias_perdidos} {self.accidentes.descripcion} {self.accidentes.contexto} {self.accidentes.fecha}'

