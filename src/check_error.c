/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

int check_error(char *map)
{
    for (int count = 0; map[count] != '\0'; count++) {
        if (map[count] != 'P' && map[count] != 'O' && map[count] != ' ' &&
            map[count] != 'X' && map[count] != '\n' && map[count] != '#')
            return (84);
    }
    return (1);
}
