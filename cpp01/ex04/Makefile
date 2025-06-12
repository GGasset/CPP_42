

CPP_FILES=main.cpp cpp_replace.cpp
O_FILES=$(patsubst %.cpp,%.o,$(CPP_FILES))
NAME=replace
COMPILATION_FLAGS=-c -Wall -Werror -Wextra -std=c++98

all: ${NAME}

${NAME}: ${O_FILES}
	c++ -o ${NAME} ${O_FILES} ${LIBFT_NAME}

%.o: %.cpp
	c++ ${COMPILATION_FLAGS} $?

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${O_FILES}


.phony: all ${NAME} re fclean clean