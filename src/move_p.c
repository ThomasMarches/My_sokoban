/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_p.c
*/

#include "my.h"

void move_down(map_t *map_struct, char **my_map, char a, char b)
{
    if (my_map[map_struct->p_position_y + 1][map_struct->p_position_x] == '#')
        return;
    a = my_map[map_struct->p_position_y + 1][map_struct->p_position_x];
    b = my_map[map_struct->p_position_y + 2][map_struct->p_position_x];
    if (a != '#' && a != 'X') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y + 1][map_struct->p_position_x] = 'P';
    } else if (a == 'X' && b != 'X' && b != '#') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y + 1][map_struct->p_position_x] = 'P';
        if (my_map[map_struct->p_position_y + 2][map_struct->p_position_x]
        == 'O')
            map_struct->p_done += 1;
        my_map[map_struct->p_position_y + 2][map_struct->p_position_x] = 'X';
    }
}

void move_up(map_t *map_struct, char **my_map, char a, char b)
{
    if (my_map[map_struct->p_position_y - 1][map_struct->p_position_x] == '#')
        return;
    a = my_map[map_struct->p_position_y - 1][map_struct->p_position_x];
    b = my_map[map_struct->p_position_y - 2][map_struct->p_position_x];
    if (a != '#' && a != 'X') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y - 1][map_struct->p_position_x] = 'P';
    } else if (a == 'X' && b != 'X' && b != '#') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y - 1][map_struct->p_position_x] = 'P';
        if (my_map[map_struct->p_position_y - 2][map_struct->p_position_x]
        == 'O')
            map_struct->p_done += 1;
        my_map[map_struct->p_position_y - 2][map_struct->p_position_x] = 'X';
    }
}

void move_left(map_t *map_struct, char **my_map, char a, char b)
{
    if (my_map[map_struct->p_position_y][map_struct->p_position_x - 1] == '\0'
    || my_map[map_struct->p_position_y][map_struct->p_position_x - 1] == '#')
        return;
    a = my_map[map_struct->p_position_y][map_struct->p_position_x - 1];
    b = my_map[map_struct->p_position_y][map_struct->p_position_x - 2];
    if (my_map[map_struct->p_position_y][map_struct->p_position_x - 1] ==
    'X' && my_map[map_struct->p_position_y][map_struct->p_position_x - 2]
    == '\0')
        return;
    if (a != '#' && a != 'X') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y][map_struct->p_position_x - 1] = 'P';
    } else if (a == 'X' && b != 'X' && b != '#') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y][map_struct->p_position_x - 1] = 'P';
        if (my_map[map_struct->p_position_y][map_struct->p_position_x - 2]
        == 'O')
            map_struct->p_done += 1;
        my_map[map_struct->p_position_y][map_struct->p_position_x - 2] = 'X';
    }
}

void move_right(map_t *map_struct, char **my_map, char a, char b)
{
    if (my_map[map_struct->p_position_y][map_struct->p_position_x + 1] == '\0'
    || my_map[map_struct->p_position_y][map_struct->p_position_x + 1] == '#')
        return;
    a = my_map[map_struct->p_position_y][map_struct->p_position_x + 1];
    b = my_map[map_struct->p_position_y][map_struct->p_position_x + 2];
    if (my_map[map_struct->p_position_y][map_struct->p_position_x + 1] ==
    'X' && my_map[map_struct->p_position_y][map_struct->p_position_x + 2]
    == '\0')
        return;
    if (a != '#' && a != 'X') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y][map_struct->p_position_x + 1] = 'P';
    } else if (a == 'X' && b != 'X' && b != '#') {
        my_map[map_struct->p_position_y][map_struct->p_position_x] = ' ';
        my_map[map_struct->p_position_y][map_struct->p_position_x + 1] = 'P';
        if (my_map[map_struct->p_position_y][map_struct->p_position_x + 2]
        == 'O')
            map_struct->p_done += 1;
        my_map[map_struct->p_position_y][map_struct->p_position_x + 2] = 'X';
    }
}