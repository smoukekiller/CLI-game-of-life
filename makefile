CC = gcc
files = main.c utils.c new_square.c millis.c 
flags = -Wall -extra
target = ##flags 
-a <seconds> - automatically restarts the simulatio in given number of seconds
-d <milliseconds> - controlls the time between generation, can be used to control simulation speed	
$(target): main.c
	$(CC) $(files) $(flags) -lncurses -o $(target)  
