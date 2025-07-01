#include "new_square.h"
#include "millis.h"
#include "utils.h"
#include <ncurses.h>
#include <stdint.h>
#include <string.h>

#define KEY_SPACE 32

#define DELAY_STANDART 30

void print_rectangle(int origin_x, int origin_y, int size_x, int size_y) 
{
	for (int j = 0; j < size_y; j++){	
		move(origin_y+j, origin_x);
		for (int i = 0; i < size_x; i++){
			printw("#");
		}
	}
}
void print_boardn(bool *arr_ptr, int rows, int columns){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			(arr_ptr[i*columns+j]) ? attron(COLOR_PAIR(1)) : attroff(COLOR_PAIR(1));
			printw(" ");
		}
	//	printw("\n");

	}
}

void print_rectangle_hollow(int origin_x, int origin_y, int size_x, int size_y) 
{
	for (int j = 0; j < size_y; j++){	
		move(origin_y+j, origin_x);
		if(j == 0 || j == size_y-1){
			for (int i = 0; i < size_x; i++){
				printw("#"); 
			} 
		}
		else{
			printw("#");
			move(origin_y+j, origin_x+size_x-1);
			printw("#");	
		}
	} 
} 
int main(int argc, char *argv[]){
	//variables
	bool isPaused = false, autoRestart = false;
	int pressed_key, rows, columns, auto_delay;
	uint64_t auto_timer = millis();
	bool *arr_ptr, *help_arr_ptr;
	int delay = DELAY_STANDART;
	
	//check for flags
	for (int i = 1; i < argc; i++){
		if ((strcmp(argv[i], "-d") == 0) && (i<argc-1)){
			i++;
			if (isInt(argv[i], strlen(argv[i]))){
				delay = toInt(argv[i], strlen(argv[i]));
			}
			else{
				printf(">> -d flag is not valid\n");
				exit(0);
			}
		}
		else if((strcmp(argv[i], "-a") == 0) && (i < argc-1)){
			i++;
			if (isInt(argv[i], strlen(argv[i]))){
				autoRestart = true;
				auto_delay = toInt(argv[i], strlen(argv[i])) * 1000;
			}
			else{
				printf(">> -a flag is not valid\n");
				exit(0);
			}
			
		}
		else {
			printf(">> (%s) is unknown flag\n", argv[i]);
			exit(0);
		}
	}
	uint64_t timer = millis() - delay;

	//init ncurses
	initscr();
	nodelay(stdscr, TRUE);	
	noecho();
	curs_set(0);

	//init colors
	start_color();	
	init_pair(1, COLOR_RED, COLOR_WHITE);
	attron(COLOR_PAIR(1));

	getmaxyx(stdscr, rows, columns);
	arr_ptr = init_array(rows, columns);
	help_arr_ptr = init_array(rows, columns);
	fill_random(arr_ptr, rows, columns);
	while(1){
		pressed_key = getch();	
		if (pressed_key == KEY_SPACE){
			isPaused = !isPaused;	
		} 
		if ((autoRestart == true) && ((millis()-auto_timer) >= auto_delay)){
			fill_random(arr_ptr, rows, columns);
			auto_timer = millis();
		} 
		if (((millis()-timer) >= delay) && !isPaused){
			clear();
			timer = millis();
			render_new(arr_ptr, help_arr_ptr, rows, columns);
			print_boardn(arr_ptr, rows, columns);
			refresh();	
		}	
	}
}


