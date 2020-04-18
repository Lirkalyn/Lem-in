/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** for the ant-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int is_comment(char *line)
{
    int i = 0;
    int space = 0;
    int space_ok = 0;

    for (; line[i] != '\0' && line[i] != '\n'; i++) {
        if (line[i] == ' ')
            space = 1;
        else if (space == 1 && line[i] == '#')
            space_ok = 1;
        if (((line[i] < '0' || line[i] > '9') && line[i] != '#')
            && (space == 0))
            return 0;
    }
    if (space_ok == 1)
        return 1;
    else if (space == 1)
        return 0;
    else
        return 1;
    return 1;
}

int space_error(char *line)
{
    int i = 0;
    int space = 0;
    int ok = 0;

    for (; line[i] != '\0' && line[i] != '\n' && line[i] != '#'; i++);
    if (line[i] == '#')
        for (i--; i >= 0;) {
            if (line[i] == ' ' && ok == 0)
                i--;
            else if (line[i] >= '0' && line[i] <= '9') {
                ok = 1;
                i--;
            }
            if (line[i] == ' ' && ok == 1)
                return 0;
        }
    return 1;
}

int ant_nb_finder(char *line, int *nb)
{
    int i = 0;
    int ok = is_comment(line);
    int ok_2 = space_error(line);
    int space = 0;

    if (ok == 0 || ok_2 == 0)
        return -84;
    for (; line[i] != '\0' && line[i] != '\n' && line[i] != ' '
            && line[i] != '#'; i++) {
            *nb *= 10;
            *nb += (line[i] - '0');
        }
    return 1;
}

ant_t *ant_initializer_2(ant_t *ant, int nb)
{
    for (int i = 0; i < nb; i++) {
        ant[i].id = i;
        ant[i].nb = nb;
        ant[i].pos_name = NULL;
        ant[i].pos_id = 0;
    }
    return ant;
}

ant_t *ant_initializer(ant_t *ant, input_t *info)
{
    int bool_ant_nb = 0;
    int nb_tmp = 0;

    while (info->next != NULL && bool_ant_nb == 0)
    {
        if (bool_ant_nb == 0) {
            bool_ant_nb = ant_nb_finder(info->line, &nb_tmp);
            info = info->next;
        }
    }
    printf("ant = %d\n", nb_tmp);
        ant = (bool_ant_nb == -84) ? NULL : malloc(nb_tmp * sizeof(ant_t));
        if (ant == NULL)
            return NULL;
        ant = ant_initializer_2(ant, nb_tmp);
    return ant;
}