// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

int maximumTasksScheduling(multiset<pair<int, int>> , int );

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	
	#ifndef OLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	multiset<pair<int, int> > ms; // first-> end_time, second->start_time
	for(int i=0;i<n;i++)
	{
		int start , end;
		cin>>start>>end;
		ms.insert(make_pair(end, start));
	}
	
	int ans = maximumTasksScheduling(ms, n);
	
	cout<<ans<<endl; 
	
	return 0; //return type is int
}

int maximumTasksScheduling(multiset<pair<int, int>> ms, int n)
{
	int start = 0, end = 0;
	for(pair<int, int> pr: ms)
	{
		
	}
}
