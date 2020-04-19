/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** A* algo-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

ant_t *ant_pos(ant_t *ant, room_t *rooms)
{
    int i = 0;
    int j = 0;
    int ok = 0;

    for (; i < rooms->nb && ok == 0; i++)
        ok = (rooms[i].start == 1) ? 1 : 0;
    if (ok == 1)
        i--;
    for (; j < ant->nb; j++) {
        ant[j].pos_name = rooms[i].name;
        ant[j].pos_id = rooms[i].id;
    }
    return ant;
}

int end_finder(room_t *rooms)
{
    int i = 0;
    for (; i < rooms->nb; i++)
        if (rooms[i].end == 1)
            return i;
}