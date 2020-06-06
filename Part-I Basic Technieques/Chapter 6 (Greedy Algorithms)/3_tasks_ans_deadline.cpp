// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

vector<pair<int, int>> tasksAndDeadline(int *, int *, int );

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);  // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* duration = new int[n], * deadline = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>duration[i]>>deadline[i];
	}
	
	vector	<pair<int, int>> ans = tasksAndDeadline(duration, deadline, n);
	for(pair<int, int> task: ans)
	{
		cout<<task.first<<" "<<task.second<<endl;
	}
	
	return 0; //return type is int
}

vector<pair<int, int>> tasksAndDeadline(int *duration, int* deadline, int n)
{
	
}
