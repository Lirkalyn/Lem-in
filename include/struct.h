/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** struct
*/

#ifndef __STRUCT_H__
#define __STRUCT_H__

//#include <glob.h>
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
    int nb; // pour connaitre le nombre totale de fourmit
    int id; // pour savoir qu'elle fourmit c'est.
    char *pos_name; // le nom de la salle où se trouve la fourmit
    int pos_id; // l'id de la salle où se trouve la fourmit
} ant_t;

typedef struct Tunnel {
    int good; // pour savoir si le tunnel est valide. = 1 si oui.
    int nb; // pour connaitre le nombre totale de tunnel
    char *name; // le nom officiel du tunnel. obtenue dans l'input
    int occupy; // si une fourmit est déjà dedans = 1.
    char *f_node_name; // le nom de la première salle du tunnel
    int f_node_id; // id de cette dernière
    char *l_node_name; // le nom de la dernière salle du tunnel
    int l_node_id; // id de cette dernière
} tunnel_t;

typedef struct Room {
    int nb; // pour connaitre le nombre totale de pièce
    char *name; // le nom officiel de la pièce . obtenue dans l'input
    int id; // pour reconnaitre facile les différente pièce.
    int start; // si la salle est start ou  end = 1. comme ça on sait dans quelle salle ne pas vérifier occupy.
    int end; // si la salle est start ou  end = 1. comme ça on sait dans quelle salle ne pas vérifier occupy.
    int occupy; // si une fourmit est déjà dedans = 1.
    int x; // position x of the room.
    int y; // position x of the room.
} room_t;

typedef struct input {
    char *line;
    size_t len;
    struct input *next;
    struct input *preview;
} input_t;

#endif
