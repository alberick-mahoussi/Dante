/*
** EPITECH PROJECT, 2022
** graph management
** File description:
** path list gestion
*/

#include "solver.h"

void tree_init(graph *my)
{
    path op = initialisation(op);
    my->op = op;
    my->prev = NULL;
    my->next = NULL;
}

void branches_adding(graph *tree, path branche)
{
    graph *a = tree;
    graph *my = malloc(sizeof(graph));

    while (a->next != NULL) {
        a = a->next;
    } a->op = branche;
    path op = initialisation(op);
    my->op = op;
    my->prev = a;
    my->next = NULL;
    a->next = my;
}

path path_cpy(path my)
{
    path cpy = initialisation(cpy);
    node *a = my.first;

    while (a->next != NULL) {
        push_back(&cpy, a->y, a->x);
        a = a->next;
    }
    return cpy;
}

void is_solvable_maze(int *i)
{
    *i += 1;
    if (*i == 10000000) {
        printf("no solution found\n");
        exit(0);
    }
}