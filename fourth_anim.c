/*
** EPITECH PROJECT, 2019
** fourh_anim.c
** File description:
** fourth animation
*/

#include "my.h"

static t_square square[10] = {
    {{350, 250}, 50, {255, 0, 0, 255}},
    {{350, 300}, 50, {89, 87, 98, 255}},
    {{350, 350}, 50, {0, 255, 0, 255}},
    {{400, 250}, 50, {0, 0, 255, 255}},
    {{400, 300}, 50, {235, 189, 40, 255}},
    {{400, 350}, 50, {87, 65, 23, 255}},
    {{450, 250}, 50, {90, 65, 98, 255}},
    {{450, 300}, 50, {234, 156, 34, 255}},
    {{450, 350}, 50, {56, 76, 245, 255}}
};

static sfColor four = {89, 87, 98, 255};
static sfColor five = {235, 189, 40, 255};
static sfColor six = {87, 65, 23, 255};
static sfColor seven = {90, 65, 98, 255};
static sfColor eight = {234, 156, 34, 255};
static sfColor nine = {56, 76, 245, 255};

void draw_fourth(t_framebuffer *fb, sfRenderWindow *window)
{
    sfRenderWindow_setFramerateLimit(window, 50);
    for (int i = 0; i < 10; i += 1) {
        changing_color(&square[i]);
        draw_square(fb, square[i].beg, square[i].dim, square[i].color);
    }
    sfRenderWindow_setFramerateLimit(window, 100);
}

void changing_color(t_square *s)
{
    int i = rand() % 8;
    if (i == 0)
        s->color = sfRed;
    if (i == 1)
        s->color = sfGreen;
    if (i == 2)
        s->color = sfBlue;
    if (i == 3)
        s->color = four;
    if (i == 4)
        s->color = five;
    if (i == 5)
        s->color = six;
    if (i == 6)
        s->color = seven;
    if (i == 7)
        s->color = eight;
    if (i == 8)
        s->color = nine;
}