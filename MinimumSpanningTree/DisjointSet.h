//
// Created by tyyp- on 11/23/2020.
//

#ifndef MINIMUMSPANNINGTREE_DISJOINTSET_H
#define MINIMUMSPANNINGTREE_DISJOINTSET_H

#include <vector>

class DisjointSet
{
public:
    DisjointSet() {}

    DisjointSet(int setNum): array(setNum, -1) {}

    // union 2 sets which contain x and y respectively.
    void unionSets(int x, int y);

    // find the representative element of set containing x
    int findSet(int x);

private:
    std::vector<int> array;
};


#endif //MINIMUMSPANNINGTREE_DISJOINTSET_H
