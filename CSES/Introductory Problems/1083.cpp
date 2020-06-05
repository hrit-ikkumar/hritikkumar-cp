// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/
	
	int n;
	cin>>n;
	int* num = new int [n-1];
	for(int i=0;i<n-1;i++)
		cin>>num[i];
		
	int ans = 0;
	for(int i=0;i<n-1;i++)
	{
		ans^= ((i+1) ^ num[i]);
	}
	
	ans^=n;
	
	cout<<ans<<endl;
}
