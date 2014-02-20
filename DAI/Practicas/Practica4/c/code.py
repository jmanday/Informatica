# -*- coding: utf-8 -*-

import re
import web
from web import form
from web.contrib.template import render_mako
import pymongo
from bson.objectid import ObjectId
from pymongo import Connection
from pymongo.errors import ConnectionFailure
from lxml import etree
import sys
import urllib
import feedparser		# libreria para rss remotos
import time
import tweepy


urls = (
    '/', 'inicio' ,
	'/login', 'classlogin',
	'/logout', 'classlogout',
	'/historial', 'classhistorial',
	'/registro', 'classregistro',
	'/busqueda', 'classbusqueda',
	'/intro_rss', 'classrss',
	'/ingresos', 'classingresos',
	'/sedes', 'classedes',
	'/twitter', 'classtwitter',
	'/nuevo_estado_twitter', 'class_nuevo_estado_twitter',
	'/buscar_contenido_twitter', 'class_buscar_contenido_twitter',
	'/ver_estados_twitter', 'class_ver_estados_twitter',
	'/idioma_tweet', 'class_idioma_tweet',
)

# Para poder usar sesiones con web.py
web.config.debug = False

app = web.application(urls, globals())

# inicializamos la variable session a cadena vacía porque inicialmente no hay ningún usuario que haya iniciado sesion
session = web.session.Session(app, web.session.DiskStore('sessions'), initializer={'usuario':''})

# templates de mako
render = render_mako(
	directories=['templates'],
	input_encoding='utf-8',
	output_encoding='utf-8',
)


# Colocamos las claves para el manejo de aplicaciones de twitter
CONSUMER_KEY = 'h4bXmMd17UrqoTCnAu9v5g'
CONSUMER_SECRET = 'FfjY1x6JrLnReNxQBEt7KDJxsSiBvVpYkKp6JZIH4'
ACCESS_KEY = '2162658013-rrgTdJPcyK87TH41vHiZhjLSkDucNd2Sesku1ip'
ACCESS_SECRET = 'VZJZcxjWxkxjH6rmY2JqLeWAsj5OquLTMS7hO3K5xjFgT'


#En esta parte nos identifica para poder realizar operaciones
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)


# expresiones regulares para controlar el email, el numero de visa y los enlaces rss que se introduzcan
email = re.compile(r'\w+@([a-z]+\.)+[a-z]+')
visa = re.compile(r'(\d){4}\-(\d){4}\-(\d){4}\-(\d){4}|(\d){16}')
rss = re.compile(r'http://(.+)\.xml')



# Conexion local por defecto
try:
	print "Conectando a MongoDB en localhost..."		
	conexion = pymongo.Connection(host="127.0.0.1", port=27017)
	print "Conexion satisfactoria"
except ConnectionFailure, e:
	print "No se pudo conectar a MongoDB - Error: %s" % e
	


# creando/obteniendo un objeto que referencie a la base de datos.
db = conexion['bdregistro'] #base de datos a usar 


# coleccion con registros de los usuarios
datos = db['usuarios'] 	


# coleccion con registros de los enlaces de rss
datos_rss = db['enlaces_rss']


# coleccion con registros de los ingresos
datos_ingresos = db['ingresos']


# variable global donde vamos almacenando las variables que le mandamos a las paginas
variableMako = {}


# variable globla donde vamos almacenando las noticias de los rss
Makonoticias = []


# variable global para no poder acceder a cualquier pagina sin haberse registrado antes
acceso = 0


# lista para almacenar el historial
historial = ["", "", ""]


# formulario de visitas
form_ingresos = form.Form(
	form.Dropdown('ingreso', ['1000', '1100', '1200','1300', '1400', '1500', '1600', '1700', '1800', '1900', '2000'], description="Cantidad:   "),
	form.Dropdown('tipo_grafica', ['barras vertical', 'linea', 'tarta', 'barras horizontal'], description="Grafica:   "),
	form.Button ('Ingresar'),
)


# formulario de registro
myform = form.Form( 
    form.Textbox('nombre', maxlength="22", description="Nombre:"),
	form.Textbox('apellidos', maxlength="22", description="Apellidos:"),
	form.Textbox('dni', maxlength="9", size="9", description="DNI:"),
	form.Textbox('correo', maxlength="25", size="15", description="Correo Electronico:"),
	form.Dropdown('dia', range(1,32), description="Dia:"),
	form.Dropdown('mes', range(1,12), description="Mes:"),
	form.Dropdown('anio', range(1930,2013), description="Anio:"),
	form.Textarea('direccion', maxlength="55", size="35", description="Direccion:"),	
	form.Password('passw', maxlength="17", size="12", description="Password:"),
	form.Password('passw2', maxlength="17", size="12", description="Repetir:"),
	form.Radio('forma_pago', ['contra reembolso', 'visa'], description="Forma de pago:"),
	form.Textbox('numero_visa', maxlength="19", size="20", description="Numero Visa"),
    form.Checkbox('check',
		form.Validator("Debe aceptar las clausulas.", lambda i: "check" not in i), description="Acepto"), 
	form.Button('Aceptar'),
	
	
    validators = [
		form.Validator('El campo nombre no puede estar vacio.', lambda i: len(str(i.nombre))>0),
		form.Validator('El campo apellidos no puede estar vacio.', lambda i: len(str(i.apellidos))>0),
		form.Validator('El campo dni no puede estar vacio.', lambda i: len(str(i.dni))>0),
		form.Validator('El campo correo no puede estar vacio.', lambda i: len(str(i.correo))>0),
		form.Validator('El campo direccion no puede estar vacio.', lambda i: len(str(i.direccion))>0),
		form.Validator('El campo numero visa no puede estar vacio.', lambda i: len(str(i.numero_visa))>0),
		form.Validator('Fecha Incorrecta.', lambda x: not(
			(int(x.dia)==31 and int(x.mes)==2) or 
			(int(x.dia)==30 and int(x.mes)==2) or 
			(int(x.dia)==29 and int(x.mes)==2 and int(x.anio)%4!=0) or 
			(int(x.dia)==31 and (int(x.mes)==4 or int(x.mes)==6 or int(x.mes)==9 or int(x.mes)==11))
		)),  
		form.Validator("Formato de correo no valido.", lambda i: email.match(i.correo)),
		form.Validator("Formato de numero de visa no valido.", lambda i: visa.match(i.numero_visa)),
		form.Validator("El password debe contener mas de 7 caracteres.", lambda i: len(str(i.passw))>7),
		form.Validator("El password debe contener mas de 7 caracteres.", lambda i: len(str(i.passw2))>7),
		form.Validator('El password no coindice.', lambda i: i.passw == i.passw2)

		]
)


# formulario de login
formlogin = form.Form (
	form.Textbox ('username', form.notnull, description='Usuario:'),
	form.Password ('password', form.notnull, description=u'Contraseña:'),
	form.Button ('Enviar'),

)


# formulario de busqueda
form_buscar = form.Form (
	form.Textbox ('dni', form.notnull, maxlength="9", size="9", description='Dni del usuario:'),
	form.Button ('Enviar'),
)


# formulario de rss
form_rss = form.Form (
	form.Textbox ('enlace_rss', form.notnull, maxlength="80", size="22", description='RSS:'),
	form.Button ('Introducir'),

	validators = [
		form.Validator("Formato de enlace rss no valido.", lambda i: rss.match(i.enlace_rss))
	]	
)


# formulario twitter cambiar estado
form_twitter1 = form.Form (
	form.Textbox ('estado_twitter', form.notnull, maxlength="80", size="22", description='Nuevo estado:'),
	form.Button ('Cambiar'),
)


# formulario twitter buscar contenido
form_twitter2 = form.Form (
	form.Textbox ('contenido_twitter', form.notnull, maxlength="80", size="22", description='Contenido:'),
	form.Button ('Buscar'),
)


# formulario de busqueda
form_buscar_usuario = form.Form (
	form.Textbox ('username', form.notnull, maxlength="20", size="12", description='tweet:'),
	form.Button ('Buscar'),
)


def comprueba_sesion():
	global acceso, variableMako
	
	if not session.usuario: # si la variable session.usuario sigue siendo igual a cadena vacía
		mensaje = "Usuario no autentificado."
		enlace1 = "<a href=\"login\">Login</a>"
		enlace2 = ""
		enlace3 = ""
		enlace4 = ""
		enlace5 = ""
		enlace6 = ""
		acceso = 0
	else:
		mensaje = "Usuario autentificado: " + session.usuario
		enlace1 = "<a href=\"logout\">Logout</a>"
		enlace2 = "<a href=\"historial\">Historial</a>"
		enlace3 = "<a href=\"registro\">Registro</a>"
		enlace4 = "<a href=\"busqueda\">Buscar</a>"
		enlace5 = "<a href=\"intro_rss\">RSS</a>"
		enlace6 = "<a href=\"twitter\">Twitter</a>"
		acceso = 1

	enlace_ingresos = "<a href=\"ingresos\">Ingresos</a>"
	enlace_sedes = "<a href=\"sedes\">Sedes</a>"
	mensaje_usuario = mensaje
	enlace_login = enlace1	
	enlace_historial = enlace2	
	enlace_registro = enlace3
	enlace_busqueda = enlace4
	enlace_rss = enlace5
	enlace_twitter = enlace6

	v = {"correo": "jmanday@gmail.com", "login": enlace_login, "usuario": mensaje_usuario, "historial": enlace_historial, "registro": enlace_registro, "busqueda": enlace_busqueda, "rss": enlace_rss, "ingresos": enlace_ingresos, "sedes": enlace_sedes, "twitter": enlace_twitter}
	

	variableMako = v


# guardo el tiempo en el que se ejecuta por primera vez el programa		
t = int(time.time())
var = 0


def comprobar_actualizacion(): 	# funcion para comprobar si ya ha transcurrido el tiempo para actualizar los rss
	global var	
	if var == 0:
		actualizar_rss()
		var += 1
	else:		
		taux = int(time.time())
		global t
		if (t + 10) < taux:
			t = taux
			actualizar_rss()

	
def	actualizar_rss():		# actualizamos los rss
	# para las noticias
	
	if db.enlaces_rss.find().count() == 0:		# si aun no hay ningun enlace rss introduzco uno
		registro_rss = {"rss": "http://ep00.epimg.net/rss/elpais/portada.xml", "ident": 1}
		datos_rss.insert(registro_rss) #inserto el enlace rss en la base de datos
		
		rss_url = "http://ep00.epimg.net/rss/elpais/portada.xml"
		d = feedparser.parse(rss_url)
		
		for i in range(0,6):
			e = d.entries[i]
			for j in e:
				if j == "title":
					titulo = e.title + "(elpais)"
					Makonoticias.append(titulo) 
	else:
		if db.enlaces_rss.count() == 1:
			resul = db.enlaces_rss.find_one({"ident":1}, {"rss":1})
			rss_url = resul["rss"]
			d = feedparser.parse(rss_url)
			
			for i in range(0,6):
				e = d.entries[i]
				for j in e:
					if j == "title":
						titulo = e.title + " [" + d.feed.title + "]"
						Makonoticias.append(titulo) 
		else:
			for n in range(1, db.enlaces_rss.count() + 1):
				resul = db.enlaces_rss.find_one({"ident":n}, {"rss":1})	

				d = feedparser.parse(resul["rss"])
			
				num = 6 / db.enlaces_rss.count()
				for i in range(0,num):
					e = d.entries[i]
					for j in e:
						if j == "title":
							titulo = e.title + " [" + d.feed.title + "]"
							Makonoticias.append(titulo) 
	

def modificar_acceso():
	global acceso
	acceso = 0



# clase que nos carga la página inicial
class inicio: 	
    def GET(self): 
	
		comprueba_sesion()
		comprobar_actualizacion()
		historial.append("/index.html")
							
		return render.index(varMako = variableMako, varNoticias = Makonoticias)



# clase para trabajar con el formulario de login
class classlogin:
	def GET(self):  #el método GET es el que primero se ejecuta, es decir, cuando se llama a la clase se ejecuta este método 
		comprueba_sesion()
		comprobar_actualizacion()
		historial.append("/login.html")					
		LoginFormulario = formlogin()
		
		#le añado el formulario renderizado
		return render.login(varMako = variableMako, formulario = LoginFormulario.render())


	def POST(self): #si ya se interactúa con lo que muestra el GET entonces se ejecuta el POST
		
		comprueba_sesion()	
		comprobar_actualizacion			
		LoginFormulario = formlogin()
				
		if not LoginFormulario.validates():
			return render.login(varMako = variableMako, formulario = LoginFormulario.render())

		else:
			i = web.input()
			usuario  = i.username
			passwd = i.password

			resul = datos.find_one({"nombre": usuario, "Password": passwd}) #buscamos al usuario
		
			if(str(resul) == "None"):
				LoginFormulario.password.set_value("")
				varLogin = "El usuario o el password no son validos." + LoginFormulario.render()
				
				return render.login(varMako = variableMako, formulario = varLogin)

			else:
				session.usuario = usuario
				comprueba_sesion()

				return render.login(varMako = variableMako, formulario = "Enhorabuena, se ha autentificado correctamente.")


# clase para trabajar con el fin de sesion
class classlogout:
	def GET(self):
	
		comprueba_sesion()	
		comprobar_actualizacion()
				
		if acceso == 1:	
			historial.append("/logout.html")
			session.kill()
			modificar_acceso()
			mensaje = "Usuario no autentificado."

			return render.logout(var1 = variableMako["correo"], var2 = mensaje) # la llamada render es a un objeto de la clase mako
		
		else:
			return render.error(var1 = variableMako["correo"], var2 = variableMako["usuario"])


# clase para trabajar con el historial de navegación
class classhistorial:
	def GET(self):

		comprueba_sesion()	
		comprobar_actualizacion()

		if acceso == 1:
			historial.append("/historial.html")
			history = {"h1": historial[len(historial)-1], "h2": historial[len(historial)-2], "h3": historial[len(historial)-3]}
			
			return render.historial(varMako = variableMako, vhistory = history)	
		
		else:
			return render.error(var1 = variableMako["correo"], var2 = variableMako["usuario"])


# clase para manejar el registro de un usuario
class classregistro:
	def GET(self):

		comprueba_sesion()	
		comprobar_actualizacion()
				
		if acceso == 1:
			print "Conectando al Servidor de Base de Datos Local..."
			historial.append("/registro.html")
			formulario_registro = myform()

			return render.registro(varMako = variableMako, var1 = formulario_registro.render())
		else:
			return render.error(var1 = variableMako["correo"], var2 = variableMako["usuario"])


	def POST(self):

		comprueba_sesion()	
		comprobar_actualizacion
		formulario_registro = myform()


		if not formulario_registro.validates():

			return render.registro(varMako = variableMako, var1 = formulario_registro.render())

		else:
			i = web.input()

			registro_usuario = {"nombre": i.nombre, "apellidos": i.apellidos, "dni": i.dni, "email": i.correo, "fecha_nac": i.dia + i.mes + i.anio, "direccion": i.direccion, "Password": i.passw, "numero_visa": i.numero_visa}

			datos.insert(registro_usuario) #inserto los datos del usuario en la base de datos

			return render.registro(varMako = variableMako, var1 = "El usuario se ha registrado correctamente.")
			

class classbusqueda:
	def GET(self):

		comprueba_sesion()	
		comprobar_actualizacion()

		if acceso == 1:
			historial.append("/busqueda.html")
			formulario_busqueda = form_buscar()

			return render.busqueda(varMako = variableMako, var1 = formulario_busqueda.render())
		else:
			return render.error(var1 = variableMako["correo"], var2 = variableMako["usuario"])

	def POST(self):

		comprueba_sesion()	
		comprobar_actualizacion()
		formulario_busqueda = form_buscar()
				
		if not formulario_busqueda.validates():
			return render.busqueda(varMako = variableMako, var1 = formulario_busqueda.render())

		else:
			i = web.input()
			dni_pas = i.dni
			res = []

			resul = datos.find_one({"dni": dni_pas}, {"nombre":1, "apellidos":1, "_id":0 }) #buscamos al usuario
			
			if str(resul) == "None":
				vaux = "No existe ningun usuario con ese dni."
			else:
							
				vaux = "Nombre: " + resul["nombre"] + "<br>" + "Apellidos: " + resul["apellidos"] + "\n"

			return render.busqueda(varMako = variableMako, var1 = vaux)			
					
		
class classrss:
	def GET(self):

		comprueba_sesion()	
		comprobar_actualizacion()

		if acceso == 1:
			historial.append("/intro_rss.html")
			formulario_rss = form_rss()

			return render.intro_rss(varMako = variableMako, var1 = formulario_rss.render())
		else:
			return render.error(var1 = variableMako["correo"], var2 = variableMako["usuario"])

	def POST(self):

		comprueba_sesion()	
		comprobar_actualizacion()
		formulario_rss = form_rss()

		if not formulario_rss.validates():
			formulario_rss.enlace_rss.set_value("")
			return render.intro_rss(varMako = variableMako, var1 = formulario_rss.render())

		else:
			i = web.input()
			
			identif = db.enlaces_rss.count() + 1
			registro_rss = {"rss": i.enlace_rss, "ident": identif}

			datos_rss.insert(registro_rss) #inserto el enlace rss en la base de datos
				
			return render.intro_rss(varMako = variableMako, var1 = "El enlace de rss se ha registrado correctamente.")


class classingresos:
	def GET(self):

		comprueba_sesion()
		comprobar_actualizacion()
		historial.append("/ingresos.html")

		formulario_ingresos = form_ingresos()
		
		return render.ingresos(varMako = variableMako, var1 = formulario_ingresos.render())

	def POST(self):

		comprueba_sesion()	
		comprobar_actualizacion()

		formulario_ingresos = form_ingresos()
		
		if not formulario_ingresos.validates():
			return render.ingresos(varMako = variableMako, var1 = formulario_ingresos.render())

		else:
			i = web.input()
						
			registro_ingreso = {"cantidad": i.ingreso}

			datos_ingresos.insert(registro_ingreso) #inserto los datos de la vista en la base de datos
			datos = {}

			datos = {"tipo_grafica": i.tipo_grafica}
	
			valores = []
			k = "1000"
			for i in range(0,11):				
				myCursor =  datos_ingresos.find({"cantidad": k})
				k = int(k) + 100
				k = str(k)	
				valores.append(myCursor.count())
						

			return render.mostrar_grafica(varMako = variableMako, vardatos = datos, datos_tabla = valores)


class classedes:
	def GET(self):
		comprueba_sesion()
		comprobar_actualizacion()

		return render.sedes(varMako = variableMako)


class classtwitter:
	def GET(self):
		comprueba_sesion()
		comprobar_actualizacion()

		return render.twitter(varMako = variableMako) 


class class_nuevo_estado_twitter:
	def GET(self):
		comprueba_sesion()
		comprobar_actualizacion()

		formulario_nuevo_estado = form_twitter1()

		return render.nuevo_estado_twitter(varMako = variableMako, var1 = formulario_nuevo_estado.render())

	def POST(self):
		comprueba_sesion()
		comprobar_actualizacion()

		i = web.input()

		#En esta parte nos identifica para poder realizar operaciones
		auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
		auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)

		x = tweepy.API(auth)
		x.update_status('@j_manday ' + i.estado_twitter)

		return render.nuevo_estado_twitter(varMako = variableMako, var1 = "El estado ha sido cambiado.")

		


class class_buscar_contenido_twitter:
	def GET(self):
		comprueba_sesion()
		comprobar_actualizacion()

		formulario_buscar_contenido = form_twitter2()

		return render.buscar_contenido_twitter(varMako = variableMako, var1 = formulario_buscar_contenido.render())

	def POST(self):
		comprueba_sesion()
		comprobar_actualizacion()

		i = web.input()
		x = tweepy.API(auth)
		var_aux = []

		for tweets in x.search(q=i.contenido_twitter,count=4, result_type='recent'): 	
			dtwitter = {"fecha": tweets.created_at, "usuario": "@" + tweets.user.screen_name, "texto": tweets.text, "salto": '\n *'*38}
			var_aux.append(dtwitter)

		return render.buscar_contenido_twitter2(varMako = variableMako, var1 = var_aux)


class class_ver_estados_twitter:
	def GET(self):
		comprueba_sesion()
		comprobar_actualizacion()

		x = tweepy.API(auth)
		var_aux = []

		for tweets in x.home_timeline(count=2): # esta funcion es la que nos permite mostrar el estado de mis amigos(count es el numero de estados)
			dtwitter = {"fecha": tweets.created_at, "usuario": "@" + tweets.user.screen_name, "texto": tweets.text, "salto": '\n *'*38}
			var_aux.append(dtwitter)
		
		return render.ver_estados_twitter(varMako = variableMako, var1 = var_aux)



class class_idioma_tweet:
	def GET(self):
		comprueba_sesion()
		comprobar_actualizacion()

		formulario_buscar = form_buscar_usuario()

		return render.idioma_tweet(varMako = variableMako, var1 = formulario_buscar.render())

	def  POST(self):
		comprueba_sesion()
		comprobar_actualizacion()

		i = web.input()
		x = tweepy.API(auth)
		a = set()
		b = []
		c = []
		m = []
		k = 0

		for tweet in x.search(q=i.username, count=100):
			b.append(tweet.user.lang)
			a.add(tweet.user.lang)

		for t1 in a:
			for t2 in b:
				if t1 == t2:
					k += 1
			vaux = {"idioma": t1, "cantidad": k}
			c.append(vaux)
			k = 0		

		return render.idioma_tweet2(varMako = variableMako, var1 = c)
		


if __name__ == "__main__":
    app.run()


