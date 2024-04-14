CC := gcc
CFLAGS := -Wall -Wextra -Wconversion -O2
SRC := main.c
OBJ := main.o

output: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o output

$(OBJ): $(SRC)
	$(CC) $(SRC) -c

clean:
	rm $(OBJ)

uninstall:
	rm output
