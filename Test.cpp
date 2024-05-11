#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Algorithms Class Tests")
{
    SUBCASE("Test isConnected")
    {
        ariel::Graph g;
        // Test a connected graph
        vector<vector<int>> connectedGraph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(connectedGraph);
        CHECK(ariel::Algorithms::isConnected(g) == true);

        // Test a disconnected graph
        vector<vector<int>> disconnectedGraph = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(disconnectedGraph);
        CHECK(ariel::Algorithms::isConnected(g) == false);
    }

    SUBCASE("Test shortestPath")
    {
        ariel::Graph g;
        // Test shortest path in a connected graph
        vector<vector<int>> connectedGraph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(connectedGraph);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

        // Test shortest path in a disconnected graph
        vector<vector<int>> disconnectedGraph = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(disconnectedGraph);
        CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    }

    SUBCASE("Test isContainsCycle")
    {
        ariel::Graph g;
        // Test a graph without a cycle
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

        // Test a graph with a cycle
        vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        cout << ariel::Algorithms::isContainsCycle(g) << endl;
        CHECK(ariel::Algorithms::isContainsCycle(g).find("The cycle is:") != string::npos);
    }

    SUBCASE("Test isBipartite")
    {
        ariel::Graph g;
        // Test a bipartite graph
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

        // Test a non-bipartite graph
        vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        CHECK(ariel::Algorithms::isBipartite(g) == "0");

        // Test another bipartite graph
        vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 0},
            {1, 0, 3, 0, 0},
            {0, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
        g.loadGraph(graph3);
        CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
    }
}

TEST_CASE("Graph Class Tests")
{
    SUBCASE("Test isValidGraph")
    {
        ariel::Graph g;
        // Valid graph
        vector<vector<int>> validGraph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        CHECK(g.isValidGraph(validGraph) == true);

        // Invalid graph (not square matrix)
        vector<vector<int>> invalidGraph1 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
        CHECK(g.isValidGraph(invalidGraph1) == false);
    }

    SUBCASE("Test loadGraph")
    {
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
        CHECK_THROWS(g.loadGraph(graph));

        vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 0},
            {1, 0, 3, 0, 0},
            {0, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
        CHECK_NOTHROW(g.loadGraph(graph2));
    }

    SUBCASE("Test getVertices")
    {
        ariel::Graph g;
        // Test an empty graph
        CHECK(g.getVertices() == 0);

        // Test a graph with 3 vertices
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph1);
        CHECK(g.getVertices() == 3);

        // Test a graph with 5 vertices
        vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
        g.loadGraph(graph2);
        CHECK(g.getVertices() == 5);
    }
}