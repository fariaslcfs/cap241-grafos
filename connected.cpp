#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include "demo_graphs.hpp"

#include <iostream>

void print_components(Graph *g) {
    std::vector<std::vector<int>> components = graph_connected_components(g);

    for (int c = 0; c < components.size(); ++c) {
        std::cout << "Componente " << c << ":" << std::endl << "{";
        auto component = components[c];
        for (int n = 0; n < component.size(); ++n) {
            std::cout << component[n];
            if (n < component.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
}

int main(){
    std::cout << std::endl << " --- Exemplo 1 - Grafo com 2 componentes ---" << std::endl << std::endl;
    Graph *g = demo::acyclic_4nodes2components();
    std::cout << g->getPrettyPrint() << std::endl;
    print_components(g);
    delete g;

    std::cout << std::endl << " --- Exemplo 2 - Grafo com 1 componentes ---" << std::endl << std::endl;
    g = demo::acyclic_4nodes();
    std::cout << g->getPrettyPrint() << std::endl;
    print_components(g);
    delete g;

    return 0;
}