/*
** EPITECH PROJECT, 2019
** second_anim.c
** File description:
** second animation
*/

#include "my.h"

static t_square s[4] = {
    {{ORBIT_WIDTH - 100, ORBIT_HEIGHT - 100}, 100, {255, 0, 0, 255}, 10},
    {{ORBIT_WIDTH - 100, ORBIT_HEIGHT}, 100, {0, 0, 255, 255}, 10},
    {{ORBIT_WIDTH, ORBIT_HEIGHT - 100}, 100, {0, 255, 0, 255}, 10},
    {{ORBIT_WIDTH, ORBIT_HEIGHT}, 100, {255, 255, 0, 255}, 10}
};

static t_rectangle r = {{300, 500}, 200, 50};

static t_square sq[3] = {
    {{301, 505}, 40, {0, 0, 255, 255}},
    {{345, 505}, 40, {0, 0, 255, 255}}
};

static float angle = 0;

static sfColor testc = {255, 255, 255, 255};

static int dist = 1;

static int index = 0;

void drawing_orbit(t_square *test)
{
    test->beg.x = test->beg.x + cosf(angle) * dist;
    test->beg.y = test->beg.y + sinf(angle) * dist;
}

void draw_square(t_framebuffer *fb, sfVector2f point, int dim, sfColor color)
{
    for (float i = point.y;  i < point.y + dim; i += 1)
        for (float j = point.x; j < point.x + dim; j += 1)
            draw_pixel(fb, round(j), round(i), color);
}

void print_square(t_framebuffer *fb)
{
    draw_rect(fb);
    for (int i = 0; i < 4; i += 1) {
        drawing_orbit(&s[i]);
        if (index > 3)
            index = 0;
        if (i == index) {
            change_square_size(&s[i]);
        }
        draw_square(fb, s[i].beg, s[i].dim, s[i].color);
        angle += 0.01f;
    }
    drawing_square(&sq[0]);
    drawing_square(&sq[1]);
    draw_square(fb, sq[0].beg, sq[0].dim, sfBlue);
    draw_square(fb, sq[1].beg, sq[1].dim, sfBlue);
    index += 1;
}

void change_square_size(t_square *s)
{
    if (s->dim == 10 || s->dim == 100) {
        s->scaling *= -1;
    }
    s->dim += s->scaling;
}

void draw_rect(t_framebuffer *fb)
{
    for (int y = r.beg.y; y < r.beg.y + r.height; y += 1) {
        for (int x = r.beg.x; x < r.beg.x + r.width; x += 1) {
            if (y == r.beg.y)
                draw_pixel(fb, x, y, testc);
            if (y == r.beg.y + r.height - 1)
                draw_pixel(fb, x, y, testc);
            if (x == r.beg.x)
                draw_pixel(fb, x, y, testc);
            if (x == r.beg.x + r.width - 1)
                draw_pixel(fb, x, y, testc);
        }
    }
}