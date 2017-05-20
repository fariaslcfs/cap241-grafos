#include <stdio.h>
#include <stdlib.h>
#include "graph/graph.hpp"
#include "graph/graph_search.hpp"

#define N 10

int main(int argc, char *argv[]){
    size_t i, j;
    graph *g = create_demo_graph();
    int *vet;
    
    for(i=0; i<g->size; ++i){
        printf("A partir do %d\n", (int)i);
        vet = bfs(g, i);
        for(j=0; j<g->size; ++j){
            printf("#%d: %d\n", (int)j, vet[j]);
        }
        free(vet);
        printf("\n\n");
    }

    return 0;
}