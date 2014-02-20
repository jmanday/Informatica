#!/usr/bin/python
# -*- coding: utf-8 -*-


import web
        
urls = (
	'/hola(.*)', 'Hola',
	'/adios(.*)', 'Adios'
)

app = web.application(urls, globals())

class Hola:        
    def GET(self, name):
        if not name: 
            name = 'La nueva'
        else:
            name = str(name)  # Para evitar problemas de codificación
            
            
        params = web.input(nombre="Sin Nombre") # para los parámetros que se le pasa por la url ?nombre=valor&apellidos=aaaaa
            
        # Creamos el HTML de la página "a pelo". Usualmente no se hará así (utilizaremos templates)
        html = """
        <html>
          <head>
            <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            <title>%s Pagina</title>
          </head>
          <body>
            <h1>%s</h1>
            
            <p>Otra página servida <code>web.py</code>. En este caso atiende cualquier petición que empiece por <code>hola</code></p>
            
            <p>Por cierto, la página admite un parametro en la url llamado <code>nombre</code>. Su valor actual es: <code>%s</code>.</p>
          </body>
        </html>""" % (name, name, str(params.nombre))
        
        return html


class Adios:
	def GET(self, name):
		if not name:
 			name = 'La vieja'
		else:
			name = str(name)

		# Creamos el HTML de la página "a pelo". Usualmente no se hará así (utilizaremos templates)
		html = """
		<html>
			<head>
				<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
            	<title>%s Pagina</title>
        	</head>
			<body>
				<h1>%s</h1>

				<p>Otra página servida <code>web.py</code>. En este caso atiende cualquier petición que empiece por <code>adios</doce></p>

				<p>Por cierto, la página admite un parametro en la url llamado <code>nombre</code>. Su valor actual es: <code>%s</code>.</p>
          </body>
		</html>""" % (name, name, name)

		return html


if __name__ == "__main__":
    app.run()
