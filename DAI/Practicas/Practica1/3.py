#!/usr/bin/env python3

num = int(input('Introduzca un numero: '))
v = []
y = 0

#rellenamos el vector con los valores desde 2 hasta el número introducido
for i in range(2,num+1):
  v.append(i)
  
#algoritmo de eratostenes (vamos recorriendo el vector y comparando)  
while pow(v[y],2) < num:
  for j in range(y+1,len(v)):
    if v[j]%v[y] == 0:
      v[j] = -1
    j += 1
    
  y += 1
  while v[y] == -1:
    y += 1
  
#nos quedamos solamente con los números primos
w = []
for i in range(0,len(v)):
  if v[i] != -1:
    w.append(v[i])
    
#imprimimos el resultado
print(w)