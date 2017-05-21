#include "graph/graph.hpp"
#include "graph/graph_connected.hpp"

#include <iostream>

graph* graph_fully_connected() {
    graph *g = create_graph(9);
    
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

graph* graph_with_3_components() {
    graph *g = create_graph(9);
    
    insert_edge(g, 0, 1, 1.);
    insert_edge(g, 1, 2, 1.);
    insert_edge(g, 2, 3, 1.);
    insert_edge(g, 1, 4, 1.);
    insert_edge(g, 6, 7, 1.);
    insert_edge(g, 6, 8, 1.);
    
    return g;
}

void print_components(graph *g) {
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
    graph *g1comp = graph_fully_connected();
    
    std::cout << "\nExemplo de grafo totalmente conectado (1 componente):" << std::endl;
    print_components(g1comp);

    graph *g3comp = graph_with_3_components();
    std::cout << "\nExemplo de grafo com 3 componentes:" << std::endl;
    print_components(g3comp);

    return 0;
}