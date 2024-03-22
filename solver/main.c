/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "solver.h"

node *is_goal(graph *tree, node final)
{
    graph *my = tree;
    node *a = NULL;
    while (my->next != NULL) {
        a = my->op.first;
        while (a->next->next != NULL) a = a->next;
        if (a->y == final.y && a->x == final.x)
            return my->op.first;
        my = my->next;
    }
    return NULL;
}

void path_searcher(char **maps, node final)
{
    node *solution = NULL, *nd = NULL;
    graph *n = malloc(sizeof(graph)), *stock = NULL;
    path a = initialisation(a);
    push_back(&a, 0, 0), tree_init(n);
    int i = 0;

    maps[0][0] = '#';
    tree_branche_creation(a, n, maps);
    while (solution == NULL) {
        stock = n;
        solution = is_goal(n, final);
        n = tree_evolution(n, maps);
        if (solution == NULL) tree_slaughter(stock);
        is_solvable_maze(&i);
    } while (solution->next != NULL) {
        nd = solution;
        maps[solution->y][solution->x] = 'o';
        solution = solution->next;
        free(nd);
    } free(solution);
    tree_slaughter(n);
    list_deleter(a);
}

node goal_id(char **maps)
{
    int i = strlen(maps[0]);
    int y = 0;
    node ob;

    while (maps[y] != NULL) y += 1;
    ob.y = y - 1;
    ob.x = i - 1;
    return ob;
}

void map_cleaner(char **map, char c)
{
    int x = 0, y = 0;

    while (map[y] != NULL) {
        for (x = 0; map[y][x] != '\0'; x += 1)
            map[y][x] = map[y][x] == c ? '*' : map[y][x];
        y += 1;
    }
}

int main(int ac, char **av)
{
    int i = 0, k = 0;
    char *str = file_reader(av[1]);
    if (str == NULL || strlen(str) == 0) return 84;
    if (is_correct_maps(str) == 84) return 84;
    char **maps = maps_configuration(str);
    node goal = goal_id(maps);
    path_searcher(maps, goal);
    map_cleaner(maps, '#');
    while (maps[k] != NULL) {
        write(1, maps[k], goal.x + 1);
        k += 1;
        if (maps[k] != NULL) write(1, "\n", 1);
    }
    arr_2d_deleter(maps);
}
