#ifndef __GRAPH_TOPOLOGICAL_H__
#define __GRAPH_TOPOLOGICAL_H__

#include <vector>
#include <stack>
#include <iostream>

#include "graph.hpp"

void __topo();

void topo_order(graph *, size_t, std::vector<bool> &, std::stack<size_t> &);

std::stack<size_t> graph_topological_order(graph *);

#endif //__GRAPH_TOPOLOGICAL_H__
