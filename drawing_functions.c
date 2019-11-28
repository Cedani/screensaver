/*
** EPITECH PROJECT, 2019
** drawing_functions.c
** File description:
** implementation of drawing functions
*/

#include "my.h"

void draw_pixel(t_framebuffer *fb, int x, int y, sfColor color)
{
    if (fb == NULL) {
        write(2, "frame is null", 14);
        exit (84);
    }
    if (fb ->pixel == NULL) {
        write(2, "pixel's array is null", 22);
        exit (84);
    }
    fb->pixel[(x*4) + (y * fb->width * 4)] = color.r;
    fb->pixel[(x*4) + (y * fb->width * 4) + 1] = color.g;
    fb->pixel[(x*4) + (y * fb->width * 4) + 2] = color.b;
    fb->pixel[(x*4) + (y * fb->width * 4) + 3] = color.a;
}

void draw_line_hor_opt(t_framebuffer *fb, int x, sfVector2i fin, sfColor color)
{
    int av = 0;
    if (fb == NULL) {
        write(2, "frame is null", 14);
        exit (84);
    }
    if (x > fin.x)
        av = -1;
    else
        av = 1;
    for (int i = x; i != fin.x ; i += av)
        draw_pixel(fb, i, fin.y, color);
}

void draw_line_ver_opt(t_framebuffer *fb, sfVector2i sta, int y2, sfColor color)
{
    int av = 0;
    if (fb == NULL) {
        write(2, "frame is null", 14);
        exit (84);
    }
    if (sta.y > y2)
        av = -1;
    else
        av = 1;
    for (int i = sta.y; i != y2 ; i += av)
        draw_pixel(fb, sta.x, i, color);
}

void draw_line(t_framebuffer *fb, sfVector2i p_a, sfVector2i p_b, sfColor color)
{
    if (p_a.x != p_b.x && p_a.y == p_b.y)
        draw_line_hor_opt(fb, p_a.x, p_b, color);
    if (p_a.x == p_b.x && p_a.y != p_b.y)
        draw_line_ver_opt(fb, p_a, p_b.y, color);
    if (p_a.x == p_b.x && p_a.y == p_b.y)
        draw_pixel(fb, p_a.x, p_b.x, color);
    if (p_a.x != p_b.x && p_a.y != p_b.y) {
        float a = (float)(p_a.y - p_b.y) / (p_a.x - p_b.x);
        float b = p_a.y - a * p_a.x;
        int av = 0;
        float j = 0;
        if (p_a.x > p_b.x)
            av = -1;
        else
            av = 1;
        for (int i = p_a.x; i != p_b.x; i += av) {
            j = a * i + b;
            draw_pixel(fb, i, round(j), color);
        }
    }
}

void draw_circle(t_framebuffer *fb, t_circle *circle, sfColor color)
{
    if (circle == NULL) {
        write(2, "circle is null", 15);
        exit (84);
    }
    sfVector2i fin;
    int k = 0;

    fin.x = circle->center.x + circle->radius;
    fin.y = circle->center.y + circle->radius;

    for (int y = circle->center.y - circle->radius; y < fin.y; y += 1) {
        for (int x = circle->center.x - circle->radius; x < fin.x; x += 1) {
            k = (pow(x - circle->center.x, 2) + pow(y - circle->center.y, 2));
            if (k <= pow(circle->radius, 2))
                draw_pixel(fb, round(x), round(y), color);
        }
    }
}