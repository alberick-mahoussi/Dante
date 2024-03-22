/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "solver.h"

path initialisation(path my)
{
    node *a = malloc(sizeof(node));

    a->x = 0;
    a->y = 0;
    a->next = NULL;
    my.first = a;
    my.last = a;
    my.length = 0;
    return my;
}

void push_back(path *my, int y, int x)
{
    my->last->y = y;
    my->last->x = x;
    my->last->next = malloc(sizeof(node));
    my->last = my->last->next;
    my->last->y = 0;
    my->last->x = 0;
    my->last->next = NULL;
    my->length += 1;
}

void open_list_charger(int y, int x, char **maps,
path *open_list)
{
    if (y != 0 && maps[y - 1] [x] == '*') {
        push_back(open_list, (y - 1), x);
        maps[y - 1][x] = '#';
    } if (maps[y + 1] != NULL && maps[y + 1][x] == '*') {
        push_back(open_list, (y + 1), x);
        maps[y + 1][x] = '#';
    } if (x != 0 && maps[y][x - 1] == '*') {
        push_back(open_list, y, (x - 1));
        maps[y][x - 1] = '#';
    } if (maps[y][x + 1] == '*') {
        push_back(open_list, y, (x + 1));
        maps[y][x + 1] = '#';
    }
}

void tree_branche_creation(path op, graph *new, char **maps)
{
    path open_list = initialisation(open_list);
    node *step = open_list.first;
    path cpy;
    node *a = op.first;

    while (a->next->next != NULL) a = a->next;
    open_list_charger(a->y, a->x, maps, &open_list);
    while (step->next != NULL) {
        cpy = path_cpy(op);
        push_back(&cpy, step->y, step->x);
        branches_adding(new, cpy);
        step = step->next;
    }
}

graph *tree_evolution(graph *tree, char **maps)
{
    graph *old = tree;
    graph *update = malloc(sizeof(graph));
    tree_init(update);

    while (old->next != NULL) {
        tree_branche_creation(old->op, update, maps);
        old = old->next;
    }
    return update;
}
