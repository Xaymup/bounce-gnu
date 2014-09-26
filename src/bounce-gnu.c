#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h> 
#define DELAY 30000


int main(int argc, char *argv[]) {
	int x = 25, y = 5;
	int w,h;
	initscr();
	noecho();
	curs_set(FALSE);
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(1,1,0);
	init_pair(2,2,0);
	init_pair(3,3,0);
	init_pair(4,4,0);
	init_pair(5,5,0);
	init_pair(6,6,0);
	init_pair(1,7,0);
    int xd = 1;
    int yd = 1;
    int color=0;
    while (1) {
		getmaxyx(stdscr, h, w);
		if (y==4) {yd = yd*-1;}
		if (y==h-4){yd = yd*-1;}
		if (x==0) {xd = xd*-1;}
		if (x==w-18){xd = xd*-1;}
		if (color==6){color = -1;}
		y=y+yd;
		x=x+xd;
		color++;
		attrset(COLOR_PAIR(color));
		draw_point(x,y);
		usleep(DELAY);
		clear();
	}
    endwin();
}


int draw_point (int x, int y) {
	mvprintw(y-4, x, "  ,           ,  ");
	mvprintw(y-3, x, " /             \\");
	mvprintw(y-2, x, "((__-^^-,-^^-__))");
	mvprintw(y-1, x, " `-_---' `---_-' ");
	mvprintw(y  , x, "  `--|o` 'o|--'  ");
	mvprintw(y+1, x, "     \\  `  /    ");
	mvprintw(y+2, x, "      ): :(      ");
	mvprintw(y+3, x, "      :o_o:      ");
	mvprintw(y+4, x, "       '-'       ");
	refresh();
}
