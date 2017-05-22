#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <vector>


typedef struct node_
{
    struct node_* next;
    size_t id;
    float weight;
} node;

typedef struct
{
    node **nodes;
    size_t size;
} graph;


graph * create_graph(size_t size);
void free_graph(graph *);

node *create_node(size_t, float, node *);
void free_node(node *);

size_t insert_edge(graph *, size_t, size_t, float weight);
size_t remove_edge(graph *, size_t, size_t);

size_t exists_edge(graph * g, size_t, size_t);

node* adjacent_edges(graph *, size_t);

void prsize_t_graph(graph *);

graph* create_demo_graph();

bool has_Cicle(graph *);

#endif /* __GRAPH_H__ */
