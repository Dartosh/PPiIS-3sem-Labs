#pragma once
#include <vector>
#include <iostream>

class graph
{
public:
	graph() :
		u(0),
		v(0)
	{
		matrix[0][0] = 0;
	}
	~graph()
	{	}

	virtual void set_matrix(const int& vertexes, const int& edges);
	virtual void add_vertex();
	virtual void add_edge(const int& first, const int& sec);
	virtual void del_edge(const int& first, const int& sec);
	virtual void del_vertex(const int& value);
	virtual void print_matrix();
private:
	int u;
	int v;
	std::vector<std::vector<bool>> matrix;
};