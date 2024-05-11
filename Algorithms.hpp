#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>

namespace ariel
{

    class Algorithms
    {
    public:
        static bool isConnected(const Graph &g);
        static std::string shortestPath(const Graph &g, int start, int end);
        static std::string isContainsCycle(const Graph &g); //fix  
        static std::string isBipartite(const Graph &g); // fix
        static void negativeCycle(const Graph &g);

    private:
        static bool dfs(const std::vector<std::vector<int>> &adjacencyMatrix, std::vector<bool> &visited, int start);
        static bool isContainsCycleH(const std::vector<std::vector<int>> &adjacencyMatrix, int vertex, std::vector<bool> &visited, int parent, std::vector<int> &cycle);
    };
}

#endif
