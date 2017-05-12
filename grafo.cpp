#include "grafo.hpp"
#include <iostream>

using namespace std;

int main() {
    Grafo grafo;
    
    grafo.inserirVertice(0);
    grafo.inserirVertice(1);
    grafo.inserirVertice(2);
    grafo.inserirVertice(3);

    grafo.inserirAresta(0, 1, 10);
    grafo.inserirAresta(1, 2, 10);
    grafo.inserirAresta(2, 3, 10);
    grafo.inserirAresta(3, 0, 10);

    if (!grafo.possuiAresta(0, 1)) {
        cout << "Aresta 0 -> 1 não encontrada!" << endl;
    }

    if (grafo.possuiAresta(1, 0)) {
        cout << "Aresta 1 -> 0 não deveria existir!" << endl;
    }

    grafo.removerAresta(0, 1);

    if (grafo.possuiAresta(0, 1)) {
        cout << "Aresta 0 -> 1 deveria ter sido removida!" << endl;
    }

    grafo.imprimir();
    
    return 0;
}