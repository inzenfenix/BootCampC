# Generated by Django 5.0.4 on 2024-05-28 16:19

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('web', '0003_accidente_persona_delete_datosmodel'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='persona',
            name='dias_perdidos',
        ),
        migrations.AddField(
            model_name='accidente',
            name='dias_perdidos',
            field=models.IntegerField(default=0),
        ),
    ]
