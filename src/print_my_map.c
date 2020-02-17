/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

void print_my_map(char **my_map, map_t *map_struct)
{
    int count = 0;
    int line = 0;

    for (; line != map_struct->nb_of_line; count++) {
        mvprintw(line, 0, my_map[line]);
        line++;
    }
}