#!/usr/bin/env python3

f = open('fichero.txt') #abrimos el fichero en modo lectura (por defecto)

linea = f.read() #leemos todos lo que hay en el fichero
num = int(linea) #transformamos a int

f.close() #cerramos el fichero del que hemos leído

f = open('salida.txt', 'w') #abrimos (en este caso se crea ya que no existe) el fichero destino

v = []
# algoritmo de fibonacci, los vamos introduciendo en un vector y nos quedamos con el ultimo elemento
for i in range(0,num):
	if i < 2:	
		v.append(i)
	else:
		v.append(v[i-1] + v[i-2])

f.write(str(v[len(v)-1])) #escribimos en el fichero de salida
f.close() #cerramos el fichero de salida
