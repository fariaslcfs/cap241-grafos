#include "grafo.hpp"
#include <iostream>

int main()
{
    Grafo grafo;
    
    grafo.inserirVertice(0);
    grafo.inserirVertice(1);
    grafo.inserirVertice(2);
    grafo.inserirVertice(3);

    grafo.inserirAresta(0, 1, 10);
    grafo.inserirAresta(1, 2, 10);
    grafo.inserirAresta(2, 3, 10);
    grafo.inserirAresta(3, 0, 10);


    Grafo grafo1 {{0,1,2,3}, {{0,1}, {1,2}, {2,3}, {3,0}}, {10, 10, 10, 10}};


    if (!grafo.possuiAresta(0, 1)) {
    	std::cout << "Aresta 0 -> 1 não encontrada!" << std::endl;
    }

    if (grafo.possuiAresta(1, 0)) {
    	std::cout << "Aresta 1 -> 0 não deveria existir!" << std::endl;
    }

    grafo.removerAresta(0, 1);

    if (grafo.possuiAresta(0, 1)) {
    	std::cout << "Aresta 0 -> 1 deveria ter sido removida!" << std::endl;
    }

    grafo.imprimir();
    
    std::cout << std::endl;

    grafo1.removerAresta(1,2);

    grafo1.imprimir();


    return 0;
}
