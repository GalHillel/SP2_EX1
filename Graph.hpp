#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel
{

    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int vertices;

    public:
        Graph();
        void loadGraph(const std::vector<std::vector<int>> &graph);
        void printGraph() const;
        bool isValidGraph(const std::vector<std::vector<int>> &graph) const;
        int getVertices() const { return vertices; }
        const std::vector<std::vector<int>> &getAdjacencyMatrix() const { return adjacencyMatrix; }
    };

}

#endif
