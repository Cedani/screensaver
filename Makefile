##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		main.c 					\
				manage_window.c 		\
				screensaver_1.c 		\
				drawing_functions.c 	\
				animation_1.c			\
				my_getnbr.c				\
				my_strcmp.c				\
				second_anim.c			\
				add_second.c 			\
				third_anim.c 			\



NAME	=		my_screensaver

all:
		gcc -lm -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system $(SRC) -o $(NAME)

clean:
		rm -rf *.o

fclean: clean
		rm -f $(NAME)

re:	all fclean
