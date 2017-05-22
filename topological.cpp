#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include "demo_graphs.hpp"

#include <string>
#include <iostream>

int main(){

    Graph *g = demo::acyclic_8nodes_3edges();
    
    std::stack<int> t = graph_topological_order(g);

    while (!t.empty()) {
        std::cout << t.top() << " ";
        t.pop();
    }
    std::cout << std::endl;
    delete g;
    return 0;
}