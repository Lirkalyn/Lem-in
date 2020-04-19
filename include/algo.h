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
int rooms_nb_finder(input_t *info, int *nb_tmp);
int tunnel_nb_finder(input_t *info, int *nb_tmp);
int go_too_far(char *line);
ant_t *ant_initializer(ant_t *ant, input_t *info);
int diff_maker(char *line);
room_t *rooms_initializer(room_t *rooms, input_t *info, int nb, int forward);
room_t *rooms_initializer_2(room_t *rooms, int nb);
room_t *rooms_filler(room_t *rooms, input_t *info, int nb, int forward);
int rooms_nb_finder_2(char *line);
int spe_finder(char const *s1, char const *s2);
room_t *rooms_name_x_y(char *line, room_t *rooms, int pos);
int check_com(char *line);
tunnel_t *tunnel_filler(tunnel_t *tunnel, input_t *info, int nb, room_t *rooms);
int my_strcmp(char const *s1, char const *s2);
int lenght_finder(char *line, int opt);
int *same_finder(char *line, room_t *rooms);
char *name_putter(char *line, int len, int opt);
int name_finder(char *name, room_t *rooms, int max);
tunnel_t *nod_fil(tunnel_t *tunnel, room_t *rooms, int *pos, int where);
int last_check(char *line);
int too_much_sep(char *line);
void jump(input_t **info, char **line, char *str, int opt);
tunnel_t *tunnel_initializer(tunnel_t *tunnel, int nb);
int check_before_start(ant_t *ant, room_t *rooms, tunnel_t *tunnel);
ant_t *ant_pos(ant_t *ant, room_t *rooms);

#endif
