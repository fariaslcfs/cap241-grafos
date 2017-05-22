#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "node.hpp"

class Graph {
    public:
    Graph(size_t size);
    ~Graph();
    int insertEdge(int n1, int n2, float weight);
    int removeEdge(int n1, int n2);
    int existsEdge(int n1, int n2);
    Node *adjacentEdges(int n);
    void print();

    Node** nodes;
    size_t size;
};

Graph::Graph(size_t size) {
    this->size = size;
    nodes = (Node**) malloc(sizeof(Node*)*this->size);
    for(size_t i = 0; i < this->size; ++i){
        nodes[i] = NULL;
    }
}

Graph::~Graph() {
    for (size_t i = 0; i < this->size; i++) {
        delete this->nodes[i];
    }
}

int Graph::insertEdge(int n1, int n2, float weight) {
    Node* n;
    Node* w;
    if(this->existsEdge(n1, n2) == 0) {
        if(n1 < this->size && n2 < this->size) {
        
            // essa solução tem maior custo, mas os vérticies aparecem na ordem de inserção. 
            // a solução comentada abaixo é mais simples, mas os vertices ficam na ordem reversa.
            n = new Node(n2, weight, NULL);
            if(this->nodes[n1] == NULL){
                this->nodes[n1] = n;
            }else{
                for(w=this->nodes[n1]; w->getNext() != NULL; w = w->getNext());
                w->setNext(n);
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

int Graph::removeEdge(int n1, int n2) {
    Node* n;
    Node* prev = NULL;
    for(n=this->nodes[n1]; n!= NULL; n= n->getNext()){
        if(n->getId() == n2) {
            if(prev == NULL){
                this->nodes[n1] = n->getNext();
            }else{
                prev->setNext(n->getNext());
            }
            n->setNext(NULL);
            delete n;
            return 1;
        }
        prev = n;
    }
    return 0;
}

int Graph::existsEdge(int n1, int n2) {
    Node* n;
    if(n1 < this->size && n2 < this->size) {
        for(n = this->nodes[n1]; n!=NULL; n = n->getNext()){
             if(n->getId() == n2){
                return 1;
            }
        }
    }
    return 0;
}

Node *Graph::adjacentEdges(int n) {
    if(n < this->size) {
        return this->nodes[n];
    }
    return NULL;
}

void Graph::print() {
    int i;
    Node* n;
    for(i=0; i<this->size; ++i){
        if(this->nodes[i] != NULL){
            printf("#%d: ", i);
            for(n = this->nodes[i]; n!=NULL; n=n->getNext()){
                       printf("%d(%.2f) ", n->getId(), n->getWeight());
            }
            printf("\n");
        }
    }
}

/*
Funções legadas da implementação em C
*/

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

#endif /* __GRAPH_H__ */