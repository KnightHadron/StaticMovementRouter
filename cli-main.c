// cli-main.c
// SMR main file for the cli interface

#include <ncurses.h>
#include <unistd.h>

int scr_max_y, scr_max_x;

int str_len(char *str){
	int i;
	for(i=0; str[i]!='\0'; ++i);
	return i;
}

int init_ncurses(){
	initscr();
	noecho();
	curs_set(FALSE);
	
	getmaxyx(stdscr, scr_max_y, scr_max_x);
	
	return 0;
}

void print_center(char *str, int y){
	mvprintw(y, (scr_max_x/2) - (str_len(str)/2), str);
	refresh();
}

int main(int argc, char **argv)
{
	init_ncurses();
	
	print_center("Welcome to Static Movement Router", 5);
	
	sleep(1);
	
	endwin();
	
	return 0;
}
