#include <stdio.h>
#include <stdlib.h>
#include "graph/graph.hpp"
#include "graph/graph_topological.hpp"

#include <string>
#include <iostream>

int main(){

    Graph *g = create_graph(8);
    
    insert_edge(g, 0, 1, 1.);
    insert_edge(g, 2, 6, 1.);
    insert_edge(g, 4, 6, 1.);

    std::stack<int> t = graph_topological_order(g);

    while (!t.empty()) {
        std::cout << t.top() << " ";
        t.pop();
    }
    std::cout << std::endl;
}