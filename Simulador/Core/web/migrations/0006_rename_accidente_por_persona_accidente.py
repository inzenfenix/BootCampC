# Generated by Django 5.0.4 on 2024-06-04 23:54

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('web', '0005_rename_accidente_accidente_por_persona_and_more'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='Accidente_por_persona',
            new_name='Accidente',
        ),
    ]
