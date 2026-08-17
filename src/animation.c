#include "animation.h"
#include "colors.h"

int i;

const char *colors[COLOR_COUNT] = {
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    PINK,
    ORANGE,
    PURPLE,
    LIME,
    GOLD,
    SILVER
};

const char *color_names[COLOR_COUNT] = {
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "MAGENTA",
    "CYAN",
    "PINK",
    "ORANGE",
    "PURPLE",
    "LIME",
    "GOLD",
    "SILVER"
};

void next_color(void) {
  if (i + 1 >= COLOR_COUNT)
    i = 0;
  else
    i++;
}

void update(double dt, float *x, float *y, float *dx, float *dy, int width,
            int height) {
  float speed = 20.0f;

  *x += (*dx) * speed * dt;
  *y += (*dy) * speed * dt;

  if (*x >= width - 5 || *x <= 1.0f) {
    *dx = -(*dx);

    if (*x <= 1.0f)
      *x = 1.0f;

    if (*x >= width - 5)
      *x = width - 5;

    next_color();
  }

  if (*y >= height || *y <= 1.0f) {
    *dy = -(*dy);

    if (*y <= 1.0f)
      *y = 1.0f;

    if (*y >= height)
      *y = height;

    next_color();
  }
}