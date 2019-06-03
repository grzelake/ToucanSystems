#! /usr/bin/env python3

N = int(input("Wprowadz N: "))
lista = []
for i in range(N):
    x = input("Wprowadz liczbe: ")
    lista.append(x)
for i in lista:
    print(i)
while len(lista)!=0:
    x = lista[0]
    del lista[0]
    print(x)
    print(lista)
    if len(lista) == 0:
        print("Lista jest pusta")
N = int(input("Wprowadz N: "))
lista = []
for i in range(N):
    x = input("Wprowadz liczbe: ")
    lista.append(x)
for i in lista:
    print(i)
while len(lista)!=0:
    x = lista[len(lista)-1]
    del lista[len(lista)-1]
    print(x)
    print(lista)
    if len(lista) == 0:
        print("Lista jest pusta")
