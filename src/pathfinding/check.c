/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** to have check before the begining-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int check_before_start(ant_t *ant, room_t *rooms, tunnel_t *tunnel)
{
    int i = 0;
    int j = 0;
    int start = 0;
    int end = 0;

    if (ant->nb == 0)
        return 84;
    for (; i < rooms->nb; i++) {
        start += (rooms[i].start == 1) ? 1 : 0;
        end += (rooms[i].end == 1) ? 1 : 0;
    }
    if (i == 0 && start == 1 && end == 1)
        return 0;
    else if (start != 1 || end != 1 || i < 1)
        return 84;
    for (; tunnel[j].good == 1; j++);
    if (j == 0 || j < (i - 1))
        return 84;
    return 0;
}