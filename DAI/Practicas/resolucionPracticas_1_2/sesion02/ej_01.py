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

# Importamos web.py
import web
        
# Creamos una lista de parejas de expresiones regulares para parsear las urls de entrada y nombres de clase que deben gestionar dichas urls. En este caso cualquier página será gestionada con la clase hello      
urls = (
    '/(.*)', 'hello'
)

# Creamos la aplicación web que use el anterior array
app = web.application(urls, globals())

# La clase hello será la encargada de gestionar las páginas de la aplicación
class hello:        
    # La clase solo contiene el método GET (por lo tanto no atendemos a POST). En name se guardará la url que ha hecho match con (.*)
    def GET(self, name):
        if not name: # En caso de que name no esté definido (se haya accedido a la página principal /)
            name = 'World'
        return 'Hello, ' + name + '!'  # Devolvemos el código de la página, que no es ni HTML ni nada, simplemente un mensaje

# Ejecutamos la aplicación web
if __name__ == "__main__":
    app.run()