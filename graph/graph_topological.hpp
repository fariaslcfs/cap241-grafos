#ifndef __GRAPH_TOPOLOGICAL_H__
#define __GRAPH_TOPOLOGICAL_H__

#include <vector>
#include <stack>
#include <iostream>

void topo_order(Graph *g, int i, std::vector<bool> &visited, std::stack<int> &topo) {
    if (! visited[i]) { //Se o vértice ainda não foi visitado
        visited[i] = true; //marque-o como visitado
        if (g->getNode(i) != NULL) { // e se houverem vértices adjascentes
            Node *n = g->getNode(i);
            while (n != NULL) {
                topo_order(g, n->getId(), visited, topo); //realize a ordenação topológica para os vértices adjascentes primeiro
                n = n->getNext(); //próximo vértice adjacente
            }
        }
        //Caso não haja mais adjacentes adicione o vértice atual a ordenação topológica
        topo.push(i);
    }
}

/*
Realiza a ordenação topológica usando um algoritmo de busca em profundidade recursivo.
*/
std::stack<int> graph_topological_order(Graph *g) {
    std::vector<bool> visited; //Vértices já visitados.
    std::stack<int> topo; //Pilha com a ordenação topológica
    visited.resize(g->getSize(), false); //Inicializa o vetor de vértices visitados com false

    /*
    Para cada vértice da lista de adjacências...
    */
    for (int i = 0; i < g->getSize(); ++i) {
        topo_order(g, i, visited, topo);
    }
    return topo;
}

#endif //__GRAPH_TOPOLOGICAL_H__