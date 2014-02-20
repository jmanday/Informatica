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

from web import form

# Creamos el formulario. Su ámbito es global

formularioFractal = form.Form( 
    form.Textbox("x1", description = "x1:", value="-1.0"),
    form.Textbox("y1", description = "y1:", value="-1.0"),
    form.Textbox("x2", description = "x2:", value="1.0"),
    form.Textbox("y2", description = "y2:", value="1.0"),
    form.Textbox("anchura", description = "Anchura (en píxeles):", value="400"),
    form.Textbox("iteraciones", description = "Número máximo de iteraciones:", value="255"),  
    form.Button("Renderiza el Fractal"),
) 

# Una clase para generar un formulario
class Formulario:        
  
    # El método GET devolverá el formulario para que lo rellene el usuario
    def GET(self):
        form = formularioFractal()  # Hacemos una copia del formulario para evitar que se use la misma información en distintas llamadas

        # Creamos el HTML de la página "a pelo". Usualmente no se hará así (utilizaremos templates)
        html = """
        <html>
          <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            <title>Ejemplo de Formulario</title>
            <link rel="stylesheet" href="static/comun.css">
            <link rel="stylesheet" href="static/moonchild.css">
            <link rel="stylesheet" href="static/formulario.css">
          </head>
          <body>
            <h1>Ejemplo de Formulario</h1>
            
            <p>Un formulario creado con <code>form</code> de <code>web.py</code>.</p>
            <p>Lo usaremos para luego generar un fractal en el siguiente ejercicio.</p>
            
            <form method="POST">
            %s
            </form>
          </body>
        </html>""" % (form.render())  # Renderizamos el formulario dentro del tag <form>. Dicho tag indica que el formulario se pasará por el método POST (típico) a la misma página que lo contiene, por lo que lo gestionaremos en el método POST(self) de más abajo.
        
        return html
      
    # El método POST devolverá la página donde se gestionan los datos introducidos por el usuario
    def POST(self): 
        form = formularioFractal() 
        
        form.validates()  # Validamos el formulario para obtener los valores del usuario (y si tuvieramos algun validador lo ejecutaría!)
        
        html = """
        <html>
          <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            <title>Ejemplo de Formulario Enviado</title>
            <link rel="stylesheet" href="static/comun.css">
            <link rel="stylesheet" href="static/moonchild.css">
            <link rel="stylesheet" href="static/formulario.css">
          </head>
          <body>
            <h1>Ejemplo de Formulario Enviado</h1>
            
            <p>Esta página es la que gestiona el formulario enviado por el usuario. Si esperabas que ya pintase el fractal, la llevas clara, que eso es parte del siguiente ejercicio.</p>
            
            <p>Aquí solo diremos que el fractal que ha pedido el usuario es el que va desde <code>(%.2f, %.2f)</code> a <code>(%.2f, %.2f)</code>, de <code>%d</code> píxeles de ancho y <code>%d</code> iteraciones de máximo.</p>
            
            <p>¡Que pases un buen día!</p>
          </body>
        </html>""" % (float(form.d.x1), float(form.d.y1), float(form.d.x2), float(form.d.y2), int(form.d.anchura), int(form.d.iteraciones)) 
        
        return html
