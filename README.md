# ZPR
BIBLIOTEKA C++<br>
W katalogu "battleships_libcpp" znajduje się biblioteka dynamiczna w C++, przystosowana do użytkowania w pythonie.<br>
Biblioteka służy przechowywaniu i przetwarzaniu danych związanych z grą w "Statki", inaczej zwana również grą w "Okręty".<br>
<br>WYMAGANIA<br>
Biblioteka używa standardu C++17 oraz bibliotekę boost_python<br>
Kompilacja programu wymaga oprócz kompilatora zainstalowanego pythona, opocjonalnie narzędzie SCons do kompilacji przez przygotowane skrypty kompilacyjne.<br>
<br>KOMIPLACJA<br>
Do komiplacji programu przygotowany jest skrypt pythonowy (SConstruct).<br>
Aby go uruchomić należy przejść do folderu "Build", w którym znajduje się plik "SConstruct", w którym trzeba podać ścieżki do nagłówków biblioteki boost, pythona oraz biblioteki boost_python, następnie w podanym katalogu otworzyć terminal i wpisać polecenie "scons".<br>
Przy załączaniu bliblioteki do programów należy podawać ścieżkę do pliku "libpythonGame.so", który po kompilacji będzie znajdował się w podkatalogu "Build".<br>
<br>TESTY<br>
Do kompilacji testów jednostkowych przygotowano skrypt SConstruct, znajdujący się w podkatalogu "Test"<br>

