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


# Para servir contenidos estáticos se usa el directorio "static" todo lo que haya dentro de ese directorio se sirve tal cual (imágenes, css, javascript...)

from moon import *
import web
             
urls = (
    '/(.*)', 'Moon'  # La clase Moon la importamos de moon.py, no hace falta poner aqui todas las clases a cascoporro
)
app = web.application(urls, globals())



if __name__ == "__main__":
    app.run()