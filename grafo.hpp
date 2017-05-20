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
    /*
    Lista de inteiros para armazenar os vértices do grafo.
    */
    std::list<int> vertices_; 
    /*
    Mapa para armazenar arestas com um par de inteiros 
    (vértice de origem e destino) como chave e um inteiro como valor (peso).
    */
    std::map<std::pair<int, int>, int> arestas_; 

};


Grafo::Grafo()
{
}

/*
Constrói um novo grafo a partir de uma lista de vertices e arestas

Exemplo:
Grafo grafo1 {{0,1,2,3}, {{0,1}, {1,2}, {2,3}, {3,0}}, {10, 10, 10, 10}};

Inicializa o grafo1 com 4 vértices {0,1,2,3}, 4 arestas {{0,1}, {1,2}, {2,3}, {3,0}} com pesos {10, 10, 10, 10}
*/
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

/*
Insere um novo vértice no grafo.
TODO: Verificar se o vértice já existe antes de inserir.
*/
void Grafo::inserirVertice(int valor) {
    vertices_.push_back(valor);
}


/*
Insere uma nova aresta no grafo entre os vértices origem e destino com o peso informado.
*/
void Grafo::inserirAresta(int origem, int destino, int peso) {
	auto origemDestino = std::make_pair(origem, destino);

    if (!possuiVertice(origem) || !possuiVertice(destino)) { //Verifica se os vértices de origem e destino da aresta existem.
        return;
    }
    arestas_[origemDestino] = peso;
}

/*
Retorna true se o vértice existir no grafo
*/
bool Grafo::possuiVertice(int valor) {
    //O método find retorna a posição end() caso o valor procurado não seja encontrado.
    auto vertice = std::find(vertices_.begin(), vertices_.end(), valor);
    return vertice != vertices_.end();
}

/*
Verifica se a aresta informada existe.
*/
bool Grafo::possuiAresta(int origem, int destino) {
	auto origemDestino = std::make_pair(origem, destino);
    //Caso aresta exista número de elementos com a chave igual a origem e destino deve ser == 1
    return arestas_.count(origemDestino) == 1;
}

/*
Remove a aresta entre origem e destino.
*/
void Grafo::removerAresta(int origem, int destino) {
	auto origemDestino = std::make_pair(origem, destino);
    arestas_.erase(origemDestino);
}

/*
Imprime uma descrição do grafo
TODO: Imprimir vértices, melhorar representação do grafo.
*/
void Grafo::imprimir() {
    for (auto const &item : arestas_) {
    	std::cout << item.first.first << " === " << item.second << " ===> " << item.first.second << std::endl;
    }
}


#endif //__GRAFO_HPP__
