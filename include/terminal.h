#ifndef TERMINAL_H
#define TERMINAL_H

#define ESC_BEGIN "\033["
#define ESC_END   "m"
#define CSI       "\033["
#define CST_END   "m"

#define CLEAR     "2J"
#define CURSOR_HOME "H"

void clear_screen(void);
void hide_cursor(void);
void show_cursor(void);
void move_cursor(int x, int y);

#endif