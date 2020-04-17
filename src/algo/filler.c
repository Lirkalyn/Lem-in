/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** will initiale and fill the followinng variable : ant, tunnel and room-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int all_filler(input_t *info, ant_t **ant, room_t **rooms, tunnel_t **tunnel)
{
//    int bool_ant_done = 0;
//    int bool_rooms_done = 0;
//    int bool_tunnel_done = 0;
    int nb_tmp = 0;
    int nb_tmp_2 = 0;
    int forward = 0;
//    char *line_tmp = NULL;

    ant[0] = ant_initializer(ant[0], info);
    if (ant[0] == NULL)
        return 84;
    else
        info = info->next;
    printf("ant = %d\n", ant[0]->nb);

    forward = rooms_nb_finder(info, &nb_tmp);
    if (forward == -84)
        return 84;
    else {
        printf("rooms = %d\n", nb_tmp);
        printf("forward = %d\n", forward);
        for (int i = 0; i < (forward - 1); i++)
            info = info->next;
    }

    tunnel_nb_finder(info, &nb_tmp_2);
    printf("\ntunnel = %d\n", nb_tmp_2);
//    printf("\n\n");
/*
        if (*rooms == NULL)
            return 84;
        rooms[0] = ant_initializer(rooms[0], nb_tmp);*/
}