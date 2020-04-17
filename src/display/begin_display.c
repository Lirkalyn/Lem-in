/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display functions
*/

#include "../../include/graph.h"
#include "../../include/my.h"

void *rooms(list_t **room, int nb)
{
    int a = 0;
    list_t *tmp;
    tmp = *room;

    while (tmp != NULL && ++a < nb)
        tmp = tmp->next;
    return tmp->content;
}

void route(lemin_t *lem, list_t **room)
{
    int a = 0, ant = 1;

    //my_printf("|Route Display|");
    my_putstr("|Route Display|", 0);
    while (lem->dis_ants[lem->ant_nb] != lem->tab_len) {
        while (++a < ant) {
            if (lem->dis_ants[a] != lem->tab_len) {
                write(1, "L", 1);
                my_put_nbr(a);
                write(1, "-", 1);
//                my_putstr(display_rooms(room, (lem->way[lem->dis_ants[a]])), 0);
                write(1, " ", 1);
                lem->dis_ants[a]++;
            }
        }
        write(1, "\n", 1);
        ant += (ant <= lem->ant_nb) ? 1 : 0;
    }
}

void ants(list_t **room, lemin_t *lem)
{
    int a = lem->ant_nb;

    if (!(lem->dis_ants = malloc(sizeof(int) * (lem->ant_nb + 1))))
        return;
    if (!lem->way)
        return;
    for (; a >= 0; a--)
        lem->dis_ants[a] = 1;
//    display(lem, room);
}
