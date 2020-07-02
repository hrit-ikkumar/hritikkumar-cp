// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int vertices, edges;
	
	// Unweighted graph
	cin>>vertices>>edges;
	vector<pair<int, int>> graph_unw(0);
	for(int i=0;i<edges;i++)
	{
		int start, end;
		cin>>start>>end;
		graph_unw.push_back({start, end});
	}
	for(int i=0;i<edges;i++)
	cout<<graph_unw[i].first+1<<" --> "<<graph_unw[i].second+1<<endl;
	cout<<endl;
	
	// Weighted graph
	cin>>vertices>>edges;
	vector<tuple<int, int, int>> graph_w(0);
	for(int i=0;i<edges;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		graph_w.push_back({start, end, weight});
	}
	for(int i=0;i<edges;i++)
	cout<<get<0>(graph_w[i])+1<<" --> "<<get<1>(graph_w[i])+1<<" ["<<get<2>(graph_w[i])<<"]"<<endl;
	cout<<endl;
	return 0; // return type is int
}
