/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main.c
*/

#include "my.h"

void different_inputs(map_t *map_struct, char *map, char **my_map, int pressed)
{
    char a = 0;
    char b = 0;

    if (pressed == KEY_RIGHT)
        move_right(map_struct, my_map, a, b);
    else if (pressed == KEY_UP)
        move_up(map_struct, my_map, a, b);
    else if (pressed == ' ')
        my_map = fill_double_table(my_map, map);
}

void check_input(map_t *map_struct, char *map, char **my_map)
{
    int pressed = getch();
    char a = 0;
    char b = 0;

    for (int line = 0, count = 0; my_map[line] != NULL; line++) {
        for (; my_map[line][count] != '\0'; count++) {
            if (my_map[line][count] == 'P') {
                map_struct->p_position_x = count;
                map_struct->p_position_y = line;
            }
        }
        count = 0;
    }
    if (pressed == KEY_LEFT)
        move_left(map_struct, my_map, a, b);
    else if (pressed == KEY_DOWN)
        move_down(map_struct, my_map, a, b);
    else
        different_inputs(map_struct, map, my_map, pressed);
}

int end_of_game(char *map, map_t *map_struct, char **my_map)
{
    int temp = 0;

    if (map_struct->defeat == 1)
        temp = 1;
    clear();
    endwin();
    free(map);
    for (int count = 0; count != map_struct->nb_of_line; count++)
        free(my_map[count]);
    free(my_map);
    free(map_struct->position_o_x);
    free(map_struct->position_o_y);
    free(map_struct);
    return (temp);
}

int game_loop(char *map, map_t *map_struct, char **my_map)
{
    check_input(map_struct, map, my_map);
    put_o(map_struct, my_map);
    print_my_map(my_map, map_struct);
    refresh();
    if (check_defeat(map_struct, my_map) == 1)
        return (1);
    if (win(map_struct) == 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int size = checking_size(av[1]);
    char *map = malloc(sizeof(char) * size + 2);
    map_t *map_struct = malloc(sizeof(map_t));
    char **my_map = NULL;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (show_read_me());
    if (size == -1)
        return (84);
    map = fill_map(av[1], size, map, map_struct);
    if (check_error(map) != 1)
        return (84);
    my_map = malloc_double_table(my_map, map, map_struct);
    get_position_of_o(map_struct, my_map);
    print_my_map(my_map, map_struct);
    while (game_loop(map, map_struct, my_map) != 1);
    return (end_of_game(map, map_struct, my_map));
}