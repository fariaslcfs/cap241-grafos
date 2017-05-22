#include "graph/graph.hpp"
#include "graph/graph_connected.hpp"

#include <iostream>

/*
O algoritmo para busca de componentes conectados é uma busca em largura, onde a busca é realizada
a partir de cada um dos vértices do grafo. Ao realizar a busca os vértices visitados são marcados
e não é necessário iniciar uma nova busca a partir desses vértices, visto que eles podem ser alcançados
a partir de algum vértice visitado anteriormente.

A função retorna um vetor de vetores de inteiro, onde cada inteiro representa um vértice e cada
vetor um componente conectado.

*/
std::vector<std::vector<size_t>> graph_connected_components(graph *g)
{
    int v;
    std::vector<std::vector<size_t>> components;
    node *w;
    std::queue<int> q;
    std::map<int, bool> visited;

    //Marca todos os vértices como não visitados.
    for(size_t i = 0; i < g->size; ++i)
    {
        visited[i] = false;
    }
    //Para cada vértice de origem do grafo faça...
    for (size_t u = 0; u < g->size; ++u)
    {
        if (!visited[u]) { //Se o vértice não tiver sido visitado,
            std::vector<size_t> component; //crie um novo componente conectado,
            component.push_back(u); //adicione esse vértice ao componente conectado
            visited[u] = true; //e marque o vértice como visitado.

            q.push(u); //Inicie a busca em largura pelo vértice u
            while(!q.empty())
            {
                v = q.front();
                q.pop();
                for(w = g->nodes[v]; w != NULL; w = w->next)
                {
                    if (visited[w->id] == false)
                    {
                        component.push_back(w->id); //Adicione o vértice encontrado na busca em largura ao componente conectado
                        visited[w->id] = true; //Marque-o como visitado para NÃO iniciar uma nova busca por componentes a partir dele
                        q.push(w->id); //Continue navegando por este componentes conectado a partir deste vértice
                    }
                }
            }
            components.push_back(component); //Adicione o componente encontrado ao vetor de componentes
        }
    }
    return components;
}



graph * graph_fully_connected() {
    graph *g = create_graph(9);
    
    insert_edge(g, 0, 1, 1.);
    insert_edge(g, 1, 2, 1.);
    insert_edge(g, 2, 3, 1.);
    insert_edge(g, 1, 4, 1.);
    insert_edge(g, 4, 5, 1.);
    insert_edge(g, 0, 5, 1.);
    insert_edge(g, 0, 6, 1.);
    insert_edge(g, 6, 7, 1.);
    insert_edge(g, 6, 8, 1.);
    
    return g;
}

graph* graph_with_3_components() {
    graph *g = create_graph(9);
    
    insert_edge(g, 0, 1, 1.);
    insert_edge(g, 1, 2, 1.);
    insert_edge(g, 2, 3, 1.);
    insert_edge(g, 1, 4, 1.);
    insert_edge(g, 6, 7, 1.);
    insert_edge(g, 6, 8, 1.);
    
    return g;
}

void print_components(graph *g)
{
    std::vector<std::vector<size_t>> components = graph_connected_components(g);

    for (size_t c = 0; c < components.size(); ++c)
    {
        std::cout << "Componente " << c << ":" << std::endl << "{";
        auto component = components[c];
        for (size_t n = 0; n < component.size(); ++n)
        {
            std::cout << component[n];
            if (n < component.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl << std::endl;
    }
}
