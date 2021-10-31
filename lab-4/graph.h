#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class vertex
{
public:
	vertex() :
		_data(0)
	{	}

	vertex(const T& node) :
		_data(node)
	{	}

	T get_data()
	{
		return _data;
	}

private:
	T _data;
};

class edge
{
public:

	edge() :
		_from(0),
		_to(0)
	{	}
	edge(const int& from, const int& to) :
		_from(from),
		_to(to)
	{	}

	int get_from()
	{
		return _from;
	}
	int get_to()
	{
		return _to;
	}

	void set_from(const int& from)
	{
		_from = from;
	}
	void set_to(const int& to)
	{
		_to = to;
	}

private:
	int _from, _to;
};

template <typename T>
class graph
{
public:
	graph(void) {};
	~graph(void) {};

	void add_vertex(const T& data);								//Addition
	int find_vertex(const T& data);								//Search by value
	void delete_vertex(const T& data);								//Daletion by value

	void add_edge(const int& from, const int& to);				//Addition by number
	void add_edge(const T& from, const T& to);					//Addition by value
	bool find_edge(const int& from, const int& to);				//Search by number
	int find_edge(const T& from, const T& to);					//Search by value
	void delete_edge(const int& from, const int& to);			//Deletion by number
	void delete_edge(const T& from, const T& to);				//Deletion by value
	void print_graph();											//Show graph
	int get_vertexes_size();

	bool is_empty(void);										//Check for content
	void clear_graph(void);										//Clear graph
	
	class vertex_iterator
	{
	public:
		vertex_iterator(graph<T>& graph)
		{
			Iteration = &graph;
			count = 0;
		};

		bool next();											//Next
		bool prev();											//Prevous
		void incident_vertexes();								//Show incident vertexes
	private:
		graph<T>* Iteration;
		int count;
	};
private:
	vector<vertex<T>> _vertexes;
	vector<edge> _edges;
};


//Addition
template<typename T>
inline void graph<T>::add_vertex(const T& data)
{
	if (find_vertex(data) == -1)
		_vertexes.push_back(vertex<T>(data));
	else
		cout << "Not founded!" << endl;
}

//Search by value
template<typename T>
inline int graph<T>::find_vertex(const T& data)
{
	for (int i = 0; i < _vertexes.size(); ++i)
		if (_vertexes[i].get_data() == data)
			return i;
	return -1;
}

//Daletion by value
template<typename T>
inline void graph<T>::delete_vertex(const T& data)
{
	int vertex_num = find_vertex(data);
	if (vertex_num != -1)
	{
		_vertexes.erase(_vertexes.begin() + vertex_num);
		for (int i = 0; i < _edges.size(); ++i)
			if (find_edge(i, vertex_num))
				delete_edge(i, vertex_num);
	}
}

//Addition by number
template<typename T>
inline void graph<T>::add_edge(const int& from, const int& to)
{
	if (find_edge(from, to) == false)
		_edges.push_back(edge(from, to));
}

//Addition by value
template<typename T>
inline void graph<T>::add_edge(const T& from, const T& to)
{
	int first = find_vertex(from), sec = find_vertex(to);
	if (first != -1 && sec != -1 && find_edge(first, sec) == false)
		_edges.push_back(edge(find_vertex(from), find_vertex(to)));

}

//Search by number
template<typename T>
inline bool graph<T>::find_edge(const int& from, const int& to)
{
	for (int i = 0; i < _edges.size(); ++i)
		if (_edges[i].get_from() == from && _edges[i].get_to())
			return true;
	return false;
}

//Search by value
template<typename T>
inline int graph<T>::find_edge(const T& from, const T& to)
{
	for (int i = 0; i < _edges.size(); ++i)
		if (_vertexes[_edges[i].get_from()].get_data() == from && _vertexes[_edges[i].get_to()].get_data() == to)
			return i;
	return -1;
}

//Deletion by number
template<typename T>
inline void graph<T>::delete_edge(const int& from, const int& to)
{
	for (int i = 0; i < _edges.size(); ++i)
		if (find_edge(from, to) == true)
		{
			_edges.erase(_edges.begin() + i);
			for (int k = i; k < _edges.size(); ++k)
				_edges[k] = _edges[k + 1];
			if (_edges.size() != 0)
				_edges.pop_back();
		}
}

//Deletion by value
template<typename T>
inline void graph<T>::delete_edge(const T& from, const T& to)
{
	for (int i = 0; i < _edges.size(); ++i)
		if (find_edge(from, to) != -1)
			_edges.erase(_edges.begin() + i);
}


//Show graph
template<typename T>
inline void graph<T>::print_graph()
{
	for (int i = 0; i < _edges.size() ; ++i)
		cout << _vertexes[_edges[i].get_from()].get_data() << " ---> " << _vertexes[_edges[i].get_to()].get_data() << endl;
}

template<typename T>
inline int graph<T>::get_vertexes_size()
{
	return _vertexes.size();
}

//Check for content
template<typename T>
inline bool graph<T>::is_empty(void)
{
	if (_vertexes.size() == 0)
		return true;
	return false;
}

//Clear graph
template<typename T>
inline void graph<T>::clear_graph(void)
{
	_vertexes.clear();
	_edges.clear();
}

//Next
template<typename T>
inline bool graph<T>::vertex_iterator::next()
{
	if (Iteration->_vertexes.size() <= count + 1)
	{
		return false;
	}
	count++;
	return true;
}

//Previous
template<typename T>
inline bool graph<T>::vertex_iterator::prev()
{
	if (count == 0)
	{
		return false;
	}
	count--;
	return true;
}

//Get incident vertexes
template<typename T>
inline void graph<T>::vertex_iterator::incident_vertexes()
{
	short count2 = 0;
	for (int i = 0; i < Iteration->_vertexes.size(); ++i)
	{
		if (Iteration->find_edge(count, i) == true)
		{
			count2++;
			cout << Iteration->_vertexes[count].get_data() << " ---> " << Iteration->_vertexes[i].get_data() << endl;
		}
	}
	if (count2 == 0)
	{
		cout << "Not found!" << endl;
	}
}
