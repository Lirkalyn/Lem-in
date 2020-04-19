/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** more and more-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

room_t *rooms_x_y(char *line, room_t *rooms, int pos, int i)
{
    for (i++; line[i] != '\0' && line[i] != '\n' && line[i] != ' '
                && line[i] != '#'; i++) {
        rooms[pos].x *= 10;
        rooms[pos].x += (line[i] - '0');
    }
    for (i++; line[i] != '\0' && line[i] != '\n' && line[i] != ' '
                && line[i] != '#'; i++) {
        rooms[pos].y *= 10;
        rooms[pos].y += (line[i] - '0');
    }
    return rooms;
}

room_t *rooms_name_x_y(char *line, room_t *rooms, int pos)
{
    int i = 0;
    int len = 0;
    int nb = 0;

    for (; line[len] != '\0' && line[len] != '\n' && line[len] != ' '; len++);
    rooms[pos].name = malloc((len + 1) * sizeof(char));
    if (rooms[pos].name == NULL)
        return NULL;
    rooms[pos].name[len] = '\0';
    for (; line[i] != '\0' && line[i] != '\n' && line[i] != ' '; i++)
        rooms[pos].name[i] = line[i];
    rooms = rooms_x_y(line, rooms, pos, i);
    return rooms;
}

int check_com(char *line)
{
    int i = 0;
    int space = 0;

    for (; line[i] != '\0' && line[i] != '\n' && line[i] != '#'; i++)
        if (line[i] == ' ')
            space++;
    if (i == space)
        return 1;
    else
        return 0;
}