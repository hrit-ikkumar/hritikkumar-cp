// @hritikkumar

#include<bits/stdc++.h> // all header files

using namespace std; 

class DeBruijnGraph
{
	public:
		unordered_set<string> seen;
		vector<int> edges;
		string A = "01", deBruijnSequence;
		int n, k;
	public:
		DeBruijnGraph() {}
		DeBruijnGraph(int N, int K)
		{
			this->n = N;
			this->k = K;
		}
		
		void runScript()
		{
			print_everthing();
			deBruijnSequence = deBrujin();
			cout<<"SEQUENCE: "<<deBruijnSequence<<endl;
		}
		
		string deBrujin()
		{
			seen.clear();
			edges.clear();
			string startingNode = string(n-1, A[0]);
			dfs(startingNode);
			
			string S;
			
			int l = pow(k, n);
			for(int i=0;i<l;i++)
			{
				S += A[edges[i]];
			}
			S += startingNode;
			
			return S;
		}
		
		void dfs(string node)
		{
			for(int i=0;i<k;i++)
			{
				string str = node + A[i];
				if(seen.find(str) == seen.end())
				{
					seen.insert(str);
					dfs(str.substr(1));
					edges.push_back(i);
				}
			}
		}
		
		void print_everthing()
		{
			cout<<"N: "<<n<<", K:"<<k<<endl;
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int N, K;
	cin>>N>>K;
	DeBruijnGraph* deBruijnGraph = new DeBruijnGraph(N, K);
	deBruijnGraph -> runScript();
	
	return 0; // return type is int
}
