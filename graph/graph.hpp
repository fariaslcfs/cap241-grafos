#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

class Node 
{
    public:
    Node *next;
    int id;
    float weight;
};

typedef struct {
    Node** nodes;
    size_t size;
} graph;


graph* create_graph(size_t size);
void free_graph(graph* g);

Node *create_node(int id, float weight, Node *next);
void free_node(Node* n);

int insert_edge(graph* g, int n1, int n2, float weight);
int remove_edge(graph* g, int n1, int n2);

int exists_edge(graph* g, int n1, int n2);

Node *adjacent_edges(graph* g, int n);

void print_graph(graph* g);

graph* create_demo_graph();

#endif /* __GRAPH_H__ */