
RAW_MATERIA_SOURCES=MateriaSource.cpp
MATERIA_SOURCES=$(addprefix Sources/,$(RAW_MATERIA_SOURCES))

RAW_MATERIAS=AMateria.cpp Cure.cpp Ice.cpp $(MATERIA_SOURCES)
Materia=$(addprefix Materias/,$(RAW_MATERIAS))

RAW_CHARACTERS=Character.cpp
Characters=$(addprefix Characters/,$(RAW_CHARACTERS))

CPP_FILES=main.cpp
CPP_FILES+=$(Materia)
CPP_FILES+=$(Characters)
O_FILES=$(patsubst %.cpp,%.o,$(CPP_FILES))

INCLUDE=-I Characters -I Materias -I Materias/Sources
COMPILATION_FLAGS= $(INCLUDE) -c -g3 -Wall -Werror -Wextra -std=c++98
NAME=MateriaWorld

all: ${NAME}

${NAME}: ${O_FILES}
	c++ -o ${NAME} ${O_FILES} ${LIBFT_NAME}

%.o: %.cpp
	c++ ${COMPILATION_FLAGS} -o $@ $?

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${O_FILES}


.phony: all ${NAME} re fclean clean