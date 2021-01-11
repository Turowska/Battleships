#!/usr/bin/python3
from libcpp.build import pythonGame

lista = [True, True, False, False, False, True, False, False, False, True, False, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False]
a = pythonGame.Game(lista, lista)
print (a.Shot(0, 1))
print (a.IsSunk(0))
print (a.Shot(1, 1))
print (a.IsSunk(0))
#print (a.IsSunk(0))
#print (a.Shot(1, 1))
#print (a.IsSunk(0))
