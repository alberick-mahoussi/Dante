/*
** EPITECH PROJECT, 2022
** gen_map
** File description:
** generate map in favor of rows and col
*/

#include "generator.h"

void view_map(char **tab, int c)
{
    int i = 0;
    for (; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        if (i  < c - 1)
            my_putstr("\n");
    }
}

char **generate_perfect_maze(int x, int y)
{
    int c = 0, d = 0;
    int var = 0;
    char **map;

    map = malloc(sizeof(char *) * (x + 1));
    for (c = 0; c < x; c++) {
        map[c] = malloc(sizeof(char) * (y + 1));
        var = random() % y;
        for (d = 0; d < y; d++) {
            map[c][d] = 'X';
            if (d == var)
                map[c][d] = '*';
            if ((c % 2) == 0)
                map[c][d] = '*';
        }
    }
    map[c - 1][d - 1] = '*';
    map[c] = NULL;
    return (map);
}

char **generate_imperfect_maze(int x, int y)
{
    int c = 0, d = 0;
    int var = 0, va = 0;
    char **map;

    map = malloc(sizeof(char *) * (x + 1));
    for (c = 0; c < x; c++) {
        map[c] = malloc(sizeof(char) * (y + 1));
        va = random() % y;
        var = random() % y;
        for (d = 0; d < y; d++) {
            map[c][d] = 'X';
            if (d == var)
                map[c][d] = '*';
            if (d == va)
                map[c][d] = '*';
            if ((c % 2) == 0)
                map[c][d] = '*';
        }
    } map[x - 1][y - 1] = '*';
    map[c] = NULL;
    return (map);
}

int error(int ac, char **av)
{
    int i = 0, j = 0;
    if (ac != 3 && ac != 4)
        return 84;
    for (i = 1; i < 3; i++) {
        for (j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (84);
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;
    char **perfect = NULL;
    char **imperfect = NULL;

    if (error(ac, av) == 84)
        return (84);
    x = atoi(av[1]);
    y = atoi(av[2]);
    perfect = generate_perfect_maze(x, y);
    imperfect = generate_imperfect_maze(x, y);
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        view_map(perfect, x);
    else if (ac == 3)
        view_map(imperfect, x);
    return 0;
}
