/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** more of the same-desu
*/

int diff_maker(char *line)
{
    int i = 0;
    int space = 0;
    int ok = 0;

    for (; line[i] != '\0' && line[i] != '\n' && line[i] != '#'; i++);
    if (line[i] == '#')
        for (i--; i >= 0;) {
            if (line[i] == ' ' && ok == 0) {
                space++;
                i--;
            }
            else if (line[i] >= '0' && line[i] <= '9') {
                ok = 1;
                i--;
            }
            if (line[i] == ' ' && ok == 1)
                return space;
        }
    return space;
}