#include <stdio.h>
#include <stdlib.h>
#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include <string>
#include <iostream>

int main(){

    Graph *g = new Graph(8);
    
    g->insertEdge(0, 1, 1.);
    g->insertEdge(2, 6, 1.);
    g->insertEdge(4, 6, 1.);
    g->print();
    std::stack<int> t = graph_topological_order(g);

    while (!t.empty()) {
        std::cout << t.top() << " ";
        t.pop();
    }
    std::cout << std::endl;
}