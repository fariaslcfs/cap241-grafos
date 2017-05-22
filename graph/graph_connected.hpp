#ifndef __GRAPH_CONNECTED_H__
#define __GRAPH_CONNECTED_H__

#include <vector>
#include <map>
#include <queue>

#include "graph.hpp"

std::vector<std::vector<size_t>> graph_connected_components(graph *);

void print_components(graph *);

graph * graph_fully_connected();

graph * graph_with_3_components();


#endif //__GRAPH_CONNECTED_H__
