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


# A class to serve a Moon web page
class Moon:        
    def GET(self, name):
        if not name: 
            name = 'Moonchild'
        else:
            name = str(name)  # Para evitar problemas de codificación
            
        # Creamos el HTML de la página "a pelo". Usualmente no se hará así (utilizaremos templates)
        html = """
        <html>
          <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            <title>%s Page</title>
            <link rel="stylesheet" href="static/comun.css">
            <link rel="stylesheet" href="static/moonchild.css">
          </head>
          <body>
            <h1>Welcome to my Realm, %s</h1>
            
            <p>Aquí tenemos nuestra primera página HTML servida con <code>web.py</code></p>
            
            <p class="pImg">
              <a href="/static/lunilla.jpg"><img src="/static/lunilla.jpg" style="width: 400px;"  title="Pincha para verla más grande" /></a><br />
              Foto por <a href="http://laazotea.org/moon_11_09_2013">La Azotea</a> (Zerjillo y A. Román)
            </p>
          </body>
        </html>""" % (name, name)
        
        return html