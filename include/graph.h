/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** graph
*/

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "my.h"
#include "struct.h"

void *rooms(list_t **room, int nb);
void route(lemin_t *lem, list_t **room);
void ants(list_t **room, lemin_t *lem);

void init(lemin_t *lem);
#endif
