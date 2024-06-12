##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

MAIN	=	main.c

EXEC 	=	parser_json

CS 		=	./coding_style/coding-style.sh

LOG		=	./coding_style/coding-style-reports.log

REPORTS =	./coding_style/

SRC 	=	$(wildcard src/*.c)

OBJ 	=	$(SRC:.c=.o)

SRC_LIB	=	$(wildcard library/memlib/*.c) 		\
			$(wildcard library/arraylib/*.c) 	\
			$(wildcard library/strlib/*.c)		\
			$(wildcard library/mathlib/*.c)		\
			$(wildcard library/my_printf/*.c)	\
			$(wildcard library/iolib/*.c)

RM 	=	rm -f

LIB_PATH = libmy.a

LIB_NAME = my

LIB_CR	=	-lcriterion --coverage

OBJ_LIB	=	$(SRC_LIB:.c=.o)

TESTS	= 	$(wildcard tests/strlib_tests/*.c) 	\
			$(wildcard tests/memlib_tests/*.c)	\
			$(wildcard tests/mathlib_tests/*.c)	\

TESTS_SRC	=	$(TESTS:.c=.o)

TEST_EXEC	=	unit_test

LIB_FLAGS	=	-L . -l my -I include

CFLAGS	=	-W -Wall -Wextra -Werror

all: $(LIB_PATH) $(OBJ)
	$(CC) -g3 $(MAIN) $(OBJ) $(LIB_FLAGS) $(CFLAGS) -o $(EXEC)

all: $(LIB_PATH)
	$(CC) -g3 $(MAIN) $(SRC) $(LIB_FLAGS) $(CFLAGS) -o $(EXEC)

$(LIB_PATH): $(OBJ_LIB)
	ar rc $(LIB_PATH) $(OBJ_LIB)
	make clean

.PHONY: clean fclean norm

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_LIB)
	$(RM) *~
	$(RM) vgcore*

fclean: clean
	$(RM) $(EXEC)
	$(RM) $(LIB_PATH)
	$(RM) *.out

norm: fclean
	$(CS) . $(REPORTS)
	cat $(LOG)

re: clean all
