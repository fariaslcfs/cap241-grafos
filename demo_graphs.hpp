#ifndef __DEMO_GRAPHS_H__
#define __DEMO_GRAPHS_H__

namespace demo 
{
    Graph *acyclic_8nodes_3edges() {
        Graph *g = new Graph(8);
    
        g->insertEdge(0, 1, 1.);
        g->insertEdge(2, 6, 1.);
        g->insertEdge(4, 6, 1.);

        return g;
    }

    Graph* fully_connected_9nodes_9edges() {
        Graph *g = new Graph(9);
        
        g->insertEdge(0, 1, 1.);
        g->insertEdge(1, 2, 1.);
        g->insertEdge(2, 3, 1.);
        g->insertEdge(1, 4, 1.);
        g->insertEdge(4, 5, 1.);
        g->insertEdge(0, 5, 1.);
        g->insertEdge(0, 6, 1.);
        g->insertEdge(6, 7, 1.);
        g->insertEdge(6, 8, 1.);
        
        return g;
    }

    Graph* disconnected_3components_9nodes_6edges() {
        Graph *g = new Graph(9);
        
        g->insertEdge(0, 1, 1.);
        g->insertEdge(1, 2, 1.);
        g->insertEdge(2, 3, 1.);
        g->insertEdge(1, 4, 1.);
        g->insertEdge(6, 7, 1.);
        g->insertEdge(6, 8, 1.);
        
        return g;
    }
}

#endif //__DEMO_GRAPHS_H__