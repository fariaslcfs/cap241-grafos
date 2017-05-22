#ifndef __GRAPH_LEGACY_H__
#define __GRAPH_LEGACY_H__

Graph* create_graph(size_t size);
void free_graph(Graph* g);
Node *create_node(int id, float weight, Node *next);
void free_node(Node* n);
int insert_edge(Graph* g, int n1, int n2, float weight);
int remove_edge(Graph* g, int n1, int n2);
int exists_edge(Graph* g, int n1, int n2);
Node *adjacent_edges(Graph* g, int n);
void print_graph(Graph* g);
Graph* create_demo_graph();

Graph *create_graph(size_t size){
    Graph* g = new Graph(size);
    return g;
}

void free_graph(Graph* g){
   delete g;
}

Node *create_node(int id, float weight, Node* next){
    Node *n = new Node(id, weight, next);
    return n;
}

void free_node(Node* n){
    if(n != NULL){
        delete n;
    }
}

int insert_edge(Graph* g, int n1, int n2, float weight){
    return g->insertEdge(n1, n2, weight);
}

int remove_edge(Graph* g, int n1, int n2) {
    return g->removeEdge(n1, n2);
}

int exists_edge(Graph* g, int n1, int n2){
    return g->existsEdge(n1, n2);
}

Node* adjacent_edges(Graph* g, int n){
    return g->adjacentEdges(n);
}

void print_graph(Graph* g){
    g->print();
}

Graph* create_demo_graph(){
    Graph *g = create_graph(9);
    
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

#endif