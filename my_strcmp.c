/*
** EPITECH PROJECT, 2019
** CPool_Day06
** File description:
** my_strcmp.c
*/

int my_len(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_len(s1);
    int j = my_len(s2);
    int l = 0;
    int ret = i - j;
    if (ret < 0) {
        ret = i;
    } else {
        ret = j;
    }
    while (l <= ret) {
        if (s1[l] != s2[l]) {
            ret = s1[l] - s2[l];
            return ret;
        } else {
            l++;
        }
    }
    return 0;
}

int my_len(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
