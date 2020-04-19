/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** more... just more-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int lenght_finder(char *line, int opt)
{
    int i = 0;
    int j = 0;

    if (opt == 0) {
        for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '-'; i++);
        return i;
    }
    else if (opt == 1) {
        for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '-'; i++);
        for (j = (i + 1); line[j] != '\0' && line[j] != '\n' && line[j] != '#'
                    && line[j] != ' '; j++);
        return (j - (i + 1));
    }
}

char *name_putter(char *line, int len, int opt)
{
    int i = 0;
    int j = 0;
    char *name = malloc((len + 1) * sizeof(char));

    if (name == NULL)
        return NULL;
    name[len] = '\0';
    if (opt == 0) {
        for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '-'; i++)
        name[i] = line[i];
    }
    else if (opt == 1) {
        for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '-'; i++);
        for (j = (i + 1); line[j] != '\0' && line[j] != '\n' && line[j] != '#'
                    && line[j] != ' '; j++)
            name[(j - (i + 1))] = line[j];
    }
    return name;
}

int name_finder(char *name, room_t *rooms, int max)
{
    int i = 0;

    for (; i < max; i++)
        if (my_strcmp(name, rooms[i].name) == 0)
            return i;
    return -42;
}

tunnel_t *tunnel_initializer(tunnel_t *tunnel, int nb)
{
    int i = 0;

    tunnel = malloc((nb + 1) * sizeof(tunnel_t));
    if (tunnel == NULL)
        return NULL;
    for (; i <= nb; i++) {
        tunnel[i].good = 0;
        tunnel[i].nb = nb;
        tunnel[i].name = NULL;
        tunnel[i].occupy = 0;
        tunnel[i].f_node_name = NULL;
        tunnel[i].f_node_id = 0;
        tunnel[i].l_node_name = NULL;
        tunnel[i].l_node_id = 0;
    }
    return tunnel;
}

tunnel_t *tunnel_filler(tunnel_t *tunnel, input_t *info, int nb, room_t *rooms)
{
    char *line = info->line;
    int ok = 0;
    int *pos;
    int where = 0;

    if (tunnel == NULL)
        return NULL;
    while (info->next != NULL && line[0] != '\n' && line[0] != '\0'
            && ok == 0) {
        jump(&info, &line, line, 0);
        pos = same_finder(line, rooms);
        if (pos == NULL)
            return NULL;
        else if (pos[0] == -42 || pos[1] == -42 || last_check(line) == 1)
            ok = 1;
        tunnel = (ok != 1) ? nod_fil(tunnel, rooms, pos, where) : tunnel;
        where += (ok != 1) ? 1 : 0;
        jump(&info, &line, line, 1);
    }
    return tunnel;
}