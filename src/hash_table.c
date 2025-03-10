/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-gregoire.fageot
** File description:
** hash_table.c
*/

#include "my.h"
#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = 0;
    ht_content_t *new_node = NULL;

    if (!ht || !key || !value) {
        return 84;
    }
    index = ht->hash(key, ht->size) % ht->size;
    new_node = malloc(sizeof(ht_content_t));
    if (!new_node)
        return 84;
    new_node->key = my_strdup(key);
    new_node->value = my_strdup(value);
    new_node->hash_key = ht->hash(key, ht->size);
    new_node->next = ht->content[index];
    ht->content[index] = new_node;
    return 0;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hash_table = malloc(sizeof(hashtable_t));

    if (!hash_table || len <= 0 || !hash)
        return NULL;
    hash_table->size = len;
    hash_table->hash = hash;
    hash_table->content = malloc(sizeof(ht_content_t *) * len);
    if (!hash_table->content) {
        free(hash_table);
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        hash_table->content[i] = NULL;
    }
    return hash_table;
}

void ht_dump(hashtable_t *ht)
{
    ht_content_t *current = NULL;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        my_printf("[%d]:\n", i);
        current = ht->content[i];
        while (current) {
            my_printf(" > %d - %s\n", current->hash_key, current->value);
            current = current->next;
        }
    }
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;
    ht_content_t *current = NULL;

    if (!ht || !key)
        return NULL;
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->content[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}

void delete_hashtable(hashtable_t *ht)
{
    ht_content_t *current = NULL;
    ht_content_t *next = NULL;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->size; i++) {
        current = ht->content[i];
        while (current != NULL) {
            next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }
    }
    free(ht->content);
    free(ht);
}

int ht_delete(hashtable_t *ht, char *key)
{
    if (!ht || !key)
        return 84;
    return 0;
}
