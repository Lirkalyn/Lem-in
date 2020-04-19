/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** it's make to display everything exept the moves-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

void disp(ant_t *ant, room_t *rooms, tunnel_t *tunnel)
{
    my_putstr("#number_of_ants", 0);
    my_put_nbr(ant->nb);
    write(1, "\n", 1);
    my_putstr("#rooms", 0);
    for (int i = 0; i < rooms->nb; i++) {
        if (rooms[i].start == 1)
            my_putstr("##start", 0);
        else if (rooms[i].end == 1)
            my_putstr("##end", 0);
        my_putstr(rooms[i].name, 1);
        my_put_nbr(rooms[i].x);
        write(1, " ", 1);
        my_put_nbr(rooms[i].y);
        write(1, "\n", 1);
    }
    my_putstr("#tunnels", 0);
    for (int i = 0; tunnel[i].good == 1; i++)
        my_putstr(tunnel[i].name, 0);
    my_putstr("#moves", 0);
}