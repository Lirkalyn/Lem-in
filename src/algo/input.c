/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** take the input ant put it in a useable form-desu
*/

#include "../../include/struct.h"
#include "../../include/my.h"

input_t *input_rewinder(input_t *info)
{
    while (info->preview != NULL)
        info = info->preview;
    return info;
}

input_t *input_mallocer(void)
{
    input_t *info = malloc(sizeof(input_t));

    info->line = NULL;
    info->len = 0;
    info->next = NULL;
    info->preview = NULL;
    return info;
}

input_t *input_filler(input_t *info, char *buf, ssize_t read)
{
    void *tmp;

    info->line = buf;
    info->len = read;
    tmp = info;
    info->next = input_mallocer();
    if (info->next == NULL)
        return NULL;
    info = info->next;
    info->preview = tmp;
    return info;
}

int input_checker(char *buf)
{
    int i = 0;
    int gd_line = 0;

    if (buf == NULL || buf[0] == '\0' || buf[0] == '\n')
        return 2;
    for (gd_line = 0; buf[i] != '\n' && buf[i] != '#' && gd_line == 0; i++)
        if ((buf[i] >= '0' && buf[i] <= '9')
            || (buf[i] >= 'a' && buf[i] <= 'z')
            || (buf[i] >= 'A' && buf[i] <= 'Z')
            || buf[i] == '-')
            gd_line = 1;
    for (i = 0; buf[i] != '\n' && buf[i] != '\0'; i++);
    if (i >= 2 && buf[0] == '#' && buf[1] == '#')
        return 0;
    if (i >= 1 && buf[0] == '#' && buf[1] != '#')
        return 1;
    if (gd_line == 1)
        return 0;
    else
        return 1;
}

input_t *input_taker(void)
{
    input_t *info = input_mallocer();
    char *buf = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int check_line = 0;

    if (info == NULL)
        return NULL;
    while (1) {
        read = getline(&buf, &len, stdin);
        check_line = input_checker(rm_begining_space(buf, read));
        if (read == -1 || check_line == 2)
            return input_rewinder(info);
        else if (check_line == 0) {
            info = input_filler(info, rm_begining_space(buf, read), read);
            buf = NULL;
        }
    }
}