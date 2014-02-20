import web
from datetime import date

urls = (
    '/(.*)', 'aplicacion_fecha' # en el caso de que sea la expresion regular /(.*) llamamos a la clase hello
)


app = web.application(urls, globals())


class aplicacion_fecha:      
    def GET(self, name):
        if not name: 
			d = date.today()
        return d


if __name__ == "__main__":
    app.run()



