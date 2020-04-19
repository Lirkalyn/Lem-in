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
    if (all_filler(info, &ant, &rooms, &tunnel) == 84)
        return 84;
    if (ant == NULL || rooms == NULL || tunnel == NULL)
        return 84;
    printf("ant = %d\n", ant->nb);
    printf("rooms\n\n");
    for (int i = 0; i < rooms->nb; i++) {
        printf("room : %d\n", i);
        printf("nb = %d\n", rooms[i].nb);
        printf("name = %s\n", rooms[i].name);
        printf("id = %d\n", rooms[i].id);
        printf("start = %d\n", rooms[i].start);
        printf("end = %d\n", rooms[i].end);
        printf("occupy = %d\n", rooms[i].occupy);
        printf("x = %d\n", rooms[i].x);
        printf("y = %d\n", rooms[i].y);
        printf("\n\n");
    }

    printf("tunnel\n\n");

    for (int i = 0; tunnel[i].good == 1; i++) {
        printf("i = %d\n", i);
        printf("good = %d\n", tunnel[i].good);
        printf("nb = %d\n", tunnel[i].nb);
        printf("name = %s\n", tunnel[i].name);
        printf("occupy = %d\n", tunnel[i].occupy);
        printf("f_node_name = %s\n", tunnel[i].f_node_name);
        printf("f_node_id = %d\n", tunnel[i].f_node_id);
        printf("l_node_name = %s\n", tunnel[i].l_node_name);
        printf("l_node_id = %d\n", tunnel[i].l_node_id);
        printf("\n\n");
    }

    return 0;
}