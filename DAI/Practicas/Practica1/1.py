#!/usr/bin/env python3

import random

y = random.randint(0,100)
i = 1
encontrado = False

while encontrado == False and i < 11:
  num = int(input('Introduce un numero: '))
  if num == y:
    print('Enhorabuena, el numero coincide')
    encontrado = True
  elif num < y:
    print('El numero buscado es mayor')
  else:
    print('El numero buscado es menor')
  i += 1  
  
if i > 10:
	print('Lo sentimos, ha agotado todos los intentos')  
