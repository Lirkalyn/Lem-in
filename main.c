/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main dispay
*/

#include "include/graph.h"
#include "include/my.h"
#include "include/algo.h"

void init(lemin_t *lem)
{
    lem->end = 0;
    lem->start = 0;
    lem->room_nb = 1;
    lem->tab_len = 0;
    lem->ant_nb = 0;
}

int main(void)
{
    lemin_t lem;
    list_t *room = NULL;
    input_t *info = NULL;
    ant_t *ant = NULL;
    tunnel_t *tunnel = NULL;
    room_t *rooms = NULL;

    init(&lem);
    info = input_taker();
    if (all_filler(info, &ant, &rooms, &tunnel) == 84)
        return 84;
    if (ant == NULL || rooms == NULL || tunnel == NULL)
        return 84;
    disp(ant, rooms, tunnel);
    return 0;
}