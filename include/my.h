/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all functions
*/

#ifndef __MY_H__
#define __MY_H__

#include "header.h"
#include "struct.h"

void my_putchar(char c);
void my_charerror(char e);
int my_putstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
void disp(ant_t *ant, room_t *rooms, tunnel_t *tunnel);

#endif
