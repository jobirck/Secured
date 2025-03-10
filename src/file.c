/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-gregoire.fageot
** File description:
** file.c
*/

#include "my.h"
#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

int my_len(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

static int calculate_total_length(char *str)
{
    int total_len = 0;
    int ascii_len = 0;
    int ascii_val = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        ascii_len = 1;
        ascii_val = (int)str[i];
        while (ascii_val > 0) {
            ascii_val /= 10;
            ascii_len++;
        }
        total_len += ascii_len;
    }
    return total_len;
}

int str_to_ascii(char *str)
{
    int total_len = 0;
    char *ascii_str = NULL;
    char buffer[6];
    int result;

    if (!str)
        return 0;
    total_len = calculate_total_length(str);
    ascii_str = malloc(sizeof(char) * (total_len + 1));
    if (!ascii_str)
        return 0;
    ascii_str[0] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        int_to_str((int)str[i], buffer);
        my_strcat(ascii_str, buffer);
    }
    result = str_to_digit(ascii_str);
    free(ascii_str);
    return result;
}
