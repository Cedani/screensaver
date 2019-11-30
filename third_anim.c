/*
** EPITECH PROJECT, 2019
** third animation
** File description:
** third animation
*/

#include "my.h"


static t_circle circle[10] = {
    {{400, 300}, 20, 8, 1},
    {{400, 300}, 20, 9, 6},
    {{400, 300}, 20, 2, 6},
    {{400, 300}, 20, 3, 9},
    {{400, 300}, 20, 3, 10},
    {{400, 300}, 20, 9, 1},
    {{400, 300}, 20, 8, 7},
    {{400, 300}, 20, 4, 10},
    {{400, 300}, 20, 1, 5},
    {{400, 300}, 20, 3, 5},
};

void moving(t_circle *c) {
    c->move_x = rand() % 10;
    c->move_y = rand() % 10;
}

void actualise(t_circle *c) {
    c->center.x += c->move_x;
    c->center.y += c->move_y;
}

void directions(t_circle *c)
{
    if (c->center.x <= 21) {
        c->move_x *= -1;
        c->center.x = 21;
    }
    else if (c->center.x  >= TEST_WIDTH - 20) {
        c->move_x *= -1;
        c->center.x = TEST_WIDTH - 20 - 1;
    }
    if (c->center.y <= 21) {
        c->move_y *= -1;
        c->center.y = 21;
    }
    else if (c->center.y >= TEST_HEIGHT - 20) {
        c->move_y *= -1;
        c->center.y = TEST_HEIGHT - 20 - 1;
    }
}

void draw_third(t_framebuffer *fb)
{
    for (int i = 0; i < 10; i += 1) {
        actualise(&circle[i]);
        directions(&circle[i]);
        draw_circle(fb, &circle[i], sfRed);
    }
}