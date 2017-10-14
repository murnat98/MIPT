#include <vector>
#include <iostream>

using Graph_t = std::vector<std::vector<int> >;

class Graph
{
public:
    Graph(size_t size = DEFAULT_SIZE);

    void read();
    void print();
    void print_used();

    void dfs(int vertex);

private:
    static const int DEFAULT_SIZE = 3;

    Graph_t graph;
    std::vector<bool> used;

    size_t size;
};

int main()
{
    Graph graph;
    graph.read();

    graph.dfs(0);

    graph.print();
    graph.print_used();

    return 0;
}

Graph::Graph(size_t size) :
    size(size)
{
    graph.resize(size);
    for(auto& edges : graph)
    {
        edges.resize(size);
    }

    used.resize(size);
    used.insert(used.begin(), size, false);
}

void Graph::read()
{
    for (auto& edges : graph)
    {
        for (auto& vertex : edges)
        {
            std::cin >> vertex;
        }
    }
}

void Graph::print()
{
    for (const auto& edges : graph)
    {
        for (const auto& vertex : edges)
        {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::print_used()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << used[i] << std::endl;
    }
}

void Graph::dfs(int vertex)
{
    used[vertex] = true;

    for (const auto& vertexes : graph[vertex])
    {
        if (!used[vertexes])
        {
            dfs(vertexes);
        }
    }
}