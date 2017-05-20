#include <stdio.h>
#include <stdlib.h>
#include "graph/graph.hpp"
#include "graph/graph_search.hpp"


#define N 10

int main(int argc, char *argv[]){

    graph *g = create_demo_graph();
    int u,v;

    for(u=0; u<9; ++u){
        for(v = 0; v<9; ++v){
            if(reach(g, u, v) == 1){
                printf("%d alcança %d\n", u, v);
            }else{
               printf("%d nao alcança %d\n", u, v);
            }
        }
        printf("\n");
    }
    return 0;
}