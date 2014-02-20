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

import web

# A class to serve a Jupiter web page
class Sun:        
    def GET(self, name):
        if not name: 
            name = 'The Sun'
        else:
            name = str(name)  # Para evitar problemas de codificación
            
            
        params = web.input(nombre="Sin Nombre")
            
        # Creamos el HTML de la página "a pelo". Usualmente no se hará así (utilizaremos templates)
        html = """
        <html>
          <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            <title>%s Page</title>
            <link rel="stylesheet" href="static/comun.css">
            <link rel="stylesheet" href="static/sun.css">
          </head>
          <body>
            <h1>%s</h1>
            
            <p>Otra página servida <code>web.py</code>. En este caso atiende cualquier petición que empiece por <code>sun</code>, por ejemplo: <a href="http://localhost:8080/sunIsMyFavouriteStar"><code>http://localhost:8080/sunIsMyFavouriteStar</code></a>.</p>
            
            <p>Por cierto, la página admite un parametro en la url llamado <code>nombre</code>. Su valor actual es: <code>%s</code>.</p>
            
            <p class="pImg">
              <a href="/static/sun.jpg"><img src="/static/sun.jpg" style="width: 400px;" title="Pincha para verla más grande" /></a><br />
              Foto por <a href="http://laazotea.org/sun_24_05_2012">La Azotea</a> (Zerjillo y A. Román)
            </p>
          </body>
        </html>""" % (name, name, str(params.nombre))
        
        return html
