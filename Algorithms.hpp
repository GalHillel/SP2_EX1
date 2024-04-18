#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>
#include <vector>

namespace ariel
{
    class Algorithms
    {
    private:
        static bool isContainsCycleUtil(const Graph &graph, size_t vertex, std::vector<bool> &visited, std::vector<bool> &stack);

    public:
        static bool isConnected(const Graph &graph);
        static std::string shortestPath(const Graph &graph, int start, int end);
        static bool isContainsCycle(const Graph &graph);
        static std::string isBipartite(const Graph &graph);
    };
}

#endif
