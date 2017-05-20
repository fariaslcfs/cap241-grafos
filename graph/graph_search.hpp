#ifndef __GRAPH_SEARCH_H__
#define __GRAPH_SEARCH_H__

#include "graph.hpp"

int reach(graph *g, int u, int v);

/* Retorna um vetor de tamanho g->size com os tempos de varredura do nó em relação ao nó u */
int *dfs(graph *g, int u);


/* Retorna um vetor de tamanho g->size com a distancia que cada nó está de u */
int *bfs(graph *g, int u);

#endif /* __GRAPH_SEARCH_H__*/