#include "graph.h"

t_graph *create_graph(int v)
{
    t_graph *graph;
    int i = 0;

    graph = malloc(sizeof(*graph));
    graph->v = v;

    graph->array = malloc(sizeof(t_list) * v);

    while (i < v)
    {
        graph->array[i].head = NULL;
        i++;
    }
    return graph;
}

t_node *new_node(int dest, t_bunny_position pos)
{
    t_node *node;

    node = malloc(sizeof(*node));
    node->dest = dest;
    node->pos = pos;
    node->next = NULL;
    return node;
}

void add(t_graph *graph, int src, int dest, t_bunny_position pos)
{
    t_node *check = NULL;
    t_node *node = new_node(dest, pos);

    if (graph->array[src].head == NULL)
    {
        node->next = graph->array[src].head;
        graph->array[src].head = node;
    }
    else
    {

        check = graph->array[src].head;
        while (check->next != NULL)
            check = check->next;
        check->next = node;
    }

    node = new_node(src, pos);
    if (graph->array[dest].head == NULL)
    {
        node->next = graph->array[dest].head;
        graph->array[dest].head = node;
    }
    else
    {
        check = graph->array[dest].head;
        while (check->next != NULL)
            check = check->next;
        check->next = node;
    }
}

void free_graph(t_graph *graph)
{
    int i;
    i = 1;
    while (i < graph->v)
    {
        t_node *node_temp;
        t_node *node = graph->array[i].head;
        while (node != NULL)
        {
            node_temp = node;
            free(node_temp);
            node_temp = NULL;
            node = node->next;
        }
        i++;
    }
    free(graph->array);
    graph->array = NULL;
}