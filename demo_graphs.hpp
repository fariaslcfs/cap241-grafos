#ifndef __DEMO_GRAPHS_H__
#define __DEMO_GRAPHS_H__

#include <sstream>

namespace demo 
{

    Graph *acyclic_4nodes() {
        std::stringstream pp;
        pp << "    1     \n";
        pp << "  /       \n";
        pp << "0         \n";
        pp << "  \\      \n";
        pp << "    2 - 3 \n";

        Graph *g = new Graph(4);
        g->setPrettyPrint(pp.str());
        g->insertEdge(0, 1, 1.);
        g->insertEdge(0, 2, 1.);
        g->insertEdge(2, 3, 1.);

        return g;
    }

    Graph *acyclic_5nodes() {
        std::stringstream pp;
        pp << "    1     \n";
        pp << "  /       \n";
        pp << "0 ----- 4  \n";
        pp << "  \\   /   \n";
        pp << "    2 - 3 \n";

        Graph *g = new Graph(5);
        g->setPrettyPrint(pp.str());
        g->insertEdge(0, 1, 1.);
        g->insertEdge(0, 2, 1.);
        g->insertEdge(2, 3, 1.);
        g->insertEdge(2, 4, 1.);
        g->insertEdge(0, 4, 1.);

        return g;
    }

    Graph *cyclic_4nodes() {
        std::stringstream pp;
        pp << "    1      \n";
        pp << "  /   \\   \n";
        pp << "0       2  \n";
        pp << "  \\   /   \n";
        pp << "    3      \n";

        Graph *g = new Graph(4);
        g->setPrettyPrint(pp.str());
        g->insertEdge(0, 1, 1.);
        g->insertEdge(1, 2, 1.);
        g->insertEdge(2, 3, 1.);
        g->insertEdge(3, 0, 1.);

        return g;
    }

    Graph *cyclic_2nodes() {
        std::stringstream pp;
        pp << "0 < - > 1 \n";
        
        Graph *g = new Graph(2);
        g->setPrettyPrint(pp.str());
        g->insertEdge(0, 1, 1.);
        g->insertEdge(1, 0, 1.);

        return g;
    }

    Graph *cyclic_1node() {
        std::stringstream pp;
        pp << "   _   \n";
        pp << "  / |  \n";
        pp << " 0 -   \n";
        
        Graph *g = new Graph(1);
        g->setPrettyPrint(pp.str());
        g->insertEdge(0, 0, 1.);

        return g;
    }

    Graph *acyclic_4nodes2components() {
        std::stringstream pp;
        pp << "    1     \n";
        pp << "          \n";
        pp << "0         \n";
        pp << "  \\      \n";
        pp << "    2 - 3 \n";

        Graph *g = new Graph(4);
        g->setPrettyPrint(pp.str());
        
        g->insertEdge(0, 2, 1.);
        g->insertEdge(2, 3, 1.);

        return g;
    }

}

#endif //__DEMO_GRAPHS_H__