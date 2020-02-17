/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

void get_position_of_o(map_t *map_struct, char **my_map)
{
    int nbr_o = 0;
    map_struct->position_o_y = malloc(sizeof(int) * map_struct->number_of_o);
    map_struct->position_o_x = malloc(sizeof(int) * map_struct->number_of_o);

    map_struct->number_of_x = 0;
    for (int line = 0, count = 0; my_map[line] != NULL; line++) {
        for (; my_map[line][count] != '\0'; count++) {
            if (my_map[line][count] == 'O') {
                map_struct->position_o_x[nbr_o] = count;
                map_struct->position_o_y[nbr_o] = line;
                nbr_o++;
            } else if (my_map[line][count] == 'X')
                map_struct->number_of_x += 1;
        }
        count = 0;
    }
}

void put_o(map_t *map_struct, char **my_map)
{
    int nbr_o = 0;

    for (int line = 0, count = 0; my_map[line] != NULL; line++) {
        for (; my_map[line][count] != '\0'; count++) {
            if (nbr_o == map_struct->number_of_o)
                break;
            if (line == map_struct->position_o_y[nbr_o] &&
            count == map_struct->position_o_x[nbr_o] &&
            my_map[line][count] != 'P' && my_map[line][count] != 'X') {
                my_map[line][count] = 'O';
                nbr_o++;
            }
        }
        count = 0;
    }
}