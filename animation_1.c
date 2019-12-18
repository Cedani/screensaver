/*
** EPITECH PROJECT, 2019
** animation1
** File description:
** first animation
*/

#include "my.h"

static t_circle circle[9] = {
    {{20, 20}, 20, 0, 0},
    {{20, 300}, 20, 0, 0},
    {{20, 580}, 20, 0, 0},
    {{400, 20}, 20, 0, 0},
    {{400, 300}, 20, 0, 0},
    {{400, 580}, 20, 0, 0},
    {{780, 20}, 20, 0, 0},
    {{780, 300}, 20, 0, 0},
    {{780, 580}, 20, 0, 0}
};

void drawing(t_framebuffer *fb, sfColor color)
{
    sfVector2i point = {400, 300};
    for (int i = 0; i < 9; i += 1) {
        draw_depl(fb, &circle[i]);
        draw_circle(fb, &circle[i], color);
        sfVector2i cen = {round(circle[i].center.x), round(circle[i].center.y)};
        draw_line(fb, cen, point, color);
    }
}

void draw_depl(t_framebuffer *fb, t_circle *t)
{
    if (t->center.x > 0 + t->radius && t->center.y == 0 + t->radius) {
        t->move_x = -0.5;
        t->move_y = 0;
    }
    if (t->center.x == 0 + t->radius && t->center.y < TEST_HEIGHT - t->radius) {
        t->move_x = 0;
        t->move_y = 0.5;
    }
    if (t->center.x < TEST_WIDTH - t->radius
        && t->center.y == TEST_HEIGHT - t->radius) {
        t->move_x = 0.5;
        t->move_y = 0;
    }
    if (t->center.x == TEST_WIDTH - t->radius && t->center.y > 0 + t->radius) {
        t->move_x = 0;
        t->move_y = -0.5;
    }
    t->center.x += t->move_x;
    t->center.y += t->move_y;
}