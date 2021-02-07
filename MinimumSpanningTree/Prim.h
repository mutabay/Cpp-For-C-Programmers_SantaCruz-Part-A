//
// Created by tyyp- on 11/23/2020.
//

#ifndef MINIMUMSPANNINGTREE_PRIM_H
#define MINIMUMSPANNINGTREE_PRIM_H

#include "MinimumSpanningTree.h"

class PrimMST: public MinSpanTree
{
public:
    int generateMST(const Graph&, std::vector<EdgeNode>&) const;
};

#endif //MINIMUMSPANNINGTREE_PRIM_H
