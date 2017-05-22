#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "graph/graph.hpp"
#include "graph/graph_topological.hpp"

void topo_order(graph *g, size_t i, std::vector<bool> &visited, std::stack<size_t> &topo){
    if (! visited[i]) { //Se o vértice ainda não foi visitado
        visited[i] = true; //marque-o como visitado
        if (g->nodes[i] != NULL) { // e se houverem vértices adjascentes
            node *n = g->nodes[i];
            while (n != NULL)
            {
                topo_order(g, n->id, visited, topo); //realize a ordenação topológica para os vértices adjascentes primeiro
                n = n->next; //próximo vértice adjacente
            }
        }
        //Caso não haja mais adjacentes adicione o vértice atual a ordenação topológica
        topo.push(i);
    }
}

/*
Realiza a ordenação topológica usando um algoritmo de busca em profundidade recursivo.
*/
std::stack<size_t> graph_topological_order(graph *g) {
    std::vector<bool> visited; //Vértices já visitados.
    std::stack<size_t> topo; //Pilha com a ordenação topológica
    visited.resize(g->size, false); //Inicializa o vetor de vértices visitados com false

    /*
    Para cada vértice da lista de adjacências...
    */
    for (size_t i = 0; i < g->size; ++i) {
        topo_order(g, i, visited, topo);
    }
    return topo;
}


void __topo()
{

    graph *g = create_graph(8);
    
    insert_edge(g, 0, 1, 1.);
    insert_edge(g, 2, 6, 1.);
    insert_edge(g, 4, 6, 1.);

    std::stack<size_t> t = graph_topological_order(g);

    while (!t.empty())
    {
        std::cout << t.top() << " ";
        t.pop();
    }
    std::cout << std::endl;


}
