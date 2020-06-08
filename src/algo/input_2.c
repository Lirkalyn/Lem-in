/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** take the input ant put it in a useable form again-desu
*/

#include "../../include/struct.h"
#include "../../include/my.h"

char *rm_begining_space(char *buf, int read)
{
    int i = 0;

    if (read == -1 || buf == NULL || buf[0] == '\0' || buf[0] == '\n')
        return NULL;
    for (; buf[i] != '\n' && buf[i] != '\0' && buf[i] == ' '; i++);
    if (i > 0 && buf[(i - 1)] == ' ')
        buf += i;
    return buf;
}