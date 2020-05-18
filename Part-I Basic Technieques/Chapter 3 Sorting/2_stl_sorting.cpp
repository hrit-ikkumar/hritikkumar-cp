#include<bits/stdc++.h> // all header files

using namespace std; //namespace created as std

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	sort(a, a+n); 
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
	
	return 0; //return type is int 
}
