// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

/*
 * 	For unordered Graph, We must have strongly connected component only one
	Graph								Unordered Graph																								Ordered Graph
	
	Eulerian Circuit (EC		Every Vertex has an even degree																		Every Vertex has equal indegree and outdegree
	
	Eulerian Path	(EP)			Every Vertex has an even degree or exactly two vertices has odd degree			At most one Vertex has (outdegree - indegree) = 1 and one Vertex has (indegree - outdegree) = 1 and all other vertices have equal indegree and outdegree
 */
// Hierholzer's Algorithm works only for Directed Graphs

class EuleiranPathGraph
{
	public:
		vector<vector<int>> graph;
		vector<int> inDegree, outDegree;
		int vertices, edges;
	public:
		EuleiranPathGraph() {}
		EuleiranPathGraph(int v, int e,vector<vector<int>> dirGraph)
		{
			this->vertices = v;
			this->edges = e;
			this->graph = dirGraph;
			this->inDegree.resize(this->vertices, 0);
			this->outDegree.resize(this->vertices, 0);
		}
		
		void runScript()
		{
			calculateDegres(); // calculate all the indegress and outdegrees  of directed graph
			printEverything(); // checking for in and out degree is correct or not?
			if(checkWheaterWeCanFindEulerianPath())
			{
				// do something here
				cout<<"We can find the eulerian path in given graph.."<<endl;
			}
			else
			{
				cout<<"Can not find the eulerian path in given graph..."<<endl;
				return;
			}
		}
		
		void calculateDegres()
		{
			for(int node = 0; node < vertices; node++)
			{
				for(int child:graph[node])
				{
					this->outDegree[node] += 1;
					this->inDegree[child] += 1;
				}
			}
		}
		
		bool checkWheaterWeCanFindEulerianPath()
		{
			int inMinusOut = 0, outMinuxIn = 0;
			for(int i=0;i<this->vertices;i++)
			{
				if( (this -> inDegree[i] - this->outDegree[i]) == 1) // first case when two of them is having difference 1
					inMinusOut +=1;
				else if( (this->outDegree[i] - this->inDegree[i]) == 1)
					outMinuxIn += 1;
				else if(abs(this->inDegree[i] - this->outDegree[i]) > 1) // more than 1 difference can't be accepted here
				{
					return false;
				}
			}
			// either 0 or 1 could be the difference between two ins and outs
			if( (inMinusOut == 0 && outMinuxIn == 0) ||
				(inMinusOut == 1 && outMinuxIn == 1))
				return true;
			return false;
		}
		
		void printEverything()
		{
			cout<<"GRAPH: "<<endl;
			for(int node = 0; node < vertices; node++)
			{
				cout<<"NODE - "<<node<<": ";
				for(int child:graph[node])
					cout<<child<<" ";
				cout<<endl;
			}
			cout<<endl;
			
			cout<<"inDegrees:"<<endl;
			for(int node = 0; node < vertices; node ++)
			{
				cout<<node<<": "<<inDegree[node]<<endl;
			}
			cout<<endl;
			
			cout<<"outDegrees:"<<endl;
			for(int node = 0; node < vertices; node ++)
			{
				cout<<node<<": "<<outDegree[node]<<endl;
			}
			cout<<endl;
		}
		
};



int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int verticesLocal, edgesLocal;
	cin>>verticesLocal>>edgesLocal;
	vector<vector<int>> graphLocal(verticesLocal);
	for(int i=0;i<edgesLocal;i++)
	{
		int start, end;
		cin>>start>>end;
		graphLocal[start].push_back(end);
	}
	EuleiranPathGraph* directedGraph = new EuleiranPathGraph(verticesLocal, edgesLocal, graphLocal);
	directedGraph -> runScript();
	
	return 0; // return type is int
}
