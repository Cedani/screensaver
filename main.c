/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** center of operation
*/

#include "my.h"

int main(int argc, char **argv)
{
    int i;
    if (argc != 2) {
        write(2, "wrong number of argument\n", 26);
        exit (84);
    }
    i = my_getnbr(argv[1]);
    if (my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        exit(0);
    }
    if (i != 1) {
        write(2, "wrong animation_id\n", 20);
        exit (84);
    }
    my_screensaver(i);
    return (0);
}

void display_usage(void)
{
    write(1, "animation rendering in csfml window\n", 37);
    write(1, "\n", 2);
    write(1, "USAGE\n", 7);
    write(1, "\t./my_screensaver\t[OPTIONS] animation_id\n", 42);
    write(1, "\tanimation_id\tID of the animation to process (only 1)\n", 63);
    write(1, "\nOPTIONS\n", 10);
    write(1, "\t-h\t\tprint the usage and quit\n", 31);
}