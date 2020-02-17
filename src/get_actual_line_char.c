/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** get_actual_line_char.c
*/

#include "my.h"

int get_actual_line_char(map_t *map_struct, char *map)
{
    int nbr = 0;
    int counter = map_struct->p_position_x;
    int temp = 0;

    for (; map[counter] != '\n'; counter = counter -1);
    counter = counter + 1;
    temp = counter;
    for (; map[temp] != '\n'; temp = temp + 1);
    nbr = temp - counter;
    return (nbr + 1);
}