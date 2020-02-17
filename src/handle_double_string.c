/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

char **fill_double_table(char **my_map, char *map)
{
    int line = 0;
    int character = 0;

    for (int count = 0; map[count]; count++) {
        if (map[count] == '\n') {
            my_map[line][character] = '\0';
            line++;
            character = 0;
        } else {
            my_map[line][character] = map[count];
            character++;
        }
    }
    return (my_map);
}

char **malloc_double_table(char **my_map, char *map, map_t *map_struct)
{
    int column = 0;

    my_map = malloc(sizeof(char *) * (map_struct->nb_of_line + 1));
    for (int count = 0, counter = 0; map[count]; count++, counter++) {
        if (counter > column)
            column = counter;
        if (map[count] == '\n' || map[count] == '\0') {
            counter = 0;
        }
    }
    for (int count = 0; count < map_struct->nb_of_line; count++)
        my_map[count] = malloc(sizeof(char) * column + 1);
    my_map[map_struct->nb_of_line] = NULL;
    return (fill_double_table(my_map, map));
}