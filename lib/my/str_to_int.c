/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-gregoire.fageot
** File description:
** str_to_int.c
*/

#include <stdbool.h>
#include "../../include/my.h"
#include "../../include/hashtable.h"

static int convert_to_reversed_string(int num, char *buffer)
{
    int i = 0;
    int digit = 0;

    do {
        digit = num % 10;
        buffer[i] = digit + '0';
        i++;
        num /= 10;
    } while (num > 0);
    return i;
}

static void add_negative_sign(char *buffer, int *length, bool is_negative)
{
    if (is_negative) {
        buffer[*length] = '-';
        (*length)++;
    }
}

static void reverse_string(char *buffer, int length)
{
    int start = 0;
    int end = length - 1;
    char temp = buffer[start];

    while (start < end) {
        temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }
}

void int_to_str(int num, char *buffer)
{
    int is_neg = 0;
    int length = 0;

    if (num < 0)
        is_neg = 1;
    if (is_neg) {
        num = -num;
    }
    length = convert_to_reversed_string(num, buffer);
    add_negative_sign(buffer, &length, is_neg);
    buffer[length] = '\0';
    reverse_string(buffer, length);
}
