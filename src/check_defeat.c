/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_defeat.c
*/

#include "my.h"

void defeat_condition2(map_t *map_struct, char **my_map, int line, int count)
{
    if ((my_map[line - 1][count] == 'X' && my_map[line][count + 1] == '#')
    || (my_map[line - 1][count] == '#' && my_map[line][count - 1] == 'X'))
        map_struct->x_blocked += 1;
    else if ((my_map[line + 1][count] == '#' && my_map[line][count + 1] == 'X')
    || (my_map[line - 1][count] == 'X' && my_map[line][count - 1] == '#'))
        map_struct->x_blocked += 1;
    else if ((my_map[line - 1][count] == '#' && my_map[line][count + 1] == 'X')
    || (my_map[line + 1][count] == 'X' && my_map[line][count - 1] == '#'))
        map_struct->x_blocked += 1;
}

void defeat_condition(map_t *map_struct, char **my_map, int line, int count)
{
    if ((my_map[line + 1][count] == '#' && my_map[line][count + 1] == '#')
    || (my_map[line + 1][count] == '#' && my_map[line][count - 1] == '#'))
        map_struct->x_blocked += 1;
    else if ((my_map[line - 1][count] == '#' && my_map[line][count + 1] == '#')
    || (my_map[line - 1][count] == '#' && my_map[line][count - 1] == '#'))
        map_struct->x_blocked += 1;
    else if ((my_map[line + 1][count] == 'X' && my_map[line][count + 1] == '#')
    || (my_map[line + 1][count] == '#' && my_map[line][count - 1] == 'X'))
        map_struct->x_blocked += 1;
    else
        defeat_condition2(map_struct, my_map, line, count);
}

int check_defeat(map_t *map_struct, char **my_map)
{
    for (int line = 0, count = 0; my_map[line] != NULL; line++) {
        for (; my_map[line][count] != '\0'; count++) {
            if (my_map[line][count] == 'X')
                defeat_condition(map_struct, my_map, line, count);
        }
        count = 0;
    }
    if (map_struct->x_blocked == map_struct->number_of_x) {
        map_struct->defeat = 1;
        return (1);
    }
    map_struct->x_blocked = 0;
    return (0);
}