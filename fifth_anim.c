/*
** EPITECH PROJECT, 2019
** fifth_anim
** File description:
** fifth animation
*/

#include "my.h"

static int dist = 1;

float angle = 0;

static t_rectangle E[4] = {
    {{100, 150}, 20, 100},
    {{120, 150}, 30, 20},
    {{120, 190}, 30, 20},
    {{120, 230}, 30, 20},
};

static t_square point = {{200, 165}, 20};

static t_rectangle P[2] = {
    {{170, 150}, 20, 100},
    {{190, 150}, 50, 50},
};

static t_rectangle I[3] = {
    {{260, 150}, 50, 20},
    {{275, 170}, 20, 60},
    {{260, 230}, 50, 20},
};

static t_rectangle T[2] = {
    {{330, 150}, 50, 20},
    {{345, 170}, 20, 80},
};

static t_rectangle SE[4] = {
    {{400, 150}, 20, 100},
    {{410, 150}, 30, 20},
    {{410, 190}, 30, 20},
    {{410, 230}, 30, 20},
};

static t_rectangle C[3] = {
    {{470, 150}, 20, 100},
    {{490, 150}, 30, 20},
    {{490, 230}, 30, 20},
};

static t_rectangle HH[3] = {
    {{540, 150}, 20, 100},
    {{560, 190}, 30, 20},
    {{590, 150}, 20, 100},
};

void drawing_rectangle(t_framebuffer *fb, t_rectangle *r)
{
    for (int y = r->beg.y; y < r->beg.y + r->height; y += 1) {
        for (int x = r->beg.x; x < r->beg.x + r->width; x += 1) {
            draw_pixel(fb, x, y, sfBlue);
        }
    }
}

void orbit(t_rectangle *r) {
    r->beg.x = r->beg.x + cosf(angle) * dist;
    r->beg.y = r->beg.y + sinf(angle) * dist;
}

void draw_orbit(void)
{
    for (int i = 0; i < 4; i += 1) {
        orbit(&E[i]);
        orbit(&SE[i]);
    }
    for (int i = 0; i < 2; i += 1) {
        orbit(&P[i]);
        orbit(&T[i]);
    }
    for (int i = 0; i < 3; i  += 1) {
        orbit(&I[i]);
        orbit(&C[i]);
        orbit(&HH[i]);
    }
    point.beg.x = point.beg.x + cosf(angle) * dist;
    point.beg.y = point.beg.y + sinf(angle) * dist;
}

void draw_fifth(t_framebuffer *fb)
{
    for (int i = 0; i < 4; i += 1) {
        drawing_rectangle(fb, &E[i]);
        drawing_rectangle(fb, &SE[i]);
    }
    for (int i = 0; i < 2; i += 1) {
        drawing_rectangle(fb, &P[i]);
        drawing_rectangle(fb, &T[i]);
        draw_square(fb, point.beg, point.dim, sfBlack);
    }
    for (int i = 0; i < 3; i  += 1) {
        drawing_rectangle(fb, &I[i]);
        drawing_rectangle(fb, &C[i]);
        drawing_rectangle(fb, &HH[i]);
    }
    draw_orbit();
    angle += 0.01F;
}