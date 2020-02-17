/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game
*/

#ifndef MY_H_
#define MY_H_

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

typedef struct {
    int number_of_o;
    int p_done;
    int p_position_x;
    int p_position_y;
    int x_blocked;
    int sizex;
    int sizey;
    int defeat;
    int size;
    int nb_of_line;
    int nb_of_char;
    int number_of_x;
    int *position_o_y;
    int *position_o_x;
} map_t;

int check_error(char *map);
bool win(map_t *map_struct);
int checking_size(char *filetopath);
int check_defeat(map_t *map_struct, char **my_map);
int get_actual_line_char(map_t *map_struct, char *map);
void move_left(map_t *map_struct, char **my_map, char a, char b);
void move_right(map_t *map_struct, char **my_map, char a, char b);
void move_down(map_t *map_struct, char **my_map, char a, char b);
void move_up(map_t *map_struct, char **my_map, char a, char b);
char *my_strcpy(char *dest, char const *src);
char *fill_map(char *av, int size, char *map, map_t *map_struct);
void print_my_map(char **my_map, map_t *map_struct);
void put_o(map_t *map_struct, char **my_map);
void get_position_of_o(map_t *map_struct, char **my_map);
int my_strlen(const char *str);
void init_struct(map_t *map_struct, char *map);
int end_of_game(char *map, map_t *map_struct, char **my_map);
char **fill_double_table(char **my_map, char *map);
int show_read_me(void);
char **malloc_double_table(char **my_map, char *map, map_t *map_struct);
void get_position_of_o(map_t *map_struct, char **my_map);
void put_o(map_t *map_struct, char **my_map);

#endif /* !MY_H_*/