//
// Created by tyyp- on 2.10.2020.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <cassert>

using namespace std;

//Indirect Graph Implementation with Adj Matrix
template<typename NumericType>
class Graph {
private:
    int verticesCount;
    NumericType ** adjMatrix;

    const int WEIGHT_RANGE = 9;
public:
    //Constructors
    Graph():verticesCount(0){};

    void InitializeAdjMatrix();

    Graph(int verticesCount):
    verticesCount(verticesCount)
    {
        assert( 0 < verticesCount );

        InitializeAdjMatrix();
    }

    void RandomGraphGenerator(double density);

    Graph(int verticesCount ,double density):
    verticesCount(verticesCount)
    {
        assert( 0 < verticesCount  && 0 <= density  && density <= 1 );

        InitializeAdjMatrix();
        RandomGraphGenerator(density);

    }


    //Accessor Methods
    void SetVerticesCount( int verticesCount) { this->verticesCount = verticesCount;}
    int GetVerticesCount() { return verticesCount;}

    void SetAdjMatrix( NumericType ** adjMatrix)
    {
        int u,v;
        for (u = 0; u < verticesCount; ++u) {
            for (v = 0; v < verticesCount; ++v) {
                this->adjMatrix[u][v] = adjMatrix[u][v];
            }
        }
    }
    NumericType GetAdjMatrix() { return adjMatrix;}

    //Method Prototypes
    void PrintAdjMatrix();

    void AddEdge(int vertex1 , int vertex2 , NumericType weight);
    void DeleteEdge(int vertex1, int vertex2 );

    bool IsAdjacent(int vertex1 ,int vertex2);

    vector<int> Adjacents(int vertex);

    int GetEdgeCount();
    int GetEdgeValue(int vertex1 ,int vertex2 );
    void SetEdgeValue(int vertex1 ,int vertex2 ,int weight);
};
///If you are doing template programming, then everything must be in header file.

                                    ///SOURCES ///

template<typename NumericType>
void Graph<NumericType>::InitializeAdjMatrix() {

    adjMatrix = new NumericType* [verticesCount];
    for (int u = 0; u < verticesCount; ++u){
        adjMatrix[u] = new NumericType[verticesCount];
        for (int v = 0; v < verticesCount; ++v) {
            adjMatrix[u][v] = 0;
        }
    }
}

template<typename NumericType>
void Graph<NumericType>::RandomGraphGenerator(double density){

    srand(time(0)); //seed rand() func
    for (int u = 0; u < verticesCount; ++u) {
        for (int v = 0; v < verticesCount; ++v) {

            double prob = ( rand() % 10 ) / 10.0;

            if ( density > prob)
            {
                int weight = rand() % WEIGHT_RANGE +1 ;
                AddEdge(u ,v , weight);
            }
        }
    }
}



//Prints adj matrix.
template<typename NumericType>
void Graph<NumericType>::PrintAdjMatrix() {
    int u,v;
    for ( u = 0; u < verticesCount; ++u) {
        for (v = 0; v < verticesCount; ++v)
            cout << adjMatrix[u][v] << " ";
        cout << endl;
    }
}

template<typename NumericType>
bool Graph<NumericType>::IsAdjacent(int vertex1, int vertex2) {
    assert(vertex1 >= 0 && vertex1 < verticesCount && vertex2 >= 0 && vertex2 < verticesCount );

    return (adjMatrix[vertex1][vertex2] != 0) || (adjMatrix[vertex2][vertex1] != 0);
}

template<typename NumericType>
vector<int> Graph<NumericType>::Adjacents(int vertex) {

    assert(0 <= vertex && vertex < verticesCount );
    vector<int> list;
    for (int i = 0; i < verticesCount; ++i) {
        if (adjMatrix[vertex][i] != 0)
            list.push_back(i);
    }
    return vector<int>();
}



//Adds edge in adj matrix.
template<typename NumericType>
void Graph<NumericType>::AddEdge(int vertex1 , int vertex2 , NumericType weight){
    assert(0 <= vertex1 && vertex1 < verticesCount && 0 <= vertex2 && vertex2 < verticesCount && weight <= WEIGHT_RANGE) ;
    adjMatrix[vertex1][vertex2] = weight;
    adjMatrix[vertex2][vertex1] = weight;
}


template<typename NumericType>
void Graph<NumericType>::DeleteEdge(int vertex1, int vertex2) {
    assert(0 <= vertex1 && vertex1 < verticesCount && 0 <= vertex2 && vertex2 < verticesCount ) ;

    adjMatrix[vertex1][vertex2] = 0;
    adjMatrix[vertex2][vertex1] = 0;
}



template<typename NumericType>
int Graph<NumericType>::GetEdgeCount() {
    int counter = 0;
    for (int u = 0; u < verticesCount; ++u) {
        for (int v = 0; v < verticesCount; ++v) {
            if (adjMatrix[u][v] != 0 )
                counter++;
        }
    }
    return counter /2 ;//For indirect graph.
}

template<typename NumericType>
int Graph<NumericType>::GetEdgeValue(int vertex1, int vertex2) {
    assert(0 <= vertex1 && vertex1 < verticesCount && 0 <= vertex2 && vertex2 < verticesCount ) ;
    return adjMatrix[vertex1][vertex2];
}

template<typename NumericType>
void Graph<NumericType>::SetEdgeValue(int vertex1, int vertex2, int weight) {
    assert(0 <= vertex1 && vertex1 < verticesCount && 0 <= vertex2 && vertex2 < verticesCount && weight <= WEIGHT_RANGE) ;
    adjMatrix[vertex1][vertex2] = weight;
    adjMatrix[vertex2][vertex1] = weight; //For indirect
}


#endif //GRAPHS_GRAPH_H
