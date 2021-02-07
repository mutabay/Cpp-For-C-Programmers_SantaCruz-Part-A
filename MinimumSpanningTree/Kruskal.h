//
// Created by tyyp- on 11/23/2020.
//

#ifndef MINIMUMSPANNINGTREE_KRUSKAL_H
#define MINIMUMSPANNINGTREE_KRUSKAL_H

#include "MinimumSpanningTree.h"

#include <vector>

class KruskalMST: public MinSpanTree
{
public:
    int generateMST(const Graph&, std::vector<EdgeNode>&) const;
};

#endif //MINIMUMSPANNINGTREE_KRUSKAL_H
