all:mutex

create:create.c
	gcc -g $^ -o $@ -pthread

mutex:mutex.c
	gcc -g $^ -o $@ -pthread

.PHONY:clean
clean:
	rm -f create mutex
