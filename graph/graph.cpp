#include "graph.hpp"

Graph::Graph(size_t _size) {
    size = _size;
    nodes = (Node**) malloc(sizeof(Node*)*size);
    for(size_t i = 0; i < size; ++i){
        nodes[i] = NULL;
    }
}

Graph *create_graph(size_t size){
    Graph* g = new Graph(size);
    return g;
}

Graph::~Graph() {
    for (size_t i = 0; i < this->size; i++) {
        delete this->nodes[i];
    }
}

void free_graph(Graph* g){
   delete g;
}

Node::Node(int _id, float _weight, Node *_next) {
    id = _id;
    weight = _weight;
    next = _next;
}

Node *create_node(int id, float weight, Node* next){
    Node *n = new Node(id, weight, next);
    return n;
}

Node::~Node() {
    if (this->next) {
        delete this->next;
    }
}

void free_node(Node* n){
    if(n != NULL){
        delete n;
    }
}

int Graph::insertEdge(int n1, int n2, float weight) {
    Node* n;
    Node* w;
    if(exists_edge(this, n1, n2) == 0) {
        if(n1 < this->size && n2 < this->size) {
        
            // essa solução tem maior custo, mas os vérticies aparecem na ordem de inserção. 
            // a solução comentada abaixo é mais simples, mas os vertices ficam na ordem reversa.
            n = create_node(n2, weight, NULL);
            if(this->nodes[n1] == NULL){
                this->nodes[n1] = n;
            }else{
                for(w=this->nodes[n1]; w->next != NULL; w = w->next);
                w->next = n;
            }
            /*
            n = create_node(n2, weight, this->nodes[n1]);
            this->nodes[n1] = n;
            */
        }
        return 1;
    }
    return 0;
}

int insert_edge(Graph* g, int n1, int n2, float weight){
    return g->insertEdge(n1, n2, weight);
}

int Graph::removeEdge(int n1, int n2) {
    Node* n;
    Node* prev = NULL;
    for(n=this->nodes[n1]; n!= NULL; n= n->next){
        if(n->id == n2) {
            if(prev == NULL){
                this->nodes[n1] = n->next;
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

int remove_edge(Graph* g, int n1, int n2) {
    return g->removeEdge(n1, n2);
}

int Graph::existsEdge(int n1, int n2) {
    Node* n;
    if(n1 < this->size && n2 < this->size) {
        for(n = this->nodes[n1]; n!=NULL; n = n->next){
             if(n->id == n2){
                return 1;
            }
        }
    }
    return 0;
}

int exists_edge(Graph* g, int n1, int n2){
    return g->existsEdge(n1, n2);
}

Node *Graph::adjacentEdges(int n) {
    if(n < this->size) {
        return this->nodes[n];
    }
    return NULL;
}

Node* adjacent_edges(Graph* g, int n){
    return g->adjacentEdges(n);
}

void Graph::print() {
    int i;
    Node* n;
    for(i=0; i<this->size; ++i){
        if(this->nodes[i] != NULL){
            printf("#%d: ", i);
            for(n = this->nodes[i]; n!=NULL; n=n->next){
                       printf("%d(%.2f) ", n->id, n->weight);
            }
            printf("\n");
        }
    }
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