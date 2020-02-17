/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** get str len
*/

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}