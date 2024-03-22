/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** header
*/

#ifndef SOLVER_H_
    #define SOLVER_H_
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

typedef struct node {
    int y;
    int x;
    struct node *next;
}node;

typedef struct {
    int length;
    node *first;
    node *last;
}path;

typedef struct option {
    path op;
    struct option *prev;
    struct option *next;
}graph;

typedef struct no {
    int n;
    struct no *next;
} no;

typedef struct {
    no *first;
    no *last;
} no_list;

typedef struct n_gird {
    no_list gird;
    struct n_gird *next;
}n_gird;

typedef struct {
    n_gird *first;
    n_gird *last;
}strct_ctrl1;

char *my_strncpy(char *str, char *src, int n);
char *file_reader(char *filepath);
char **maps_configuration(char *str);
path initialisation(path my);
void push_back(path *my, int y, int x);
void tree_init(graph *my);
void branches_adding(graph *tree, path branche);
path path_cpy(path my);
void open_list_charger(int y, int x, char **maps, path *open_list);
void tree_branche_creation(path op, graph *new, char **maps);
graph *tree_evolution(graph *tree, char **maps);
node *is_goal(graph *tree, node final);
void path_searcher(char **maps, node final);
node goal_id(char **maps);
void map_cleaner(char **map, char c);
void list_deleter(path my);
void tree_slaughter(graph *tree);
void arr_2d_deleter(char **map);
void is_solvable_maze(int *i);
int is_correct_maps(char *str);

#endif
