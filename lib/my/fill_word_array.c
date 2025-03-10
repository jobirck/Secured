/*
** EPITECH PROJECT, 2024
** fill_word_array
** File description:
** fill word array (my str to word array)
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/struct_word_array.h"

void process(const char *str, word_array_t *word_array, int start, int end)
{
    if (end > start) {
        word_array->tab[word_array->index] = copy_word(str, start, end);
        if (word_array->tab[word_array->index] == NULL) {
            return;
        }
        word_array->index++;
    }
}

void fill_word_array(char const *str, word_array_t *word_array)
{
    int start = 0;
    int len = my_strlen(str);
    int end;

    for (int i = 0; i < len; i++) {
        if (str[i] == '\n' || i == len - 1) {
            end = (str[i] == '\n') ? i : i + 1;
            process(str, word_array, start, end);
            start = i + 1;
        }
    }
    word_array->tab[word_array->index] = NULL;
}
