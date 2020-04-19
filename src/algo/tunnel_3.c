/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** too much-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int *same_finder(char *line, room_t *rooms)
{
    char **name = malloc(2 * sizeof(char *));
    int *pos = malloc(2 * sizeof(int));

    if (name == NULL || pos == NULL)
        return NULL;
    name[0] = name_putter(line, lenght_finder(line, 0), 0);
    name[1] = name_putter(line, lenght_finder(line, 1), 1);
    if (name[0] == NULL || name[1] == NULL)
        return NULL;
    pos[0] = name_finder(name[0], rooms, rooms[0].nb);
    pos[1] = name_finder(name[1], rooms, rooms[0].nb);
    return pos;
}

char *namemaker(char *start, char *end)
{
    int len1 = 0;
    int len2 = 0;
    char *rsl;
    int i = 0;
    int j = 0;

    for (; start[len1] != '\0'; len1 += 1);
    for (; end[len2] != '\0'; len2 += 1);
    rsl = (char *)malloc((len1 + len2 + 2) * sizeof(char));
    if (rsl == NULL)
        return NULL;
    rsl[(len1 + len2 + 1)] = '\0';
    for (i = 0; i < len1; i++)
        rsl[i] = start[i];
    rsl[i++] = '-';
    for (j = 0; end[j] != '\0'; j++)
        rsl[(i + j)] = end[j];
    return rsl;
}

tunnel_t *nod_fil(tunnel_t *tunnel, room_t *rooms, int *pos, int where)
{
    tunnel[where].name = namemaker(rooms[pos[0]].name, rooms[pos[1]].name);
    if (tunnel[where].name == NULL)
        return NULL;
    tunnel[where].f_node_name = rooms[pos[0]].name;
    tunnel[where].f_node_id = rooms[pos[0]].id;
    tunnel[where].l_node_name = rooms[pos[1]].name;
    tunnel[where].l_node_id = rooms[pos[1]].id;
    tunnel[where].good = 1;
    return tunnel;
}

int last_check_2(char *line)
{
    int i = 0;
    int space = 0;
    int space2 = 0;

    for (; line[i] != '#';)
        if (line[i] == ' ')
            space++;
    for (; i >= 0 && line[i] == ' '; i--)
        if (line[i] == ' ')
            space2 += 1;
    if (space == space2)
        return 0;
    else
        return 1;
}

int last_check(char *line)
{
    int i = 0;
    int space = 0;
    int com = 0;

    if (too_much_sep(line) == 1)
        return 1;

    for (; line[i] != '\0' && line[i] != '\n' && line[i] != ' '
            && line[i] != '#'; i++) {
            space += (line[(i + 1)] == ' ') ? 1 : 0;
            com = (line[(i + 1)] == '#') ? 1 : com;
    }
    if (com == 0 && space != 0)
        return 1;
    else if (com > 0 && space != 0)
        return last_check_2(line);
}