/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** struct
*/

#ifndef __STRUCT_H__
#define __STRUCT_H__

#include "header.h"

typedef struct list {
    void *content;
    size_t size;
    struct list *next;
} list_t;

typedef struct lemin {
    int room_nb;
    int start;
    int end;
    int *next;
    int *fin;
    int ant_nb;
    int *dis_ants;
    int *way;
    int *dis;
    int **links;
    int tab_len;
    int **gr;
} lemin_t;

typedef struct Ant {
    int nb;
    int id;
    char *pos_name;
    int pos_id;
} ant_t;

typedef struct Tunnel {
    int good;
    int nb;
    char *name;
    int occupy;
    char *f_node_name;
    int f_node_id;
    char *l_node_name;
    int l_node_id;
} tunnel_t;

typedef struct Room {
    int nb;
    char *name;
    int id;
    int start;
    int end;
    int occupy;
    int x;
    int y;
} room_t;

typedef struct input {
    char *line;
    size_t len;
    struct input *next;
    struct input *preview;
} input_t;

#endif
