/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** display-desu
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_charerror(char e)
{
    write (2, &e, 1);
}

int my_putstr(char *str, int opt)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    if (opt == 0)
        my_putchar('\n');
    else if (opt == 1)
        my_putchar(' ');
    return (0);
}

int my_puterror(char *str, int opt)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_charerror(str[i]);
    if (opt == 0)
        my_charerror('\n');
    else if (opt == 1)
        my_charerror(' ');
    return 0;
}

int my_put_nbr(int nb)
{
    int a;
    int b;
    _Bool over = 0;

    if (nb >= 10) {
        my_put_nbr (nb / 10);
        a = (nb % 10 + '0');
        if (over == 1 && a == '7') {
            a++;
            over = 0;
        }
        my_putchar(a);
    } else {
        b = (nb + 48);
        my_putchar(b);
    }
    return 0;
}
