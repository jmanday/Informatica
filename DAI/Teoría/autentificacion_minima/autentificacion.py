#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Autentificación mínima con
# sesiones
# dai ugr.es Oct-13

import web
from web.contrib.template import render_mako
from web import form

# Para poder usar sesiones con web.py
web.config.debug = False


urls = (
  '/', 'inicio',
  '/login', 'login',
  '/logout', 'logout',
)

app = web.application (urls, locals())

session = web.session.Session(app, web.session.DiskStore('sessions'), initializer={'usuario':''})

# Templates de mako
render = render_mako (
	directories = ['templates'],
	input_encoding = 'utf-8',
	output_encoding = 'utf-8')


login_form = form.Form (
	form.Textbox ('username', form.notnull, description='Usuario:'),
	form.Password ('password', form.notnull, description=u'Contraseña:'),
	form.Button ('Login'),
)


def password_correcto_de (usuario):
	return usuario	+'3'         # concateno un '3' al nombre de usuario
    # En la realidad habría que guardar los
    # passwords de cada usuario en una base de datos


def comprueba_identificacion (): 
	usuario = session.usuario   # Devuelve '' cuando no está identificado
	return usuario              # que es el usuario inicial 
                                  


class logout:
	def GET(self):
		usuario = session.usuario
		session.kill()
		return 'adios ' + usuario


class login:
	def POST(self):

		form = login_form ()
		if not form.validates ():
			return render.login (form=form, usuario='Nadie', mensaje = 'Esto no valida')

		i = web.input()
		usuario  = i.username
		password = i.password
		if password == password_correcto_de (usuario):
			session.usuario = usuario
			return web.seeother('/')   # Redirige a inicio
		else:
			form = login_form ()
			return render.login (form=form, usuario='Nadie', 
                                 mensaje = u'pero con el password correcto que sería ' +
                                           password_correcto_de (usuario))


# Comprueba que el usuario esté identificado
# sino se lo pide
class inicio:
	def GET(self):
		usuario = comprueba_identificacion () 
		if usuario:
			return render.inicio (usuario = usuario)
		else:
			form = login_form ()
			return render.login(form=form, usuario=usuario)  

		

if __name__ == "__main__":
    app.run()	

