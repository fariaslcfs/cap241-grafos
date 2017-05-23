#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include "demo_graphs.hpp"

#include <string>
#include <iostream>

int main(){

    std::cout << std::endl << " --- Exemplo 1 - Grafo Acíclico com 4 Vértices --- " << std::endl;
    Graph *g = demo::acyclic_4nodes();
    std::cout << g->getPrettyPrint();
    std::cout << "is_cyclic: " << graph_is_cyclic(g) << std::endl << std::endl;
    delete g;

    std::cout << std::endl << " --- Exemplo 2 - Grafo Cíclico com 4 Vértices --- " << std::endl;
    g = demo::cyclic_4nodes();
    std::cout << g->getPrettyPrint();
    std::cout << "is_cyclic: " << graph_is_cyclic(g) << std::endl << std::endl;
    delete g;

    std::cout << std::endl << " --- Exemplo 3 - Grafo Cíclico com 2 Vértices --- " << std::endl;
    g = demo::cyclic_2nodes();
    std::cout << g->getPrettyPrint();
    std::cout << "is_cyclic: " << graph_is_cyclic(g) << std::endl << std::endl;
    delete g;

    std::cout << std::endl << " --- Exemplo 4 - Grafo Cíclico com 1 Vértice --- " << std::endl;
    g = demo::cyclic_1node();
    std::cout << g->getPrettyPrint();
    std::cout << "is_cyclic: " << graph_is_cyclic(g) << std::endl << std::endl;
    delete g;
    
    return 0;
}