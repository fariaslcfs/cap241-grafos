#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node_{
    struct node_* next;
    int id;
    float weight;
} node;

typedef struct {
    node** nodes;
    size_t size;
} graph;


graph* create_graph(size_t size);
void free_graph(graph* g);

node *create_node(int id, float weight, node* next);
void free_node(node* n);

int insert_edge(graph* g, int n1, int n2, float weight);
int remove_edge(graph* g, int n1, int n2);

int exists_edge(graph* g, int n1, int n2);

node* adjacent_edges(graph* g, int n);

void print_graph(graph* g);

graph* create_demo_graph();

#endif /* __GRAPH_H__ */