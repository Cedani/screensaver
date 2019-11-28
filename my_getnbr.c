/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get number in string
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int ret = 0;
    int sign = 0;
    int signal = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' && signal == 0) {
            ret = attrib_num(str, i);
            sign = attrib_sign(str, i);
            signal = 1;
        }
        i++;
    }
    if (sign == 1) {
        return -ret;
    } else {
        return ret;
    }
}

int attrib_sign(char const *str, int i)
{
    int plus = 0;
    int minus = 0;
    int k = i - 1;
    while (k >= 0) {
        if (str[k] == '-') {
            minus++;
        } else {
            plus++;
        }
        k--;
    }
    if (minus % 2 != 0) {
        return (1);
    } else {
        return (0);
    }
}

int attrib_num(char const *str, int i)
{
    int k = i;
    int coeff = 1;
    int ret = 0;

    while (str[k] >= '0' && str[k] <= '9') {
        k++;
        coeff *= 10;
    }
    coeff /= 10;
    k = i;

    while (str[k] >= '0' && str[k] <= '9') {
        ret += (str[k] - 48) * coeff;
        coeff /= 10;
        k++;
    }
    return (ret);
}