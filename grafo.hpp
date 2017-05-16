#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <algorithm>
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <initializer_list>
#include <iterator>


class Grafo {
    public:
    
	Grafo();
	explicit Grafo(std::initializer_list<int> initVertices, std::initializer_list<std::pair<int, int>> initPares, std::initializer_list<int> initPesos);
	~Grafo();

    void inserirVertice(int valor);
    void inserirAresta(int origem, int destino, int peso);
    bool possuiAresta(int origem, int destino);
    bool possuiVertice(int valor);
    void removerAresta(int origem, int destino);
    void imprimir();

    private:
    std::list<int> vertices_;
    std::map<std::pair<int, int>, int> arestas_;

};


Grafo::Grafo()
{
}


Grafo::Grafo(std::initializer_list<int> initVertices, std::initializer_list<std::pair<int, int>> initPares, std::initializer_list<int> initPesos)
{
	auto itpai = initPares.begin();
	auto itpaf = initPares.end();
	auto itpei = initPesos.begin();

	for(auto itv = initVertices.begin(); itv != initVertices.end(); ++itv)
	{
		inserirVertice(*itv);
	}

	while(itpai != itpaf)
	{
		inserirAresta(itpai->first, itpai->second, *itpei);
		 ++itpai; ++itpei;
	}
}


Grafo::~Grafo()
{
}


void Grafo::inserirVertice(int valor) {
    vertices_.push_back(valor);
}


void Grafo::inserirAresta(int origem, int destino, int peso) {
	auto origemDestino = std::make_pair(origem, destino);

    if (!possuiVertice(origem) || !possuiVertice(destino)) {
        return;
    }
    arestas_[origemDestino] = peso;
}


bool Grafo::possuiVertice(int valor) {
    auto vertice = std::find(vertices_.begin(), vertices_.end(), valor);
    return vertice != vertices_.end();
}


bool Grafo::possuiAresta(int origem, int destino) {
	auto origemDestino = std::make_pair(origem, destino);
    return arestas_.count(origemDestino) == 1;
}


void Grafo::removerAresta(int origem, int destino) {
	auto origemDestino = std::make_pair(origem, destino);
    arestas_.erase(origemDestino);
}


void Grafo::imprimir() {
    for (auto const &item : arestas_) {
    	std::cout << item.first.first << " === " << item.second << " ===> " << item.first.second << std::endl;
    }
}


#endif //__GRAFO_HPP__
