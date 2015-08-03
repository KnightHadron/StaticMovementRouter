// cli-main.c
// SMR main file for the cli interface

#include <ncurses.h>
#include <unistd.h>

int scr_max_y, scr_max_x;

enum menu_mode {ABOUT, EDIT, NAV, VIEW, QUIT};
enum menu_mode main_menu_choice;

int str_len(char *str){
	int i;
	for(i=0; str[i]!='\0'; ++i);
	return i;
}

int init_ncurses(){
	initscr();
	noecho();
	curs_set(FALSE);
	cbreak();
	
	getmaxyx(stdscr, scr_max_y, scr_max_x);
	
	return 0;
}

void print_center(char *str, int y){
	mvprintw(y, (scr_max_x/2) - (str_len(str)/2), str);
	refresh();
}

void finish_ncurses(){
	endwin();
}

void intro_screen(){
	print_center("Welcome to Static Movement Router", 5);
	
	print_center("Press any key to continue...", scr_max_y/2 + 5);
	
	getch();
}

// 1 if done, 0 if failed
int main_screen(){
	print_center("Welcome to Static Movement Router", 1);
	
	print_center("Please select one of the following:", 4);
	print_center("a) About this program", 5);
	print_center("b) Edit an existing map or create a new one", 6);
	print_center("c) Navigate an existing map", 7);
	print_center("d) View an existing map", 8);
	print_center("e) Exit", 9);
	
	char selection = getch();
	
	switch (selection) {
		case 'a' : main_menu_choice = ABOUT; break;
		case 'b' : main_menu_choice = EDIT; break;
		case 'c' : main_menu_choice = NAV; break;
		case 'd' : main_menu_choice = VIEW; break;
		case 'e' : main_menu_choice = QUIT; break;
		default: return 0;
	}
	
	return 1;
}

void run_about() {
	
}

void run_edit() {
	
}

void run_nav() {
	
}

void run_view() {
	
}
				
int verify_quit() {
	return 1;
}

int main(int argc, char **argv)
{
	init_ncurses();
	
	intro_screen();
	clear();
	
	int exit = 0;
	do {
		if (main_screen()) {
			clear();
			refresh();
			
			switch (main_menu_choice) {
				case ABOUT: run_about(); break;
				case EDIT: run_edit(); break;
				case NAV: run_nav(); break;
				case VIEW: run_view(); break;
				case QUIT:  {
								if (verify_quit()){
									exit = 1;
								}
								break;
							}
				default: exit = 1; // this should never happen
			}
			
			clear();
			
		} else {
			print_center("Sorry, you picked an invalid letter.", scr_max_y - 2);
		}
	} while (exit != 1);
	
	sleep(1); // why is this here
	
	finish_ncurses();
	return 0;
}
