# Fillit

> *Une problématique récurrente en programmation : la recherche d'une
solution optimale parmi un très grand nombre de possibilités.*

Fillit est dans l'esprit une variante du jeu Tetris. Le programme prend en paramètre 
un fichier contenant une liste de `Tetriminos` (bloc de tetris), qu’il devra ensuite agencer entre eux,
pour former `le plus petit carré possible`. 
Bien que simple en apparence, la difficulté de ce probleme réside dans le fait de 
trouver une méthode de résolution fonctionnelle et surtout rapide. 
En effet le nombre de positions à tester croit énormément à mesure que le nombre Tetriminos à traiter augmente.

**Skills :**
* Algorithmie & Intelligence artificielle
* Rigueur
* Unix

**Installation**

1. `git clone https://github.com/mayer-overflow/fillit.git`
2. `cd fillit`
3. `make`

**Usage**
* `./fillit <filename>`
* `./fillit samples/sujet_2`

**Exemple 1**
```
....    ....    ....    ....
##..    ####    ....    .##.
.#..    ....    .#..    ..##
.#..    ....    .###    ....
```

**Solution**
```
DDAA
CDDA
CCCA
BBBB
```

*Si la liste de Tetriminos passée en paramètre comporte au moins une erreur, le programme affiche `error` sur la sortie standard et quitte proprement.*

**Exemple 2**
```
...#  ....  .###  ....  ....  ....  ##..  ....
...#  ....  ...#  ..##  .##.  ....  .#..  ###.
...#  ....  ....  .##.  .##.  ##..  .#..  .#..
...#  ####  ....  ....  ....  .##.  ....  ....
```

**Solution**
```
ABBBB.
ACCCEE
AFFCEE
A.FFGG
HHHDDG
.HDD.G
```





















