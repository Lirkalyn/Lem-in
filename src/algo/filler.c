/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** will initiale and fill the followinng variable : ant, tunnel and room-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

tunnel_t *pre_tu_fill(input_t *info, tunnel_t *tunnel, room_t *rooms)
{
    int nb_tmp_2 = 0;

    tunnel_nb_finder(info, &nb_tmp_2);
    tunnel = tunnel_initializer(tunnel, nb_tmp_2);
    tunnel = tunnel_filler(tunnel, info, nb_tmp_2, rooms);
    return tunnel;
}

int all_filler(input_t *info, ant_t **ant, room_t **rooms, tunnel_t **tunnel)
{
    int nb_tmp = 0;
    int forward = 0;

    ant[0] = ant_initializer(ant[0], info);
    if (ant[0] == NULL)
        return 84;
    else
        info = info->next;
    forward = rooms_nb_finder(info, &nb_tmp);
    if (forward == -84)
        return 84;
    else {
        rooms[0] = rooms_initializer(rooms[0], info, nb_tmp, forward);
        for (int i = 0; i < (forward - 1); i++)
            info = info->next;
    }
    tunnel[0] = pre_tu_fill(info, tunnel[0], rooms[0]);
}