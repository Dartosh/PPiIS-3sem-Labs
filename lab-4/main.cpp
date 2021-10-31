#include "graph.h"
#include <gtest/gtest.h>
using namespace std;

TEST(GetVertexesSizeTest1)
{
	graph<string> G;
	EXPECT_EQ(0, G.get_vertexes_size());
}

TEST(GetVertexesSizeTest2)
{
	graph<string> G;
	G.add_vertex("1");
	G.add_vertex("2");
	G.add_vertex("3");
	G.add_vertex("4");
	EXPECT_EQ(4, G.get_vertexes_size());
}

TEST(GetVertexesSizeTest3)
{
	graph<string> G;
	G.add_vertex("1");
	G.add_vertex("2");
	G.delete_vertex("2");
	EXPECT_EQ(1, G.get_vertexes_size());
}

TEST(FindVertexTest4)
{
	graph<string> G;
	EXPECT_EQ(true, G.is_empty());
}

TEST(FindVertexTest5)
{
	graph<string> G;
	G.add_vertex("2");
	EXPECT_EQ(0, G.find_vertex("2"));
}

TEST(FindEdgeTest6)
{
	graph<string> G;
	G.add_vertex("1");
	G.add_vertex("2");
	G.add_edge("1", "2");
	EXPECT_EQ(0, G.find_edge("1", "2"));
}

int main(int a, char* b[])
{
	testing::InitGoogleTest(&a, b);
	return RUN_ALL_TESTS();
}