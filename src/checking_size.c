/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

int checking_size(char *filetopath)
{
    int size = 0;
    struct stat *buff;
    int error;

    buff = malloc(sizeof(struct stat));
    error = stat(filetopath, buff);
    size = buff->st_size;
    free(buff);
    if (error == -1)
        return (-1);
    return (size);
}