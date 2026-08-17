#ifndef ANIMATION_H
#define ANIMATION_H

#define COLOR_COUNT 12
#define MAX_DT 0.1

extern int i;
extern const char *colors[COLOR_COUNT];
extern const char *color_names[COLOR_COUNT];

void next_color(void);
void update(
    double dt,
    float *x,
    float *y,
    float *dx,
    float *dy,
    int width,
    int height
);

#endif