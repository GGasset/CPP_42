

CPP_FILES=main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
O_FILES=$(patsubst %.cpp,%.o,$(CPP_FILES))
NAME=Animal
COMPILATION_FLAGS=-c -g -Wall -Werror -Wextra -std=c++98

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