/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-gregoire.fageot
** File description:
** hash_func.c
*/

#include "my.h"
#include "hashtable.h"

int hash(char *key, int len)
{
    unsigned long hash = 0;
    int key_len = my_strlen(key);

    for (int i = 0; i < key_len; i++) {
        hash = (hash << 4) ^ (hash >> 28) ^ key[i];
    }
    return (int)(hash + len) > 0 ? (int)(hash + len) : -(int)(hash +len);
}
