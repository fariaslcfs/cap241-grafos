#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>

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

    size_t getSize() { return this->size; };
    Node* getNode(int i) { return this->nodes[i]; };

    private:
    size_t size;
    Node** nodes;
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
        std::cout << "#" << i << " ";
        if(this->nodes[i] != NULL){
            for(n = this->nodes[i]; n!=NULL; n=n->getNext()){
                std::cout << n->getId() << "(" << n->getWeight() << ") ";
            }
        }
        std::cout << std::endl;
    }
}


/*
Funções legadas da implementação em C
*/
#include "graph_legacy.h"

#endif /* __GRAPH_H__ */