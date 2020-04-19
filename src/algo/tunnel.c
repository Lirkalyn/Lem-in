/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** all the functions for tunnel-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int go_too_far(char *line)
{
    int len = 0;
    int separator = 0;

    for (; line[len] != '\0' && line[len] != '\n'; len++)
        if (len != 0 && line[len] == '-' && line[(len - 1)] != ' '
            && line[(len + 1)] != ' ')
            separator++;
    if (separator > 0)
        return 1;
    return 0;
}

int is_separator(char *line)
{
    int j = 0;
    int len = 0;
    int space = 0;
    int space_ok = 0;

    for (; line[len] != '\0' && line[len] != '\n'; len++) {
        if (line[0] == '#')
            return -2;
        else if (line[len] == ' ')
            space = 1;
        if (space == 1 && line[len] == '#')
            space_ok = 1;
    }
    if (space == 1 && space_ok == 0)
        return -3;
    for (; line[j] != '\0' && line[j] != '\n' && line[j] != '-'; j++);
    if (j == len)
        return -1; // useless?
    else
        return 0;
}

int too_much_sep(char *line)
{
    int i = 0;
    int sep = 0;

    for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '#'
                && line[i] != ' '; i++)
        if (line[i] == '-')
            sep++;
    if (sep != 1)
        return 1;
    else
        return 0;
}

int tunnel_nb_finder(input_t *info, int *nb_tmp)
{
    int nb = 0;
    int check = 0;
    char *line = info->line;

    while (info->next != NULL && line[0] != '\n' && line[0] != '\0') {
        line = info->line;
        check = is_separator(line);
        check += (check == 0) ? too_much_sep(line) : 0;
        if (check != 0)
            info = info->next;
        for (int i = 0; line[i] != '\0' && line[i] != '\n' && check == 0; i++)
            if (line[i] == '-' && i != 0 && line[(i + 1)] != '\0'
                && line[(i + 1)] != '\n')
                nb++;
//        printf("tunnel = %d et %d = %s", nb, check, line);
        if (nb == 1 && check == 0)
            *nb_tmp += 1;
        if (check == 0)
            info = info->next;
        nb = 0;
    }
}