#include "graph.h"

void graph::set_matrix(const int& vertexes, const int& edges)
{
    v = vertexes;
    u = edges;

    for (int i = 0; i < v; ++i)
    {
        std::vector<bool> temp(v);
        for (int j = 0; j < v; ++j)
            temp[j] = false;
        matrix.push_back(temp);
    }
}

void graph::add_vertex()
{
    for (int i = 0; i < v; ++i)
        matrix[i].push_back(false);

    std::vector<bool> temp(v+1);
    for (int i = 0; i < v + 1; ++i)
        temp[i] = false;

    matrix.push_back(temp);
    ++v;
    return void();
}

void graph::add_edge(const int& first, const int& sec)
{
    matrix[first][sec] = matrix[sec][first] = true;
    ++u;
    return void();
}

void graph::del_edge(const int& first, const int& sec)
{
    matrix[first][sec] = matrix[sec][first] = false;
    --u;
    return void();
}

void graph::del_vertex(const int& value)
{
    if (value > v)
        std::cout << "Error!" << std::endl;
    else
    {
        for (int i = 0; i < v; ++i)
            matrix[i].erase(matrix[i].begin() + (value - 1));
        matrix.erase(matrix.begin() + (value - 1));
    }
    --v;
    return void();
}

void graph::print_matrix()
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
            std::cout << matrix[i][j] << "  ";
        std::cout << std::endl;
    }
}
