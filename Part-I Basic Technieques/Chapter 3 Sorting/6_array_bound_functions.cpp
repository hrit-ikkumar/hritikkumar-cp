#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std 

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
	cin>>k; 
	// It is compulsory that your array is sorted otherwise this function will fail
	auto lb = lower_bound(a, a+n, k)  - a;
	auto ub = upper_bound(a, a+n, k) - a;
	
	cout<<lb<<","<<ub<<endl;
	cout<<"Range is: "<<ub-lb<<endl; 
	
	// Ther is another function which you can use 
	auto pair_bound = equal_range(a, a+n , k);
	cout<<pair_bound.first - a<<", "<<pair_bound.second-a<<endl;
	cout<<pair_bound.second - pair_bound.first<<endl;
	
	return 0; //return type is int 
}
