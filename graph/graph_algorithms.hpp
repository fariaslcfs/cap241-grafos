#ifndef __GRAPH_ALGORITHMS_HPP__
#define __GRAPH_ALGORITHMS_HPP__

#include <vector>
#include <stack>
#include <map>
#include <queue>

#include "graph.hpp"

void topo_order(Graph *g, int i, std::vector<bool> &visited, std::stack<int> &topo) {
    if (! visited[i]) { //Se o vértice ainda não foi visitado
        visited[i] = true; //marque-o como visitado
        if (g->getNode(i) != NULL) { // e se houverem vértices adjascentes
            Node *n = g->getNode(i);
            while (n != NULL) {
                topo_order(g, n->getId(), visited, topo); //realize a ordenação topológica para os vértices adjascentes primeiro
                n = n->getNext(); //próximo vértice adjacente
            }
        }
        //Caso não haja mais adjacentes adicione o vértice atual a ordenação topológica
        topo.push(i);
    }
}

/*
Realiza a ordenação topológica usando um algoritmo de busca em profundidade recursivo.
*/
std::stack<int> graph_topological_order(Graph *g) {
    std::vector<bool> visited; //Vértices já visitados.
    std::stack<int> topo; //Pilha com a ordenação topológica
    visited.resize(g->getSize(), false); //Inicializa o vetor de vértices visitados com false

    /*
    Para cada vértice da lista de adjacências...
    */
    for (int i = 0; i < g->getSize(); ++i) {
        topo_order(g, i, visited, topo);
    }
    return topo;
}

/*
O algoritmo para busca de componentes conectados é uma busca em largura, onde a busca é realizada
a partir de cada um dos vértices do grafo. Ao realizar a busca os vértices visitados são marcados
e não é necessário iniciar uma nova busca a partir desses vértices, visto que eles podem ser alcançados
a partir de algum vértice visitado anteriormente.

A função retorna um vetor de vetores de inteiro, onde cada inteiro representa um vértice e cada
vetor um componente conectado.

*/
std::vector<std::vector<int>> graph_connected_components(Graph *g) {
    int v;
    std::vector<std::vector<int>> components;
    Node *w;
    std::queue<int> q;
    std::map<int, bool> visited;
    
    //Marca todos os vértices como não visitados.
    for(int i=0; i < g->getSize(); ++i){
        visited[i] = false;
    }
    //Para cada vértice de origem do grafo faça...
    for (int u = 0; u < g->getSize(); ++u) {
        if (!visited[u]) { //Se o vértice não tiver sido visitado,
            std::vector<int> component; //crie um novo componente conectado,
            component.push_back(u); //adicione esse vértice ao componente conectado
            visited[u] = true; //e marque o vértice como visitado.
            
            q.push(u); //Inicie a busca em largura pelo vértice u
            while(!q.empty()){
                v = q.front();
                q.pop();
                for(w=g->getNode(v); w != NULL; w = w->getNext()){
                    if (visited[w->getId()] == false){
                        component.push_back(w->getId()); //Adicione o vértice encontrado na busca em largura ao componente conectado
                        visited[w->getId()] = true; //Marque-o como visitado para NÃO iniciar uma nova busca por componentes a partir dele
                        q.push(w->getId()); //Continue navegando por este componentes conectado a partir deste vértice
                    }
                }
            }
            components.push_back(component); //Adicione o componente encontrado ao vetor de componentes
        }
    }
    return components;
}

bool is_cyclic(Graph *g, size_t i, std::vector<bool> &visited, std::vector<bool> &antecedents) {
    //Se o nó não foi visitado anteriormente 
    if (!visited[i]) {
        //Defina-o como visitado
        visited[i] = true;
        //Marque o nó como antecedente na árvore de profundidade pesquisada atualmente
        antecedents[i] = true;

        //Pegue o primeiro nó adjacente
        Node *n = g->getNode(i);
        while (n != NULL) { //Se o nó adjacente existir...
            //Se o nó adjacente NÃO tiver sido visitado, verifique se o nó atual é descendente do nó adjacente
            if (!visited[n->getId()] && is_cyclic(g, n->getId(), visited, antecedents)) {
                return true;
            //Se o nó adjacente (descendente) for também antecedente deste
            } else if (antecedents[n->getId()]) {
                return true;
            }
            //Próximo nó adjacente
            n = n->getNext();
        }
    }
    //Se o ciclo não foi encontrado remova o nó atual do vetor de nós antecedentes.
    antecedents[i] = false;
    return false;
}

bool graph_is_cyclic(Graph *g) {
    std::vector<bool> visited;
    std::vector<bool> antecedents;

    visited.resize(g->getSize(), false);
    antecedents.resize(g->getSize(), false);

    /*
    Para cada vértice do grafo, verifica se possui ciclos.
    */
    for (size_t i = 0; i < g->getSize(); ++i) {
        if (is_cyclic(g, i, visited, antecedents)) {
            return true;
        }
    }
    return false;
}

#endif //__GRAPH_ALGORITHMS_HPP__