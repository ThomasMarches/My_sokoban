/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

void init_struct(map_t *map_struct, char *map)
{
    int count = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    map_struct->p_done = 0;
    map_struct->x_blocked = 0;
    map_struct->defeat = 0;
    map_struct->nb_of_line = 0;
    map_struct->number_of_o = 0;
    for (; map[count] != '\0'; count++) {
        if (map[count] == '\n')
            map_struct->nb_of_line = map_struct->nb_of_line + 1;
        else if (map[count] == 'O')
            map_struct->number_of_o = map_struct->number_of_o + 1;
    }
}