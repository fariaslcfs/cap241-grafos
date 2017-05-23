#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include "demo_graphs.hpp"

#include <string>
#include <iostream>

int main(){

    Graph *g = demo::acyclic_8nodes_3edges();
    std::cout << "is_cyclic: " << graph_is_cyclic(g) << std::endl;
    delete g;

    g = demo::cyclic_4nodes_6edges();
    std::cout << "is_cyclic: " << graph_is_cyclic(g) << std::endl;
    delete g;
    
    return 0;
}