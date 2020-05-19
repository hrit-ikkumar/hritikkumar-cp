#include<bits/stdc++.h> // all header files

using namespace std; //naemspace created as std

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i]; 
	int k; 
	cin>>k; // number which to be finded
	
	int index = 0;
	for(int b = n/2; b>=1; b/=2)
	{
		while( (index + b) < n && a[index+b] <= k) 
			index += b;
			
		if(a[index] == k)
		break;
	}
	if(a[index] == k)
		cout<<index<<endl;
	else
		cout<<-1<<endl;
	return 0; //return type is int
}
