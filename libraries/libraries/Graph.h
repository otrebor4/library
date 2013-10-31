#ifndef GRAPH_H
#define GRAPH_H

#include <list>
using std::list;


template<typename DATA_TYPE, typename WEIGHT>
class edge;
template<typename DATA_TYPE, typename WEIGHT>
class vertex;

template<typename DATA_TYPE, typename WEIGHT_TYPE>
class edge
{
private:
	typedef edge<DATA_TYPE, WEIGHT_TYPE> Edge;
	typedef vertex<DATA_TYPE, WEIGHT_TYPE> Vertex;
	bool have( list<Edge *> list, Edge * check)
	{
		for(Edge * e : list)
			if((e) == (check))
				return true;

		return false;
	}
public:
	WEIGHT_TYPE weight;
	vertex<DATA_TYPE,WEIGHT_TYPE> * start;
	vertex<DATA_TYPE,WEIGHT_TYPE> * end;
	edge(WEIGHT_TYPE _weight, Vertex * _start, Vertex * _end)
	{
		weight  =_weight;
		start = _start;
		end = _end;
	}

	~edge()
	{
		start->edgesOut.remove(this);
		end->edgesIn.remove(this);
	}
};

template<typename DATA_TYPE, typename WEIGHT_TYPE = double>
class vertex
{
private:
	typedef edge<DATA_TYPE, WEIGHT_TYPE> Edge;
	typedef vertex<DATA_TYPE, WEIGHT_TYPE> Vertex;
	void AddEdgeIn(Edge * tedge)
	{
		//Edge * tedge = new Edge(w,v,this);
		edgesIn.push_back(tedge);
	}
public:
	DATA_TYPE data;
	list<Edge *> edgesOut;
	list<Edge *> edgesIn;

	vertex(){}
	vertex(DATA_TYPE t)
	{
		data = t;
	}

	~vertex()
	{
		vector<Edge *> es;
		for(Edge * e : edgesIn){
			es.push_back(e);
		}
		for(Edge * e : edgesOut){
			es.push_back(e);
		}
		
		for(int i = 0; i < es.size(); i++)
		{
			Edge * e = es[i];
			delete e;
		}
		edgesOut.clear();
		edgesIn.clear();
		
	}

	void AddEdge(Vertex * v, WEIGHT_TYPE w)
	{
		Edge * tedge = new Edge(w, this, v);
		edgesOut.push_back(tedge);
		v->AddEdgeIn(tedge);
	}
};

enum GraphType
{
	Undirected,
	Directed,
};

template<typename DATA_TYPE, GraphType GRAPHTYPE = GraphType::Undirected, typename WEIGHT_TYPE = double>
class Graph
{
private:
	typedef vertex<DATA_TYPE, WEIGHT_TYPE> Vertex;
	typedef edge<DATA_TYPE, WEIGHT_TYPE> Edge;
	list<Vertex *> vertextList;

	Vertex * findVertex(DATA_TYPE t )
	{
		for(Vertex * v : vertextList)
			if(v->data == t)
				return v;
		return NULL;
	}

	//===================================================
	void AddEdgeUndirected(DATA_TYPE a,DATA_TYPE b, WEIGHT_TYPE w)
	{
		Vertex * v1 = findVertex(a);
		Vertex * v2 = findVertex(b);
		if(v1 != NULL && v2 != NULL)
		{
			v1->AddEdge(v2,w);
			v2->AddEdge(v1,w);
		}
	}

	void AddEdgeDirected(DATA_TYPE a, DATA_TYPE b, WEIGHT_TYPE w)
	{
		Vertex * v1 = findVertex(a);
		Vertex * v2 = findVertex(b);
		if(v1 != NULL && v2 != NULL)
		{
			v1->AddEdge(v2,w);
		}
	}


public:
	Graph(){}
	
	Graph(Graph & other)
	{
		for(Vertex * v : other.vertextList)
		{
			AddVertex( v->data);
		}
		for(Edge * e : other.getEdges())
		{
			MakeEdge( e->start->data, e->end->data, e->weight);
		}
	}

	~Graph()
	{
		clear();
	}

	void AddVertex(DATA_TYPE data)
	{
		Vertex * t = new Vertex(data);
		vertextList.push_back(t);
	}

	template<GraphType TYPE>
	void AddEdge(DATA_TYPE a, DATA_TYPE b, WEIGHT_TYPE w = default(WEIGHT_TYPE))
	{
		switch (TYPE)
		{
		case Undirected:
			AddEdgeUndirected(a,b,w);
			break;
		case Directed:
			AddEdgeDirected(a,b,w);
			break;
		default:
			break;
		}
	}

	void AddEdge(DATA_TYPE a, DATA_TYPE b, WEIGHT_TYPE w = default(WEIGHT_TYPE))
	{
		switch (GRAPHTYPE)
		{
		case Undirected:
			AddEdgeUndirected(a,b,w);
			break;
		case Directed:
			AddEdgeDirected(a,b,w);
			break;
		default:
			break;
		}
	}
	
	template<GraphType TYPE>
	void MakeEdge(DATA_TYPE a, DATA_TYPE b, WEIGHT_TYPE w )
	{
		Vertex * v = findVertex(a);
		if(v == NULL)
			AddVertex(a);
		v = findVertex(b);
		if(v == NULL)
			AddVertex(b);
		AddEdge<TYPE>(a,b,w);
	}

	void MakeEdge(DATA_TYPE a, DATA_TYPE b, WEIGHT_TYPE w )
	{
		Vertex * v = findVertex(a);
		if(v == NULL)
			AddVertex(a);
		v = findVertex(b);
		if(v == NULL)
			AddVertex(b);
		AddEdge(a,b,w);
	}

	Edge * getEdges(DATA_TYPE a, DATA_TYPE b)
	{
		Vertex * _a = getVertex(a);
		for(Edge * e : _a->edgesOut)
		{
			if(e->end->data == b)
				return e;
		}
		return NULL;
	}

	Vertex * getVertex(DATA_TYPE a)
	{
		return findVertex(a);
	}
	list<Vertex *> getVertexs()
	{
		return vertextList;
	}
	list<Edge *> getEdges()
	{
		list<Edge *> edges;
		for(Vertex * v : vertextList)
		{
			for(Edge * e : v->edgesOut)
				edges.push_back(e);
		}
		return edges;
	}

	void clear()
	{
		for(Edge * e : getEdges())
			delete e;
		for(Vertex * v : vertextList)
			delete v;
		vertextList.clear();
	}

	void display()
	{
		for each(Vertex * x in vertextList)
		{
			x->display();
		}
	}

};

#endif