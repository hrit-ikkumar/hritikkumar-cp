// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	
	#ifndef OLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	multiset<pair<int, int> > ms;
	for(int i=0;i<n;i++)
	{
		int start , end;
		cin>>start>>end;
		ms.insert(make_pair(start, end));
	}
	for(pair pr: ms)
		cout<<pr.first<<" "<<pr.second<<endl;
		
		
	return 0; //return type is int
}
