#!/usr/bin/python3
from battleships_libcpp.build import pythonGame

lista = [True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, False, True, False, False, False, True]
a = pythonGame.Game(lista, lista)
print (a.IsGood())
