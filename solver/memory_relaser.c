/*
** EPITECH PROJECT, 2022
** memory relaser
** File description:
** memeoty leak checker
*/

#include "solver.h"

void list_deleter(path my)
{
    node *a = my.first;
    node *b = NULL;

    while (a->next != NULL) {
        b = a;
        a = a->next;
        free(b);
    }
    free(a);
}

void tree_slaughter(graph *tree)
{
    int i = 0;

    while (tree->next != NULL) {
        tree = tree->next;
        list_deleter(tree->prev->op);
        free(tree->prev);
        i += 1;
    }
}

void arr_2d_deleter(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i += 1;
    }
}

int is_correct_maps(char *str)
{
    int i = 0, j = 0, k = 0, x = 0;
    if (str == NULL) return 84;

    k = strlen(str);

    while (str[i] != '\0' && str[i] != '\n') i += 1;
    while (str[x] != '\0') {
        if (str[x] == '\n') j += 1;
        x += 1;
    } if (k != ((j + 1) * (i + 1)) - 1) return 84;
    return 0;
}
