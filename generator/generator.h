/*
** EPITECH PROJECT, 2022
** generator.h
** File description:
** header
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_
    #include <ncurses.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
void cell_init(int *c, char *x);
char **maps_formater(int y, int x);
void random_point_placer(char **maps);
void is_wall(char **maps, int y, int x);
void road_checker(char **maps);
void random_value(char *x);

#endif /* !GENERATOR_H_ */
