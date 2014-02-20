#!/usr/bin/python
# -*- coding: utf-8 -*-

# Practicas de Desarrollo de Aplicaciones para Internet (DAI)
# Copyright (C) 2013 - Zerjillo (zerjioi@ugr.es)
#    
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#   
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#   
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.



from formulario2 import *
import web
             
urls = (
    '/formulario', 'Formulario', # 
)



app = web.application(urls, globals())

# Gestionamos el error 404 (not found)
def notfound():
    return web.notfound("Lo siento, la p&aacute;gina que buscas no existe. Prueba con /formulario")

# Asignamos el gestor del not found de la aplicación web a la función anterior
app.notfound = notfound

if __name__ == "__main__":
    app.run()