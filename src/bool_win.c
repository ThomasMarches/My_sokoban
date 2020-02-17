/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** bool_win.c
*/

#include "my.h"

bool win(map_t *map_struct)
{
    if (map_struct->p_done == map_struct->number_of_o)
        return (1);
    return (0);
}