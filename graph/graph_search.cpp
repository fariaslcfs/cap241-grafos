#include "graph_search.hpp"

// funcao auxiliar de reach
int __reach(graph *g, int u, int v, int* visited);


int reach(graph *g, int u, int v){
    Node *w;
    int *visited;
    size_t i;
    
    visited = (int*) malloc(sizeof(int)*g->size);
    for(i=0; i<g->size; ++i){
        visited[i] = 0;
    }
    visited[u] = 1;

    for(w = g->nodes[u]; w != NULL; w = w->next){
        if(__reach(g, w->id, v, visited) == 1){
            free(visited);
            return 1;
        }
    }
    free(visited);
    return 0;
}

int __reach(graph *g, int u, int v, int* visited){
    Node *w;
    visited[u] = 1;

    if(u == v){
        return 1;
    }
    
    for(w = g->nodes[u]; w != NULL; w = w->next){
        if(visited[w->id] == 0){
            if(w != NULL){
                if(__reach(g, w->id, v, visited) == 1 ){
                    return 1;
                }
            }
        }
    }
    return 0;
}

// funcao auxiliar de dfs
void __dfs(graph *g, int u, int *visited, int *count);

int *dfs(graph *g, int u){
    Node *w;
    int *visited;
    size_t i;
    int count = 0;
    
    visited = (int*) malloc(sizeof(int)*g->size);
    for(i=0; i<g->size; ++i){
        visited[i] = -1;
    }
    visited[u] = count++;

    for(w = g->nodes[u]; w != NULL; w = w->next){

        if(visited[w->id] == -1) {
            //print_graph(g);
            __dfs(g, w->id, visited, &count);

        }
    }
    return visited;
}

void __dfs(graph *g, int u, int* visited, int *count){
    Node *w;
    visited[u] = (*count);
    *count = (*count)+1;

    for(w = g->nodes[u]; w != NULL; w = w->next){
        if(visited[w->id] == -1){

            if(w != NULL){
                __dfs(g, w->id, visited, count);
            }
        }
    }
}


typedef struct {
    int content[1000];
    size_t start;
    size_t end;
} queue;


queue* queue_create(){
    queue *q = (queue*) malloc(sizeof(queue));
    q->start = 0;
    q->end = 0;
    return q;
}

void queue_destroy(queue* q){
    free(q);
}

size_t queue_size(queue *q){
    return q->end - q->start;
}

void queue_insert(queue *q, int v){
    q->content[q->end] = v;
    q->end++;
}

int queue_remove(queue *q){
    q->start++;
    return q->content[q->start-1];
}


int *bfs(graph *g, int u){
    int *visited;
    size_t i;
    int count = 0;
    int v;
    Node *w;
    queue* q = queue_create();
    visited = (int*) malloc(sizeof(int)*g->size);
    for(i=0; i<g->size; ++i){
        visited[i] = -1;
    }
    visited[u]= count++;
    queue_insert(q, u);
    while(queue_size(q) > 0){
        v = queue_remove(q);
        count = visited[v];
        for(w=g->nodes[v]; w != NULL; w = w->next){
            if (visited[w->id] == -1){
                visited[w->id] = count + 1;
                queue_insert(q, w->id);
            }
        }
    }
    return visited;
}