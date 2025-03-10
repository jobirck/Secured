/*
** EPITECH PROJECT, 2024
** my_isalnum
** File description:
** savoir si un caractere est alphanumerique  ou non
*/

#include "../../include/my.h"

int is_alnum(char c)
{
    return (c >= '0' && c <= '9');
}
