//
// Created by tyyp- on 5.10.2020.
//

#ifndef SHORTESTPATHALGORITH_GRAPH_H
#define SHORTESTPATHALGORITH_GRAPH_H

#include <vector>

// implement graph via adjacent matrix
class Graph
{

private:
    int edgeNum;

    int verticesNum;

    std::vector<std::vector<int> > adMatrix;

public:
    enum Color
    {
        RED,
        GREEN,
        BLUE
    };
    
    Graph() {}

    Graph(int verticeNum);

    Graph(int verticeNum, double density);

    int getVerticeNum() const { return verticesNum; }

    int getEdgeNum() const { return edgeNum; }

    // tests whether there is an edge from node x to node y
    bool adjacent(int x, int y) const;

    // lists all nodes y such that there is an edge from
    // x to y
    std::vector<int> neighbors(int x) const;

    // return all vertices in the graph
    std::vector<int> getVertices() const;

    bool addEdge(int x, int y, int value);

    bool deleteEdge(int x, int y);

    int getEdgeValue(int x, int y) const;

    void setEdgeValue(int x, int y, int value);

};


#endif //SHORTESTPATHALGORITH_GRAPH_H
