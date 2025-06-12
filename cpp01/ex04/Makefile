

CPP_FILES=main.cpp
O_FILES=$(patsubst %.cpp,%.o,$(CPP_FILES))
NAME=replace
COMPILATION_FLAGS=-c -Wall -Werror -Wextra -std=c++98
LIBFT_NAME=./libft/libft.a
INCLUDE=-I ./libft/

all: ${NAME}

${NAME}: libft-all ${O_FILES}
	c++ ${INCLUDE} -o ${NAME} ${O_FILES} ${LIBFT_NAME}

%.o: %.cpp
	c++ ${INCLUDE} ${COMPILATION_FLAGS} $?

re: fclean all

fclean: clean
	rm -f ${NAME}

clean: libft_fclean
	rm -f ${O_FILES}

libft-all:
	make --directory=./libft all

libft_fclean:
	make --directory=./libft fclean

.phony: all ${NAME} re fclean clean libft-all libft_fclean