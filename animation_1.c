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

void draw_depl(t_framebuffer *fb, t_circle *test)
{
    if (test->center.x > 0 + test->radius
        && test->center.y == 0 + test->radius) {
        test->move_x = -0.5;
        test->move_y = 0;
    }
    if (test->center.x == 0 + test->radius
        && test->center.y < TEST_HEIGHT - test->radius) {
        test->move_x = 0;
        test->move_y = 0.5;
    }
    if (test->center.x < TEST_WIDTH - test->radius
        && test->center.y == TEST_HEIGHT - test->radius) {
        test->move_x = 0.5;
        test->move_y = 0;
    }
    if (test->center.x == TEST_WIDTH - test->radius
        && test->center.y > 0 + test->radius) {
        test->move_x = 0;
        test->move_y = -0.5;
    }
    test->center.x += test->move_x;
    test->center.y += test->move_y;
}

sfColor giving_color(sfColor color)
{
    sfEvent event;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyR)
            return (sfRed);
        if (event.key.code == sfKeyB)
            return (sfBlue);
        if (event.key.code == sfKeyG)
            return (sfGreen);
        if (event.key.code == sfKeyR)
            return (sfRed);
        if (event.key.code == sfKeyJ)
            return (sfYellow);
    }
    return (color);
}

