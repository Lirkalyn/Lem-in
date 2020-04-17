/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** will initiale and fill the followinng variable : ant, tunnel and room-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int ant_nb_finder(char *line, int *nb)
{
    int i = 0;

    for (; line[i] != '\0' && line[i] != '\n'; i++)
        if (line[i] < '0' || line[i] > '9')
            return -84;
        else {
            *nb *= 10;
            *nb += (line[i] - '0');
        }
    return 1;
}

ant_t *ant_initializer(ant_t *ant, int nb)
{
    for (int i = 0; i < nb; i++) {
        ant[i].id = i;
        ant[i].nb = nb;
        ant[i].pos_name = NULL;
        ant[i].pos_id = 0;
    }
    return ant;
}

int all_filler(input_t *info, ant_t **ant, room_t **rooms, tunnel_t **tunnel)
{
    int bool_ant_nb = 0;
    int bool_ant_done = 0;
    int bool_rooms_done = 0;
    int bool_tunnel_done = 0;
    int nb_tmp = 0;
    int nb_tmp_2 = 0;
    int forward = 0;
    char *line_tmp = NULL;

    while (info->next != NULL && bool_ant_nb == 0)
    {
/////////////////////////////////////////
        if (bool_ant_nb == 0) {
            bool_ant_nb = ant_nb_finder(info->line, &nb_tmp);
            info = info->next;
        }
    }
    printf("ant = %d\n", nb_tmp);
        *ant = (bool_ant_nb == -84) ? NULL : malloc(nb_tmp * sizeof(ant_t));
        if (*ant == NULL)
            return 84;
        ant[0] = ant_initializer(ant[0], nb_tmp);
/////////////////////////////////////////

        nb_tmp = 0;
        forward = rooms_nb_finder(info, &nb_tmp);
        if (forward == -84)
            return 84;
        printf("rooms = %d\n", nb_tmp);
        printf("forward = %d\n", forward);
        for (int i = 0; i < (forward - 1); i++)
            info = info->next;
        //printf("%s\n", info->line);



    nb_tmp = 0;
    tunnel_nb_finder(info, &nb_tmp);
    printf("\ntunnel = %d\n", nb_tmp);

    printf("\n\n");

//    if (nb_tmp != 0)
//        bool_tunnel_done = 1;


//        nb_tmp = 0;
//    printf("\n%d\n", nb);


        //info = info->next;
        //nb_tmp = 0;
//        printf("%d\n", bool_rooms_done);

//        printf("1 =%s", info->line);
//        for (int i = 0; i < rewind; i++)
//            info = info->preview;
//        printf("2=%s", info->line);

//        info = info->preview;
//        printf("3=%s", info->line);
//        rewind = 0;
        //info = info->preview;
//        printf("kkkkkkkkkkkkk\n");
//        printf("%d\n", nb_tmp);
        //info = info->preview;
//            bool_rooms_done = 
/*        *rooms = (bool_rooms_done == -84) ? NULL : malloc(nb_tmp * sizeof(room_t));
        if (*rooms == NULL)
            return 84;
        rooms[0] = ant_initializer(rooms[0], nb_tmp);*/

        info = info->next;
//    }
}