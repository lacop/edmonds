#include <iostream>

#include "EdmondsMatching.hpp"

int main(int argc, char *argv[])
{
    int n, m;
    std::cin >> n >> m;

    if (n % 2 == 1)
    {
        std::cout << "NO" << std::endl;
        return 1;
    }

    EdmondsMatching matching(n);
    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        std::cin >> v1 >> v2 >> w;

        // Input is indexed from 1
        matching.addEdge(v1 - 1, v2 - 1, w);
    }

    bool success = matching.findMinimumWeightMatching();
    if (!success)
    {
        std::cout << "NO" << std::endl;
        return 1;
    }

    int weight = matching.getMatchingWeight();
    auto edges = matching.getMatchedEdges();
    std::cout << weight << std::endl;
    for (auto e: edges)
        std::cout << e.first << " " << e.second << std::endl;

    return 0;
}
