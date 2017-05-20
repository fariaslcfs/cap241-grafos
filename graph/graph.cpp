#include "graph.hpp"

graph* create_graph(size_t size){
    size_t i;
    graph* g = (graph*) malloc(sizeof(graph));
    g->size = size;
    g->nodes = (node**) malloc(sizeof(node*)*size);
    for(i=0; i<size; ++i){
        g->nodes[i] = NULL;
    }
    return g;
}

void free_graph(graph* g){
   
}

node *create_node(int id, float weight, node* next){
    node* n = (node*) malloc(sizeof(node));
    n->id = id;
    n->weight = weight;
    n->next = next;
    return n;
}

void free_node(node* n){
    if(n != NULL){
        free(n);
    }
}

int insert_edge(graph* g, int n1, int n2, float weight){
    node* n;
    node* w;
    if(exists_edge(g, n1, n2) == 0) {
        if(n1 < g->size && n2 < g->size) {
        
            // essa solução tem maior custo, mas os vérticies aparecem na ordem de inserção. 
            // a solução comentada abaixo é mais simples, mas os vertices ficam na ordem reversa.
            n = create_node(n2, weight, NULL);
            if(g->nodes[n1] == NULL){
                g->nodes[n1] = n;
            }else{
                for(w=g->nodes[n1]; w->next != NULL; w = w->next);
                w->next = n;
            }
            /*
            n = create_node(n2, weight, g->nodes[n1]);
            g->nodes[n1] = n;
            */
        }
        return 1;
    }
    return 0;
}
int remove_edge(graph* g, int n1, int n2){
    node* n;
    node* prev = NULL;
    for(n=g->nodes[n1]; n!= NULL; n= n->next){
        if(n->id == n2) {
            if(prev == NULL){
                g->nodes[n1] = n->next;
            }else{
                prev->next = n->next;
            }
            free_node(n);
            return 1;
        }
        prev = n;
    }
    return 0;
}

int exists_edge(graph* g, int n1, int n2){
    node* n;
    if(n1 < g->size && n2 < g->size) {
        for(n = g->nodes[n1]; n!=NULL; n = n->next){
             if(n->id == n2){
                return 1;
            }
        }
    }
    return 0;
}

node* adjacent_edges(graph* g, int n){
    if(n < g->size) {
        return g->nodes[n];
    }
    return NULL;
}

void print_graph(graph* g){
    int i;
    node* n;
    for(i=0; i<g->size; ++i){
        if(g->nodes[i] != NULL){
            printf("#%d: ", i);
            for(n = g->nodes[i]; n!=NULL; n=n->next){
                       printf("%d(%.2f) ", n->id, n->weight);
            }
            printf("\n");
        }
    }
}

graph* create_demo_graph(){
    graph *g = create_graph(9);
    
    insert_edge(g, 0, 1, 1.);
    insert_edge(g, 1, 2, 1.);
    insert_edge(g, 2, 3, 1.);
    insert_edge(g, 1, 4, 1.);
    insert_edge(g, 4, 5, 1.);
    insert_edge(g, 0, 5, 1.);
    insert_edge(g, 0, 6, 1.);
    insert_edge(g, 6, 7, 1.);
    insert_edge(g, 6, 8, 1.);
    
    return g;
}