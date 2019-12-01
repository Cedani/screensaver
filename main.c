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
    if (my_strcmp(argv[1], "-d") == 0) {
        display_description();
        exit(0);
    }
    if (i < 1 || i > 5) {
        write(2, "wrong animation_id\n", 20);
        exit (84);
    }
    my_screensaver(i);
    return (0);
}

void display_usage(void)
{
    write(1, "animation rendering in csfml window\n", 36);
    write(1, "\nUSAGE\n", 7);
    write(1, "\t./my_screensaver\t[OPTIONS] animation_id.\n", 42);
    write(1, "\tanimation_id\tID of the animation to process.", 46);
    write(1, " between (1 and 5).\n", 20);
    write(1, "\nOPTIONS\n", 9);
    write(1, "\t-h\t\tprint the usage and quit.\n", 31);
    write(1, "\t-d\t\tprint the description of all animation and quit.", 53);
    write(1, "\nUSER INTERACTIONS\n", 19);
    write(1, "\tLEFT_ARROW\t\tswitch to the previous animation.\n", 47);
    write(1, "\tRIGHT_ARROW\t\tswitch to the next animation.\n", 44);
}

void display_description(void)
{
    write(1, "1: 8 circles on the side moving around", 37);
    write(1, "one circle in the center\n", 25);
    write(1, "2: Imitation of windows xp's loading screen\n", 44);
    write(1, "3: red circle moving randomnly\n", 31);
    write(1, "4: 9 squares placed on the center of the page", 45);
    write(1, "with randomn color\n", 19);
    write(1, "5: EPITECH logo with a circular movement\n", 41);
}
