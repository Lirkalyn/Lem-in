/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** more of the same-desu ///should be call room.c
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    int len = 0;
    int men = 0;

    for (; s1[len] != '\0'; len++);
    for (; s2[men] != '\0'; men++);
    if (len != men)
        return 1;
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
    int dif = diff_maker(line);

    if (my_strcmp(line, "##start") == 0 || my_strcmp(line, "##end") == 0)
        return 0;
    check = is_space(line);
    if (check != 0)
        return check;
    for (; line[i] != '\0' && line[i] != '\n' && line[i] != ' '; i++);
    i += (line[i] == ' ') ? 1 : 0;
    for (; line[i] != '\0' && line[i] != '\n'; i++) {
        pos += (line[i] == ' ') ? 1 : 0;
        if (line[i] == '#' && pos >= 1 && ((pos - dif) < 2))
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
//        printf("rooms = %d = %s", nb_tmp_2, info->line);
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

room_t *rooms_initializer(room_t *rooms, input_t *info, int nb, int forward)
{
    int i = 0;

    rooms = malloc((nb + 1) * sizeof(room_t));
    if (rooms == NULL)
        return NULL;
    for (; i < nb; i++)
        rooms[i].nb = nb;
    rooms = rooms_initializer_2(rooms, nb);
    rooms = rooms_filler(rooms, info, nb, forward);
/*
    for (int j = 0; j < nb; j++)
        printf("x = %d, y = %d, start = %d, end = %d et %s\n", rooms[j].x, rooms[j].y, rooms[j].start, rooms[j].end, rooms[j].name);
*/
    return rooms;
}