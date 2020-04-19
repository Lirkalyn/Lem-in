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

input_t *input_taker(void)
{
    input_t *info = input_mallocer();
    char *buf = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int pos = 0;

    if (info == NULL)
        return NULL;
    while (1) {
        read = getline(&buf, &len, stdin);
        if (read == -1)
            return input_rewinder(info);
        else {
            pos += 1;
            info = input_filler(info, buf, read);
            buf = NULL;
        }
    }
}