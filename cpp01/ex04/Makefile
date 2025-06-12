

CPP_FILES=main.cpp
O_FILES=$(patsubst %.cpp,%.o,$(CPP_FILES))
NAME=replace
COMPILATION_FLAGS=-c -Wall -Werror -Wextra -std=c++98
LIBFT_NAME=./libft/libft.a


all: ${NAME}

${NAME}: libft ${O_FILES}
	c++ -o ${NAME} ${O_FILES} ${LIBFT_NAME}

%.o: %.cpp
	c++ ${COMPILATION_FLAGS} $?

re: fclean all

fclean: clean
	rm -f ${NAME}

clean: libft_fclean
	rm -f ${O_FILES}

libft:
	make --directory=./libft all

libft_fclean:
	make --directory=./libft fclean

.phony: all ${NAME} re fclean clean libft libft_fclean