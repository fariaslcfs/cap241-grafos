#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include <iostream>

Graph* graph_fully_connected() {
    Graph *g = new Graph(9);
    
    g->insertEdge(0, 1, 1.);
    g->insertEdge(1, 2, 1.);
    g->insertEdge(2, 3, 1.);
    g->insertEdge(1, 4, 1.);
    g->insertEdge(4, 5, 1.);
    g->insertEdge(0, 5, 1.);
    g->insertEdge(0, 6, 1.);
    g->insertEdge(6, 7, 1.);
    g->insertEdge(6, 8, 1.);
    
    return g;
}

Graph* graph_with_3_components() {
    Graph *g = new Graph(9);
    
    g->insertEdge(0, 1, 1.);
    g->insertEdge(1, 2, 1.);
    g->insertEdge(2, 3, 1.);
    g->insertEdge(1, 4, 1.);
    g->insertEdge(6, 7, 1.);
    g->insertEdge(6, 8, 1.);
    
    return g;
}

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
    Graph *g1comp = graph_fully_connected();
    
    std::cout << "\nExemplo de grafo totalmente conectado (1 componente):" << std::endl;
    print_components(g1comp);

    Graph *g3comp = graph_with_3_components();
    std::cout << "\nExemplo de grafo com 3 componentes:" << std::endl;
    print_components(g3comp);

    return 0;
}