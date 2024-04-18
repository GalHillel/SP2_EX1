#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;

    public:
        Graph();
        ~Graph();
        void loadGraph(const std::vector<std::vector<int>> &matrix);
        void printGraph() const;
        int getSize() const;
        int getWeight(int from, int to) const;
    };
}
#endif
