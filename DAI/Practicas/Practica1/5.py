#!/usr/bin/env python3

import random

num = random.randint(2,12) #tamaño que tendrá el array
v = []

for i in range(0,num):
	n = random.randint(0,10) #en función de si este número es par o impar introducimos en el array el carácter '[' ó ']'
	if n%2 == 0:
		v.append('[')
	else:
		v.append(']')

#imprimos los caracteres
for i in range(0,len(v)):
	print(v[i],end='') #el argumento end es para quitar el salto de linea en cada print


#el primer filtro es comprobar el tamaño del array, si es impar podemos decir que es incorrecto
if len(v)%2 != 0:
	print('->Incorrecto')
else: #si el tamaño es par, la segunda comprobacion es si existe el mismo número de los tipos de caracteres
	a = 0
	b = 0
	c = 0
	for i in range(0,len(v)):
		if v[i] == '[':
			a += 1
		else:
			b += 1

	if a != b:
		print('->Incorrecto')
	else:#si tiene el mismo número de ambos, tenemos que comprobar que esta balanceada
		if v[0] == ']':
			print('->Incorrecto')
		else:#sino comprobamos que cada vez que se complete un 'abre-cierra', luego no quede como primero un 'cierra'
			i = 0
			while i < len(v) and c != -1:
				if v[i] == '[':
					c += 1
				else:
					c -= 1
				i += 1

			if c == 0:
				print('->Correcto')
			else:
				print('->Incorrecto')

print()
