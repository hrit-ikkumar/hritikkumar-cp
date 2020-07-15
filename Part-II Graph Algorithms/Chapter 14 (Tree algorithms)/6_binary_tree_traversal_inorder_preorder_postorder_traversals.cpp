// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

void preorder(vector<vector<int>> &, vector<int> &, int);
void inorder(vector<vector<int>> &, vector<int> &, int);
void postorder(vector<vector<int>> &, vector<int> &, int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(vertices, vector<int>(2, -1));
	for(int i=0;i<edges;i++)
	{
		int start, end; char side;
		cin>>start>>end>>side;
		if(side == 'L' || side=='l')
		graph[start][0] = end;
		else if(side=='R'|| side == 'r')
		graph[start][1] = end;
	}
	vector<int> preorder_traversal(0), inorder_traversal(0), postorder_traversal(0);
	preorder(graph, preorder_traversal, 0);
	inorder(graph, inorder_traversal, 0);
	postorder(graph, postorder_traversal, 0);
	cout<<"PRE-ORDER: ";
	for(int x:preorder_traversal) cout<<x<<" "; 
	cout<<endl;
	cout<<"IN-ORDER: ";
	for(int x:inorder_traversal) cout<<x<<" "; 
	cout<<endl;
	cout<<"POST-ORDER: ";
	for(int x:postorder_traversal) cout<<x<<" "; 
	cout<<endl;
}

void preorder(vector<vector<int>> &graph, vector<int> &ans, int root)
{
	ans.push_back(root); // pre
	if(graph[root][0] != -1)
	preorder(graph, ans, graph[root][0]); // left
	if(graph[root][1] != -1)
	preorder(graph, ans, graph[root][1]); // right
}
void inorder(vector<vector<int>> &graph, vector<int> &ans, int root)
{
	if(graph[root][0] != -1)
	inorder(graph, ans, graph[root][0]); // left
	ans.push_back(root); // in
	if(graph[root][1] != -1)
	inorder(graph, ans, graph[root][1]); // right
}
void postorder(vector<vector<int>> &graph, vector<int> &ans, int root)
{
	if(graph[root][0] != -1)
	postorder(graph, ans, graph[root][0]); // left
	if(graph[root][1] != -1)
	postorder(graph, ans, graph[root][1]); // right
	ans.push_back(root); // post
}
