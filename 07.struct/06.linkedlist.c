#include <stdlib.h>
#include "./include/io_utils.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));
    if (!node)
        exit(1);
    node->value = value;
    node->next = NULL;
    return node;
}

void destroy_node(Node **node_ptr)
{
    (*node_ptr)->next = NULL;
    free(*node_ptr);
    *node_ptr = NULL;
}

Node *create_list(int array[], int len)
{
    if (len <= 0)
        return NULL;

    Node *head = create_node(array[0]);
    Node *cur = head;
    for (int i = 1; i < len; i++)
    {
        cur->next = create_node(array[i]);
        cur = cur->next;
    }

    return head;
}

void destroy_list(Node **head)
{
    if (!head || !(*head))
        return;

    Node *cur = *head;
    while (cur)
    {
        Node *to_be_destroy = cur;
        cur = cur->next;
        destroy_node(&to_be_destroy);
    }
    *head = NULL;
}

void insert_node(Node **head, int value, int index)
{
    if (!head || index < 0)
        return;

    Node *new_node = create_node(value);
    if (index == 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        if (!(*head))
        {
            *head = create_node(0);
        }
        Node *cur = *head;
        while (index > 1)
        {
            if (cur->next)
            {
                cur->next = create_node(0);
            }
            cur = cur->next;
            index--;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }
}

void print_list(Node *head)
{
    while (head)
    {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(void)
{
    int array[] = {0, 1, 2, 3, 4};
    Node *head = create_list(array, 5);
    print_list(head);
    destroy_list(&head);

    PRINT_HEX(head);
    return 0;
}