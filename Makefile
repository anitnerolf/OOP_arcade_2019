##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME		=	arcade

NAME_SFML	=	./lib/lib_arcade_sfml.so

NAME_NCURSES	=	./lib/lib_arcade_ncurses.so

NAME_PACMAN	=	./games/libarcade_pacman.so

NAME_SNAKE	=	./games/libarcade_snake.so

CORE_SRC	=	./Core/main.cpp \
			./Core/Menu.cpp

COREOBJ		=	$(CORE_SRC:.cpp=.o)

SFML_SRC	=	./lib/Sfml.cpp

NCURSES_SRC	=	./lib/Ncurses.cpp

SFMLOBJ		=	$(SFML_SRC:.cpp=.o)

NCURSESOBJ	=	$(NCURSES_SRC:.cpp=.o)

PACMAN_SRC	=	./games/Pacman.cpp

SNAKE_SRC	=	./games/Snake.cpp

PACMANOBJ	=	$(PACMAN_SRC:.cpp=.o)

SNAKEOBJ	=	$(SNAKE_SRC:.cpp=.o)

CPPFLAGS	+=	-fPIC -c -W -Wall -Wextra  -std=c++11

LDFLAGS		=	-ldl -g3

all:	main games1 games2 graphicals1 graphicals2

main:	$(COREOBJ)
	g++ -o $(NAME) $(COREOBJ) -ldl

games1:	$(PACMANOBJ)
	g++ -o $(NAME_PACMAN) -shared $(PACMANOBJ)

games2:	$(SNAKEOBJ)
	g++ -o $(NAME_SNAKE) -shared $(SNAKEOBJ)

graphicals1:	$(SFMLOBJ)
	g++ -o $(NAME_SFML) -shared $(SFMLOBJ) -lm -lsfml-graphics -lsfml-window -lsfml-system

graphicals2:	$(NCURSESOBJ)
	g++ -o $(NAME_NCURSES) -shared $(NCURSESOBJ) -lncurses

clean:
	rm -f $(COREOBJ)
	rm -f $(SFMLOBJ)
	rm -f $(PACMANOBJ)
	rm -f $(NCURSESOBJ)
	rm -f $(SNAKEOBJ)

fclean:	clean
	rm -f *~ core/include/*~ $(NAME)
	rm -f lib/*~ $(NAME_SFML)
	rm -f games/*~ $(NAME_PACMAN)
	rm -f $(NAME_NCURSES)
	rm -f $(NAME_SNAKE)

re:	fclean all

.PHONY:	all clean fclean re

