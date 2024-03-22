/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "solver.h"

char *my_strncpy(char *str, char *src, int n)
{
    int i, j, k;

    for (i = 0; i != n; ++i) {
        str[i] = src[i];
        if (src[i] == '\0') break;
    }
    return str;
}

char *file_reader(char *filepath)
{
    int i = open(filepath, O_RDONLY);
    struct stat my;
    char *str = NULL;

    if (i == -1) return NULL;
    stat(filepath, &my);
    str = malloc(sizeof(char) * (my.st_size + 1));
    read(i, str, my.st_size);
    str[my.st_size] = '\0';
    return str;
}

char **maps_configuration(char *str)
{
    char **plateau = NULL;
    int i = 0, j = 0, k = 0, c = 0;

    for (i = 0; str[i] != '\0'; i += 1)
        if (str[i] == '\n') k += 1;
    plateau = malloc(sizeof(char *) * (k + 1));
    i = 0, k = 0;
    for (i = 0; str[i] != '\0'; i += c) {
        j = i;
        while (str[j] != '\n' && str[j] != '\0') j += 1;
        c = j - i;
        plateau[k] = malloc(sizeof(char) * (c + 1));
        strncpy(plateau[k], &str[i], c);
        plateau[k][c] = '\0';
        k += 1, i += 1;
    }
    plateau[k] = NULL;
    return plateau;
}
