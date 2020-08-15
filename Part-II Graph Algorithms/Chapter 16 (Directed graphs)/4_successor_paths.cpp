// hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std 

void dfsXK(vector<vector<int>> & , int ,int ,vector<vector<int>> &, vector<int> &);
vector<vector<int>> succPathXKFun(vector<vector<int>> &, vector<int> &);

void dfs(vector<vector<int>> &,int, vector<int> &);
vector<int> succPathFun(vector<vector<int>> &);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>(0));
	for(int i=0;i<edges;++i)
	{
		int start, end;
		cin>>start>>end;
		graph[start].push_back(end);
	}
	// Successor Graph or Functional Graphs
	/* Out-Degree = 1
	 * Cotain Multiple Component and in each one of those component, there will be only one cycle.
	 */
	// Successor from Node = 1
	vector<int> successor = succPathFun(graph);
	for(int i=0;i<vertices;i++)
	cout<<i+1<<" ";
	cout<<endl;
	for(int x: successor)
	cout<<x+1<<" ";
	cout<<endl<<endl;
	
	// Successor from all possiblities
	// succ(x, k) from k to x (k -> x)
	vector<vector<int>> succ_x_k = succPathXKFun(graph, successor);
	cout<<"  ";
	for(int i=1;i<(signed) succ_x_k[0].size();i*=2)
	cout<<i<<" ";
	cout<<endl;
	for(int i=1;i< (signed)succ_x_k.size();i++)
	{
		cout<<i<<" ";
		for(int j=1;j<(signed) succ_x_k[0].size(); j*=2)
		{
			cout<<succ_x_k[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0; // return type is int
}

void dfsXK(vector<vector<int>> &graph, int row, int col, vector<vector<int>> &ans, vector<int> &succ)
{	
	if(col == 1)
	{
		ans[row][col] = succ[row-1]+1;
	}
	else if(col > 1)
	{
		dfsXK(graph, row, col/2, ans, succ);
		dfsXK(graph, ans[row][col/2], col/2, ans, succ);
		ans[row][col] = ans[ans[row][col/2]][col/2];
	}
}

vector<vector<int>> succPathXKFun(vector<vector<int>> &graph, vector<int> &succ)
{
	vector<vector<int>> ans(graph.size()+1, vector<int>(graph.size() + 1, -1));
	for(int row=1;row<=(signed) graph.size();row++)
	{
		for(int col=1; col<= (signed) graph.size(); col*=2)
		{
			dfsXK(graph, row,col, ans, succ);
		}
	}
	return ans;
}

void dfs(vector<vector<int>> &graph,int root, vector<int> &succ)
{
	if(succ[root] == -1)
	{
		succ[root] = graph[root][0];
	}
}

vector<int> succPathFun(vector<vector<int>> &graph)
{
	vector<int> ans(graph.size(), -1);
	for(int i=0;i<(signed)graph.size();i++)
	{
		dfs(graph,i, ans);
	}
	return ans;
}
