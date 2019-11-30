/*
** EPITECH PROJECT, 2019
** add_second.c
** File description:
** other functions for second animation
*/

#include "my.h"

void drawing_square(t_square *s)
{
    if (s->beg.x == 459)
        s->beg.x = 301;
    s->beg.x += 1;
}