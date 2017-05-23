#include "graph/graph.hpp"
#include "graph/graph_algorithms.hpp"

#include "demo_graphs.hpp"

#include <string>
#include <iostream>


void printStack(std::stack<int> stack) {
    std::cout << "Ordem Topológica: ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

void sort(Graph *g) {
    std::cout << g->getPrettyPrint();
    try {
        std::stack<int> t = graph_topological_order(g);
        printStack(t);
    } catch (const std::invalid_argument& e) {
        std::cout << "Exceção lançada! Não foi possível realizar a ordenação topológica: (" << e.what() << ")" << std::endl;
    }
}

int main(){

    std::cout << std::endl << " --- Exemplo 1 --- " << std::endl;
    Graph *g = demo::acyclic_4nodes();
    sort(g);
    delete g;

    std::cout << std::endl << " --- Exemplo 2 --- " << std::endl;
    g = demo::acyclic_5nodes();
    sort(g);
    delete g;

    std::cout << std::endl << " --- Exemplo 3 --- " << std::endl;
    g = demo::cyclic_4nodes();
    sort(g);
    delete g;

    return 0;
}