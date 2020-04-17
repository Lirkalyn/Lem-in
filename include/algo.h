/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** for all of the algo's function-desu
*/

#ifndef __ALGO_H__
#define __ALGO_H__

#include "header.h"
#include "struct.h"

input_t *input_taker(void);
int all_filler(input_t *info, ant_t **ant, room_t **rooms, tunnel_t **tunnel);
//int rooms_nb_finder(char *line);
int rooms_nb_finder(input_t *info, int *nb_tmp);
int tunnel_nb_finder(input_t *info, int *nb_tmp);
int go_too_far(char *line);

int is_separator(char *line);

#endif
