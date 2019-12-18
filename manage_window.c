/*
** EPITECH PROJECT, 2019
** manage_window.c
** File description:
** creating and managing ressources
*/

#include "my.h"

sfRenderWindow *create_window(sfRenderWindow *window, int width, int height)
{
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "Screensaver", sfDefaultStyle, NULL);
    if (window == NULL) {
        write(2, "window not initialized", 23);
        return (84);
    }
    return (window);
}

t_framebuffer *create_buffer(int width, int height)
{
    t_framebuffer *fb;
    fb = malloc(sizeof(*fb));

    fb->width = width;
    fb->height = height;
    fb->pixel = malloc((width*height*32) / 8);
    if (fb == NULL) {
        write(2, "frame not initialized", 22);
        return (84);
    }
    return (fb);
}

void frame_clear(t_framebuffer *fb, sfColor color)
{
    color.a = 2;
    color.r = 100;
    color.b = 100;
    color.g = 100;
    for (int y = 0; y < fb->height; y += 1)
        for (int x = 0; x < fb->width; x += 1)
            draw_pixel(fb, x, y, color);
}

void framebuffer_destroy(t_framebuffer *fb)
{
    free(fb->pixel);
    free(fb);
}

void destroying_ressources(t_ressources *ressources)
{
    sfSprite_destroy(ressources->sprite);
    sfTexture_destroy(ressources->texture);
    framebuffer_destroy(ressources->fb);
    sfRenderWindow_destroy(ressources->window);
    free(ressources);
}