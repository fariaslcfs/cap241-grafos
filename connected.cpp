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
    Graph *g = demo::fully_connected_9nodes_9edges();
    
    std::cout << "\nExemplo de grafo totalmente conectado (1 componente):" << std::endl;
    print_components(g);
    delete g;

    g = demo::disconnected_3components_9nodes_6edges();
    std::cout << "\nExemplo de grafo com 3 componentes:" << std::endl;
    print_components(g);
    delete g;

    return 0;
}