#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TABLESIZE 20000


typedef struct node
{
    char *data;
    struct node *next;
} node;

unsigned int hash (const char *str)
{
    unsigned int hash = 0;
    for (int i = 0 ; str[i] != '\0' ; i++)
    {
        hash = 31*hash + str[i];
    }
    return hash % TABLESIZE;
}


static int lookup(node *table[], const char *key)
{
    unsigned index = hash(key);
    const node *it = table[index];
    while(it != NULL && strcmp(it->data, key) != 0)
    {
        it = it->next;
    }
    return it != NULL;
}

int insert(node *table[], char *key)
{
    if( !lookup(table, key) )
    {
        unsigned index = hash(key);
        node *new_node = (node*)malloc(sizeof *new_node);

        if(new_node == NULL)
            return 0;

        new_node->data = malloc((strlen(key)+1)*sizeof(char));

        if(new_node->data == NULL)
            return 0;

        strcpy(new_node->data, key);
        new_node->next = table[index];
        table[index] = new_node;
        return 1;
    }
    return 0;
}

int delete(node *table[],char* key)
{
    if(lookup(table,key)) {
        unsigned int index = hash(key);
        node *it = table[index];
        node *prev = NULL;
        while (strcmp(it->data, key) != 0) {
            prev = it;
            it = it->next;
        }
        if (prev) {
            prev->next = it->next;
        } else { table[index] = it->next; }
    }
    return 0;
}

int main() {
    node *table[TABLESIZE] = {0};
    char value[10000] = {0};
    char command = '0';
    while (scanf("%c",&command)>0) {

        if (command == 'a') {
            scanf("%s",&value);
            insert(table, value);
        }
        if (command == 'f') {
            scanf("%s",&value);
            if (lookup(table, value)) {
                printf("%s", "yes\n");
            } else { printf("%s", "no\n"); }
        }
        if (command == 'r'){
            scanf("%s",&value);
            delete(table,value);
        }
    }
}
