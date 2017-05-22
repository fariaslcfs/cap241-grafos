#include <iostream>
#include "graph/graph.hpp"
#include "graph/graph_cicle.hpp"
#include "graph/graph_search.hpp"
#include "graph/graph_connected.hpp"
#include "graph/graph_topological.hpp"


void alcance()
{
	graph *g = create_demo_graph();
	int u,v;
	for (u = 0; u < 9; ++u)
	{
		for (v = 0; v < 9; ++v)
		{
			if (reach(g, u, v) == 1)
			{
				std::cout << u << " alcança " << v << std::endl;
			}
			else
			{
				std::cout << u << " não alcança " << v << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

void bfs()
{
	size_t i, j;
	graph *g = create_demo_graph();
	int *vet;
	for (i = 0; i < g->size; ++i)
	{
		std::cout << "A partir do " << i << std::endl;
		vet = bfs(g, i);
		for (j = 0; j < g->size; ++j)
		{
			std::cout << "#" << (int) j << ":" << vet[j] << std::endl;
		}
		free(vet);
		std::cout << std::endl;
	}
}

void dfs()
{
    size_t i, j;
    graph *g = create_demo_graph();
    int *vet;
    for(i = 0; i < g->size; ++i)
    {
        std::cout << "A partir do " << i << std::endl;
        vet = dfs(g, i);
        for(j = 0; j < g->size; ++j)
        {
            std::cout << "#" << (int)j << ":" << vet[j] << std::endl;
        }
        free(vet);
        std::cout << std::endl;
    }
}

void g_f_connected()
{
    graph *gwith1 = graph_fully_connected();
    std::cout << std::endl << "Exemplo de grafo totalmente conectado (1 componente):" << std::endl;
    print_components(gwith1);

    graph *gwith3 = graph_with_3_components();
    std::cout << std::endl << "Exemplo de grafo com 3 componentes:" << std::endl;
    print_components(gwith3);
}

void g_topological()
{
	__topo();
}

int main()
{
	//alcance();
	std::cout << std::endl;

	bfs();
	std::cout << std::endl;

	dfs();
	std::cout << std::endl;

	g_f_connected();
	std::cout << std::endl;

	return 0;
}
