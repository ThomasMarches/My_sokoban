/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

char *fill_map(char *av, int size, char *map, map_t *map_struct)
{
    FILE *fd;

    fd = fopen(av, "r");
    if (fd == NULL)
        exit(84);
    fread(map, size, 1, fd);
    map[size] = '\0';
    fclose(fd);
    init_struct(map_struct, map);
    return (map);
}