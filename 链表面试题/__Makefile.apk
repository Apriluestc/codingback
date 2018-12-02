SRC=$(wildcard ./*.c)
OBJ=$(patsubst %.c, %.o, $(SRC))
BIN=./tmp

.PHONY:$(BIN)

$(BIN):$(OBJ)
	gcc $^ -o $@

%.o:%.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
