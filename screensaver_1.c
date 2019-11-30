/*
** EPITECH PROJECT, 2019
** TESTsaver 1
** File description:
** first animation
*/

#include "my.h"

void my_screensaver(int index)
{
    t_ressources *re = malloc(sizeof(*re));
    sfEvent event;

    set_ressources(re);
    while (sfRenderWindow_isOpen(re->window)) {
        while (sfRenderWindow_pollEvent(re->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(re->window);
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyLeft)
                index -= 1;
            if (event.key.code == sfKeyRight)
                index += 1;
        }
        frame_clear(re->fb, sfBlack);
        manage_index(&index);
        change_animation(re->fb, index);
        refreshing(re);
    }
    destroying_ressources(re);
}

void change_animation(t_framebuffer *fb, int index)
{
    if (index == 1) {
        drawing(fb, sfRed);
    } if (index == 2) {
        print_square(fb);
    } if (index == 3) {
        draw_third(fb);
    }
}

void set_ressources(t_ressources *re)
{
    re->window = create_window(re->window, TEST_WIDTH, TEST_HEIGHT);
    re->fb = create_buffer(TEST_WIDTH, TEST_HEIGHT);
    re->texture = sfTexture_create(TEST_WIDTH, TEST_HEIGHT);
    re->sprite = sfSprite_create();
}

void refreshing(t_ressources *re)
{
    sfTexture_updateFromPixels(re->texture, re->fb->pixel, W, H, 0, 0);
    sfSprite_setTexture(re->sprite, re->texture, sfFalse);
    sfRenderWindow_drawSprite(re->window, re->sprite, NULL);
    sfRenderWindow_display(re->window);
    sfRenderWindow_clear(re->window, sfBlack);
}

void manage_index(int *index)
{
    if (*index > NB_ANIM)
        *index = 1;
    if (*index < 1)
        *index = NB_ANIM;
}