/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main dispay
*/

#include "graph.h"

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
    list_t *room;

    room = NULL;

    init(&lem);
    display_route(&room, &lem);
    return 0;
}