/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** ...-desu
*/

#include "../../include/my.h"
#include "../../include/algo.h"

int just_comm(char *line)
{
    int i = 0;

    for (; (line[i] == ' ' || line[i] == '#' || line[i] == '\t')
            && line[i] != '\0'; i++);
    if ((i > 0) && (line[(i - 1)] == '#' || line[i] == '#'))
        return 1;
    else if (line[i] == '#')
        return 1;
    else
        return 0;
}

void jump(input_t **info, char **line, char *str, int opt)
{
    if (just_comm(str) == 1 && opt == 0) {
        info[0] = info[0]->next;
        *line = info[0]->line;
    }
    else if (opt == 1) {
        info[0] = info[0]->next;
        *line = info[0]->line;
    }
}