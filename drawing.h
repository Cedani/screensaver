/*
** EPITECH PROJECT, 2019
** drawing.h
** File description:
** prototype of drawing function
*/

#ifndef DRAWING
#define DRAWING
#include "my.h"

typedef struct s_circle {
    sfVector2f center;
    int radius;
    float move_x;
    float move_y;
} t_circle;

typedef struct s_framebuffer {
    sfUint8 *pixel;
    int width;
    int height;
} t_framebuffer;

typedef struct s_ressources {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    t_framebuffer *fb;
} t_ressources;

sfRenderWindow *create_window(sfRenderWindow *window, int width, int height);
t_framebuffer *create_buffer(int width, int height);
void frame_clear(t_framebuffer *fb, sfColor color);
void framebuffer_destroy(t_framebuffer *fb);
void set_ressources(t_ressources *re);
void draw_pixel(t_framebuffer *fb, int x, int y, sfColor color);
void draw_line_hor_opt(t_framebuffer *fb, int x, sfVector2i fin, sfColor color);
void draw_line_ver_opt(t_framebuffer *, sfVector2i, int, sfColor);
void draw_line(t_framebuffer *, sfVector2i, sfVector2i, sfColor);
void draw_circle(t_framebuffer *fb, t_circle *circle, sfColor color);
void my_screensaver(int index);
void drawing(t_framebuffer *fb, sfColor color);
void direction(t_framebuffer *fb);
void draw_depl(t_framebuffer *fb, t_circle *test);
void destroying_ressources(t_ressources *ressources);
void change_animation(t_framebuffer *fb, int index);
int attrib_sign(char const *str, int i);
int attrib_num(char const *str, int i);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
void display_usage(void);
#endif /* !DRAWING */
