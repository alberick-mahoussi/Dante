/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int d = 0;
    while (s1[i] != 0 && s2[i] != 0) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
