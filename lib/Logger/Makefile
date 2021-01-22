SRC	=	Logger.cpp

NAME	= libLogger.a

CFLAGS = -std=c++17
CXXFLAGS = -std=c++17

OBJ	= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
