//
// Created by tyyp- on 11/23/2020.
//

#ifndef MINIMUMSPANNINGTREE_MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_MINIMUMSPANNINGTREE_H

#include <vector>

#include "Graph.h"

// the edge which consists of MST
struct EdgeNode
{
    int x;
    int y;
    int value;

    EdgeNode(int x=-1, int y=-1, int value=0): x(x), y(y), value(value)
    {
    }
};

// declare the interface of MST algorithm
// sort of Strategy Pattern
class MinSpanTree
{
public:
    // store the MST's edges in vector<EdgeNode>
    // return the min cost.
    virtual int generateMST(const Graph&, std::vector<EdgeNode>&) const = 0;
};

#endif //MINIMUMSPANNINGTREE_MINIMUMSPANNINGTREE_H
