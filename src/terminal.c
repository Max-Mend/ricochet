#include "terminal.h"

#include <stdio.h>

void clear_screen(void) {
    printf("\033[2J\033[H");
}

void hide_cursor(void) {
    printf("\033[?25l");
}

void show_cursor(void) {
    printf("\033[?25h");
}

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
