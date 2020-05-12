// Copyright 2020 Boris Ivanovic - see LICENSE

#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    struct node_ *next;
    char          data;
} node_t;

node_t *list_create_node(char data)
{
    node_t *node = malloc(sizeof(node_t));
    node->next = 0;
    node->data = data;
    
    return node;
}

void list_destroy(node_t *node)
{
    while(node)
    {
        node_t *temp=node;
        node = node->next;
        free(temp);
    }
}

node_t *list_make(char *pstr)
{
    node_t *head = 0;
    node_t *prev = 0;

    for(;*pstr;pstr++)
    {
        node_t *node = list_create_node(*pstr);
        
        if(prev)
        {
            prev->next = node;
        }
        else
        {
            head = node;
        }
        
        prev = node;
    }
    
    return head;
}

void list_print(node_t *node)
{
    printf("List: ");

    while(node)
    {
        printf("%c -> ",node->data);
        node = node->next;
    }
    
    printf("(end)\n");
}

node_t *list_reverse(node_t *node)
{
    node_t *prev = 0;
    
    while(node)
    {
        node_t *temp = node->next;
        node->next = prev;
        
        prev = node;
        node = temp;
    }
    
    return prev;
}

int main(void)
{
    node_t *node = list_make("Orange!");
    list_print(node);

    node = list_reverse(node);
    list_print(node);
    
    list_destroy(node);
    
    return 0;
}

