#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <algorithm>
#include <list>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

class Grafo {
    public:
    
    void inserirVertice(int valor);
    void inserirAresta(int origem, int destino, int peso);
    bool possuiAresta(int origem, int destino);
    bool possuiVertice(int valor);
    void removerAresta(int origem, int destino);
    void imprimir();

    private:
    list<int> _vertices;
    map<pair<int, int>, int> _arestas;
};

void Grafo::inserirVertice(int valor) {
    _vertices.push_back(valor);
}

void Grafo::inserirAresta(int origem, int destino, int peso) {
    pair<int, int> origemDestino = make_pair(origem, destino);

    if (!possuiVertice(origem) || !possuiVertice(destino)) {
        return;
    }

    _arestas[origemDestino] = peso;
}

bool Grafo::possuiVertice(int valor) {
    auto vertice = find(_vertices.begin(), _vertices.end(), valor);
    return vertice != _vertices.end();
}

bool Grafo::possuiAresta(int origem, int destino) {
    pair<int, int> origemDestino = make_pair(origem, destino);
    return _arestas.count(origemDestino) == 1;
}

void Grafo::removerAresta(int origem, int destino) {
    pair<int, int> origemDestino = make_pair(origem, destino);
    _arestas.erase(origemDestino);
}

void Grafo::imprimir() {
    for (auto const &item : _arestas) {
        cout << item.first.first << " === " << item.second << " ===> " << item.first.second << endl;
    }
}

#endif //__GRAFO_HPP__