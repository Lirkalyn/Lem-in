/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** struct
*/

#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <glob.h>

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

#endif
