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

//    room = NULL;

    init(&lem);

    info = input_taker();
/*    while (info->next != NULL)
    {
        info = info->next;
    }
*/
    if (all_filler(info, &ant, &rooms, &tunnel) == 84)
        return 84;
    //printf("%d\n", ant->nb);
    return 0;
}