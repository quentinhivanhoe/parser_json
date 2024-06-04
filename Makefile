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

SRC	=	$(wildcard library/memlib/*.c) 		\
		$(wildcard library/arraylib/*.c) 	\
		$(wildcard library/strlib/*.c)		\
		$(wildcard library/mathlib/*.c)		\
		$(wildcard library/my_printf/*.c)	\
		$(wildcard library/iolib/*.c)

RM 	=	rm -f

LIB_PATH = libmy.a

LIB_NAME = my

LIB_CR	=	-lcriterion --coverage

OBJ	=	$(SRC:.c=.o)

TESTS	= 	$(wildcard tests/strlib_tests/*.c) 	\
			$(wildcard tests/memlib_tests/*.c)	\
			$(wildcard tests/mathlib_tests/*.c)	\

TESTS_SRC	=	$(TESTS:.c=.o)

TEST_EXEC	=	unit_test

LIB_FLAGS	=	-L . -l my -I include

CFLAGS	=	-W -Wall -Wextra -Werror

all: $(LIB_PATH)
	$(CC) -g3 $(MAIN) $(LIB_FLAGS) $(CFLAGS) -o $(EXEC)

$(LIB_PATH): $(OBJ)
	ar rc $(LIB_PATH) $(OBJ)
	make clean

.PHONY: clean fclean norm

clean:
	$(RM) $(OBJ)
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

tests_run: $(TESTS_SRC) $(LIB_PATH)
	$(CC) -o $(TEST_EXEC) $(TESTS_SRC) $(SRC) $(CFLAGS) $(LIB_FLAGS) $(LIB_CR)
	./$(TEST_EXEC) && gcovr -e tests/ -b

tests_clean: clean
	$(RM)	$(TESTS_SRC)
	$(RM) *.gcda
	$(RM) *.gcno

tests_fclean: tests_clean fclean
	$(RM) $(TEST_EXEC)

tests_re: tests_fclean tests_run
