#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "colors.h"
#include "terminal.h"
#include "timer.h"
#include "animation.h"

void get_terminal_size(int *width, int *height) {
    struct winsize w;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        *width = w.ws_col;
        *height = w.ws_row;
    } else {
        *width = 80;
        *height = 24;
    }
}

void handle_exit(int signal) {
    (void)signal;

    show_cursor();
    printf("\n");
    fflush(stdout);

    _exit(0);
}

int main(void) {
    int width;
    int height;

    float x = 10.0f;
    float y = 10.0f;

    float dx = 1.0f;
    float dy = 1.0f;

    double previous_time = clock_get_time();

    signal(SIGINT, handle_exit);

    hide_cursor();

    while (1) {
        double current_time;
        double dt;

        get_terminal_size(&width, &height);

        current_time = clock_get_time();
        dt = current_time - previous_time;
        previous_time = current_time;

        if (dt > MAX_DT)
            dt = MAX_DT;

        update(
            dt,
            &x,
            &y,
            &dx,
            &dy,
            width,
            height
        );

        clear_screen();

        move_cursor(1, 1);

        printf("Size: %dx%d\n", width, height);
        printf("Color: %s\n", color_names[i]);
        printf("FPS: %.2f\n", 1.0 / dt);

        move_cursor((int)x, (int)y);

        printf("%sSMIDR%s", colors[i], RESET);

        fflush(stdout);

        // ~20 FPS
        usleep(50000);

        // ~10 FPS
        // usleep(100000);
    }

    return 0;
}