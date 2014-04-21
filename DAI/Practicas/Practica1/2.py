#!/usr/bin/env python3

import random
import time

def cronometro(funcion):
   def funcion_a_ejecutar(*argumentos):
       # Tiempo de inicio de ejecución.
       inicio = time.time()
       # Lanzamos función a ejecutar.
       ret = funcion(*argumentos)
       # Tiempo de fin de ejecución.
       fin = time.time()
       # Tiempo de ejecución.
       tiempo_total = fin - inicio
       # Devolvemos el tiempo de ejecución.
       return tiempo_total
   # Devolvemos la función que se ejecuta.
   return funcion_a_ejecutar



def burbuja(v):
	""" Esta funcion ordena un vector utilizando el metodo burbuja """
	for i in range(0,len(v)-1):
		for j in range(0,len(v)-1):
			if v[j] > v[j+1]:
				aux = v[j+1]
				v[j+1] = v[j]
				v[j] = aux
	return v



def inserccion(v):
	""" Esta funcion ordena un vector utilizando el metodo de inserccion """
	for i in range(0,len(v)-1):
		if v[i+1] < v[i]:
			m = i
			while v[i+1] < v[i] and m > 0: 
				aux = v[i]
				v[i] = v[i+1]
				v[i+1] = aux
				m -= 1
	return v


vec1 = []

for i in range(0,10): #en este bucle rellenamos el vector con numeros aleatorios
  vec1.append(random.randint(0,100))

print('Vector inicial: ', vec1)

tiempo1 = cronometro(burbuja)(vec1)
print('\nOrdenacion mediante burbuja:',tiempo1)

tiempo2 = cronometro(inserccion)(vec1)
print('\nOrdenacion mediante inserccion:', tiempo2)
