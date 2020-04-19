/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** more of the same-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

void put_spe(int *next_start, int *start, int *next_end, int *end)
{
    if (*next_start == 1) {
        *start = 1;
        *next_start = 0;
    }
    else if (*next_end == 1) {
        *end = 1;
        *next_end = 0;
    }
}

int spe_finder(char const *s1, char const *s2)
{
    int i = 0;

    for (;s1[(i + 1)] != '\n' && s1[(i + 1)] != '\0'
            && s1[i] != '#'; i++);
    s1 += i;
    for (i = 0; s1[i] != '\n' && s2[i] != '\n'
            && s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 1;
    return 0;
}

int diff_maker(char *line)
{
    int i = 0;
    int space = 0;
    int ok = 0;

    for (; line[i] != '\0' && line[i] != '\n' && line[i] != '#'; i++);
    if (line[i] == '#')
        for (i--; i >= 0;) {
            if (line[i] == ' ' && ok == 0) {
                space++;
                i--;
            }
            else if (line[i] >= '0' && line[i] <= '9') {
                ok = 1;
                i--;
            }
            if (line[i] == ' ' && ok == 1)
                return space;
        }
    return space;
}

room_t *rooms_initializer_2(room_t *rooms, int nb)
{
    int i = 0;

    for (; i < nb; i++) {
        rooms[i].name = NULL;
        rooms[i].id = i;
        rooms[i].start = 0;
        rooms[i].end = 0;
        rooms[i].occupy = 0;
        rooms[i].x = 0;
        rooms[i].y = 0;
    }
    return rooms;
}

room_t *rooms_filler(room_t *rooms, input_t *info, int nb, int forward)
{
    int i = 0;
    int pos = 0;
    int next_start = 0;
    int next_end = 0;
    char *line = NULL;

    for (; i < (forward - 1); i++) {
        line = info->line;
        put_spe(&next_start, &rooms[pos].start, &next_end, &rooms[pos].end);
        if ((rooms_nb_finder_2(line) == 0) || (rooms_nb_finder_2(line) == 1)) {
            next_start = (spe_finder(line, "##start") == 0) ? 1 : 0;
            next_end = (spe_finder(line, "##end") == 0) ? 1 : 0;
            if (check_com(line) == 0) {
                rooms = rooms_name_x_y(line, rooms, pos);
                if (rooms == NULL)
                    return NULL;
                pos++;}}
        info = info->next;
    }
    return rooms;
}