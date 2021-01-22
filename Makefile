SRC	=	src/*.cpp \
		lib/imgui/*.cpp

CFLAGS = 	-W -Wall -Wextra -g
CXXFLAGS = 	-W -Wall -Wextra -g

INCLUDE = 	-I./include -I./lib/

LIB = -L./lib/Logger -lLogger -lncurses -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-network -lm -lGL -lGLEW

NAME 	=	a.out

all:	$(NAME)

$(NAME):
	make re -C lib/Logger
	g++ -g -std=c++17 -o $(NAME) $(SRC) $(INCLUDE) $(LIB) 
clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf vg*

re: fclean all

debug: $(CFLAGS) += -g fclean all