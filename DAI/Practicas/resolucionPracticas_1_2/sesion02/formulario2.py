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

from borraFicherosAntiguos import *
from mandelbrot import *
from web import form
import os.path
from time import time



# Creamos el formulario. Su ámbito es global

formularioFractal = form.Form( 
    form.Textbox("x1", description = "x1:", value="-2.1"),
    form.Textbox("y1", description = "y1:", value="-1.3"),
    form.Textbox("x2", description = "x2:", value="0.7"),
    form.Textbox("y2", description = "y2:", value="1.3"),
    form.Textbox("anchura", description = "Anchura (en píxeles):", value="500"),
    form.Textbox("iteraciones", description = "Número máximo de iteraciones:", value="255"),  
    form.Dropdown('paleta', [('azules', 'Azules'), ('bn', "Blanco y Negro"), ('grises', "Grises"), ('dolor', 'Dolor de Ojos'), ('dolor2', 'Dolor de Ojos Suave')], description="Paleta:"),
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
            <title>Fractal de Mandelbrot</title>
            <link rel="stylesheet" href="static/comun.css">
            <link rel="stylesheet" href="static/moonchild.css">
            <link rel="stylesheet" href="static/formulario.css">
          </head>
          <body>
            <h1>Fractal de Mandelbrot</h1>
            
            <p>Generaremos un fractal a partir de los datos que nos facilites en este formulario.</p>
            
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
        
        if (form.d.paleta == "azules"):
            paleta = [(255, 255, 255), (173, 205, 244), (255, 255, 255)]
            nColores = 15
        elif (form.d.paleta == "bn"):
            paleta = [(0, 0, 0), (255, 255, 255)]
            nColores = 2
        elif (form.d.paleta == "dolor"):
            paleta = [(255, 0, 0), (255, 255, 0), (255, 0, 255), (0, 255, 0), (0, 255, 255), (0, 0, 255)]
            nColores = 6
        elif (form.d.paleta == "dolor2"):
            paleta = [(255, 0, 0), (255, 255, 0), (255, 0, 255), (0, 255, 0), (0, 255, 255), (0, 0, 255)]
            nColores = 18
        elif (form.d.paleta == "grises"):
            paleta = [(0, 0, 0), (255, 255, 255)]
            nColores = 10
          
        nombreFichero = """static/mandelbrot_%f_%f_%f_%f_%d_%d_%s.png""" % (float(form.d.x1), float(form.d.y1), float(form.d.x2), float(form.d.y2), int(form.d.anchura), int(form.d.iteraciones), str(form.d.paleta))
        
        
        # Sistema de caché
        fechaActual = time()
        borraFicherosAntiguos("static/", "mandelbrot_", fechaActual - 24 * 60 * 60) # Ojo, esto es un poco borrico, porque se ejecuta cada vez que se sirve la página. Lo suyo sería asegurarnos que no se ejecuta, por ejemplo, nada más que una vez cada 10 minutos. Se puede hacer con un fichero con la ultima vez que se hizo el borrado y evitando otros borrados antes de que pasen los 10 minutos, pero no vamos a complicar más este código
        
        encontradoEnCache = "NO"
        # Si no existe (cacheado en el directorio static), lo renderizamos 
        if not os.path.isfile(nombreFichero):
            renderizaMandelbrotBonito(float(form.d.x1), float(form.d.y1), float(form.d.x2), float(form.d.y2), int(form.d.anchura), int(form.d.iteraciones), nombreFichero, paleta, nColores);
        else:
            encontradoEnCache = "SI"
            
        
        html = """
        <html>
          <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            <title>Fractal Generado</title>
            <link rel="stylesheet" href="static/comun.css">
            <link rel="stylesheet" href="static/moonchild.css">
            <link rel="stylesheet" href="static/formulario.css">
          </head>
          <body>
            <h1>Fractal Generado</h1>
            
            <p>Esta página es la que gestiona el formulario enviado por el usuario renderizando un fractal de Mandelbrot. Los datos del fractal son: desde <code>(%.2f, %.2f)</code> a <code>(%.2f, %.2f)</code>, de <code>%d</code> píxeles de ancho, <code>%d</code> iteraciones de máximo y la paleta <code>%s</code>.</p>
            
            <p>El fichero <code>%s</code> se ha encontrado en cache.</p>
            
            <p class="pImg">
              <img src="/%s" />
            </p>
          </body>
        </html>""" % (float(form.d.x1), float(form.d.y1), float(form.d.x2), float(form.d.y2), int(form.d.anchura), int(form.d.iteraciones), str(form.d.paleta), encontradoEnCache, nombreFichero)
        
        return html
