# -*- coding: utf-8 -*-
# Generated by Django 1.11.16 on 2022-07-13 15:37
from __future__ import unicode_literals

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('ews', '0006_rename_patch_id_field_to_change_id'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='Patch',
            new_name='Change',
        ),
        migrations.RenameField(
            model_name='build',
            old_name='patch',
            new_name='change',
        ),
    ]