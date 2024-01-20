# Macros
CC = gcc
CFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O -Wconversion -std=c89 -Wno-implicit-fallthrough

OBJECT = main.o drawHelper.o bitwise.o dp_console.o
EXE = main.exe
ERASE = rm

# Targets
$(EXE) : $(OBJECT)
	$(CC) -o $(EXE) $(OBJECT)
	$(ERASE) $(OBJECT)

%.o : %.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean :
	$(ERASE) $(EXE)

run :
	./$(EXE)