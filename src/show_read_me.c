/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

int show_read_me(void)
{
    FILE *fd;
    char *map = malloc(sizeof(char) * 5001);

    fd = fopen("usage.txt", "r");
    fread(map, 5000, 1, fd);
    write(1, map, my_strlen(map) + 1);
    fclose(fd);
    free(map);
    return (0);
}