#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include "demo_graphs.hpp"

#include <string>
#include <iostream>


void printStack(std::stack<int> stack) {
    std::cout << "Topological Sort: ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

int main(){

    std::cout << std::endl << " --- Exemplo 1 --- " << std::endl;
    Graph *g = demo::acyclic_4nodes();
    std::cout << g->getPrettyPrint();
    std::stack<int> t = graph_topological_order(g);
    printStack(t);
    delete g;

    std::cout << std::endl << " --- Exemplo 2 --- " << std::endl;
    g = demo::acyclic_5nodes();
    std::cout << g->getPrettyPrint();
    t = graph_topological_order(g);
    printStack(t);
    delete g;

    return 0;
}