CC = gcc
files = main.c utils.c new_square.c millis.c 
flags = -Wall -extra
target = life
$(target): main.c
	$(CC) $(files) $(flags) -lncurses -o $(target)  
