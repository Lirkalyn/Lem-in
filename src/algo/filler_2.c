/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** more of the same-desu ///should be call room.c
*/

#include "../../include/my.h"
#include "../../include/algo.h"

static int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return ((s1[i] - s2[i]));
    return (0);
}

int is_space(char *line)
{
    int j = 0;
    int len = 0;

    for (; line[len] != '\0' && line[len] != '\n'; len++)
        if (line[0] == '#')
            return -2;
    for (; line[j] != '\0' && line[j] != '\n' && line[j] != ' '; j++);
    if (j == len)
        return -1;
    else
        return 0;
}

int rooms_nb_finder_2(char *line)
{
    int i = 0;
    int pos = 0;
    int check = 0;

    if (my_strcmp(line, "##start") == 0 || my_strcmp(line, "##end") == 0)
        return 0;
    check = is_space(line);
    if (check != 0)
        return check;
    for (; line[i] != '\0' && line[i] != '\n' && line[i] != ' '; i++);
    i += (line[i] == ' ') ? 1 : 0;
    for (; line[i] != '\0' && line[i] != '\n'; i++) {
        pos += (line[i] == ' ') ? 1 : 0;
        if (line[i] == '#' && pos >= 1)
            return 1;
        else if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
            return (go_too_far(line) == 1) ? -1 : -84;
    }
    return (pos != 1) ? -84: 1;
}

int rooms_nb_finder(input_t *info, int *nb_tmp)
{
    int forward = 0;
    int nb_tmp_2 = 0;
    int bool_rooms_done = 0;

    while (info->next != NULL && bool_rooms_done == 0) {
        nb_tmp_2 = rooms_nb_finder_2(info->line);
        printf("rooms = %d = %s", nb_tmp_2, info->line);
        *nb_tmp += (nb_tmp_2 == 1) ? 1 : 0;
        bool_rooms_done = (nb_tmp_2 == -1) ? 1 : bool_rooms_done;
        if (nb_tmp_2 == -2) {
            info = info->next;
            forward++;
        }
        else if (nb_tmp_2 == -84)
            return -84;
        else {
            info = info->next;
            forward++;
        }
    }
    return forward;
}

int rooms_placer(char *oldline, char *line, int *nb)
{
    char *name = NULL;
    int i = 0;
    int len = 0;
    int coord[4] = {[0 ... 3] = 0};
    int pos = 0;

//
    for (; line[len] != '\0' && line[len] != '\n' && line[len] != ' '; len++);
    name = malloc((len + 1) * sizeof(char));
    if (name == NULL)
        return -84;
    name[len] = '\0';
    i += (line[i] == ' ') ? 1 : 0;
    for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != ' '; i++)
        name[i] = line[i];
//
    while (line[i] != '\0' && line[i] != '\n') {
        for (; line[i] != '\0' && line[i] != '\n' && line[i] != ' '; i++)
            if (line[i] < '0' || line[i] > '9')
                return -84;
            else {
                coord[pos] *= 10;
                coord[pos] += (line[i] - '0');
            }
        pos += 1;
    }
    return 1;
}