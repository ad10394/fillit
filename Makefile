# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayer <amayer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 13:41:58 by amayer            #+#    #+#              #
#    Updated: 2019/04/09 06:01:44 by amayer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
HEADERS = fillit.h
SRC = main.c \
		reader.c \
		map.c \
		solver.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft 

OBJ = $(SRC:%.c=%.o)

%.o: %.c $(HEADERS)
	gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

clean2:
	rm -f $(OBJ)

fclean: clean2
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re clean2


# cible: dependance
#		commandes



# hello: hello.o main.o
#	gcc -o hello hello.o main.o

# doit remplir la dependance hello.o avant de continuer donc :

# hello.o: hello.c
#	gcc -o hello.o -c hello.c -Wall -Wextra -Werror

# aucune dependance de hello.o n'est une regle , on peut donc continuer
#la cmd est execute seulement si le fichier hello.c est plus recent que hello.o


#Une variable se déclare sous la forme NOM=VALEUR et se voir utiliser via $(NOM).

#	$@	Le nom de la cible
#	$<	Le nom de la première dépendance
#	$^	La liste des dépendances
#	$?	La liste des dépendances plus récentes que la cible
#	$*	Le nom du fichier sans suffixe

# Génération de la liste des fichiers objets a partir des .c
# OBJ = $(SRC:%.c=%.o)


# apres avoir rempli cette dependance il va traiter les .o obtenu puisque c une regle

#	construire un .o a partir d'un .c
#	%.o: %.c
#		gcc -o $@ -c $< $(FLAGS)


#	pour que main.o soit recompile is hello.h est modifie
#	main.o: hello.h


# gcc
# -c
# Compile or assemble the source files, but do not link. 
# The output is an object file for each source file. 

# -o file
# if '-o' is not specified, the default output is "a.out"
# if specified you can chose the name of the executable

# Supposons que clean soit également le nom d'un fichier présent 
# dans le répertoire courant, il serait alors forcément plus récent 
# que ses dépendances et la règle ne serait alors jamais exécutée.
# Pour pallier ce problème, il existe une cible particulière nommée .PHONY 
# dont les dépendances seront systématiquement reconstruites.


# RUN A MAKE FILE FROM OTHER DIR
# make -C dir
# OR
# (cd /other/dir && make)


# to use library
# -L : where the lib reside
# -l : lib name
# -L libft/ -lft 