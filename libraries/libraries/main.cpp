#include <iostream>
#include <string>
#include <list>

#include "gridGraph.h"

using namespace std;

string to_stringPair(std::pair<int,int> p)
{
	string s = "("+to_string( p.first) + "," + to_string(p.second)+")";
	return s;
}

int main()
{
	

	gridGraph g;
	//ofstream out("out.txt");
	cout << g.run("test.txt");
	/*
	g.load("test.txt");
	
	for(int i = 0; i < 2; i++)
	{
		std::pair<int,int> start = g.randPos();
		std::pair<int,int> end = g.randPos();
		out << to_stringPair(start) <<" - " << to_stringPair(end) << "\n";
		out << g.findPath(start, end);
		out << "\n";
	}
	out.close();
	//g.run("test.txt");
	//cout << "\n";
	//g.run("in.txt");
	/*
	Graph<string,GraphType::Directed,double> graph;
	graph.MakeEdge( "hall", "foyer", 3 );
	graph.MakeEdge( "hall", "ocean", 2 );
	graph.MakeEdge( "hall", "mountains", 1 );

	graph.MakeEdge( "mountains", "hall", 1 );
	graph.MakeEdge( "mountains", "foyer", 1 );
	graph.MakeEdge( "mountains", "roof", 2 );

	graph.MakeEdge( "roof", "forest", 3 );

	graph.MakeEdge( "ocean", "hall", 2 );
	graph.MakeEdge( "ocean", "shire", 1 );

	graph.MakeEdge( "shire", "foyer", 1 );
	graph.MakeEdge( "shire", "pit", 1 );

	graph.MakeEdge( "pit", "foyer", 1 );
	graph.MakeEdge( "pit", "dungeon", 3 );

	graph.MakeEdge( "foyer", "hall", 3 );
	graph.MakeEdge( "foyer", "dungeon", 2 );
	graph.MakeEdge( "foyer", "shire", 1 );
	graph.MakeEdge( "foyer", "pit", 1 );

	graph.MakeEdge( "forest", "roof", 3 );
	graph.MakeEdge( "forest", "dungeon", 3 );
	graph.MakeEdge( "forest", "treasureRoom", 1 );

	graph.MakeEdge( "dungeon", "foyer", 2 );
	graph.MakeEdge( "dungeon", "treasureRoom", 12 );

	graph.MakeEdge( "treasureRoom", "dungeon", 12 );
	graph.MakeEdge( "treasureRoom", "forest", 1 );
	Graph<string,GraphType::Directed, double> path;
	path = dijkstra<string,GraphType::Directed,double>(graph,"hall", "treasureRoom");
	/*
	Graph<string, GraphType::Directed, double> G;
	G.MakeEdge("(0,0)", "(0,1)", 1);
	G.MakeEdge("(0,0)", "(0,1)", 2);

	G.MakeEdge("(0,1)", "(0,0)", 3);
	G.MakeEdge("(0,1)", "(0,2)", 4);
	G.MakeEdge("(0,1)", "(1,0)", 2);

	G.MakeEdge("(1,0)", "(0,1)", 1);
	G.MakeEdge("(1,0)", "(1,1)", 2);
	G.MakeEdge("(1,0)", "(2,0)", 5);

	G.MakeEdge("(1,1)", "(0,1)", 2);
	G.MakeEdge("(1,1)", "(1,0)", 3);
	G.MakeEdge("(1,1)", "(1,2)", 4);
	G.MakeEdge("(1,1)", "(2,1)", 7);

	G.MakeEdge("(0,2)", "(0,1)", 1);
	G.MakeEdge("(0,2)", "(1,2)", 2);

	G.MakeEdge("(2,0)", "(1,0)", 2);
	G.MakeEdge("(2,0)", "(2,1)", 3);

	G.MakeEdge("(1,2)", "(0,2)", 5);
	G.MakeEdge("(1,2)", "(1,1)", 1);
	G.MakeEdge("(1,2)", "(2,2)", 2);

	G.MakeEdge("(2,1)", "(1,1)", 6);
	G.MakeEdge("(2,1)", "(2,0)", 3);
	G.MakeEdge("(2,1)", "(2,2)", 8);

	G.MakeEdge("(2,2)", "(1,2)", 2);
	G.MakeEdge("(2,2)", "(2,1)", 3);
	//(0,0)(0,1)(0,2)
	//(1,0)(1,1)(1,2)
	//(2,0)(2,1)(2,2)
	G = dijkstra<string, GraphType::Directed,double>(G,"(0,0)", "(2,2)");
	cout << "";
	//*/
	system("pause");
	return 0;
}