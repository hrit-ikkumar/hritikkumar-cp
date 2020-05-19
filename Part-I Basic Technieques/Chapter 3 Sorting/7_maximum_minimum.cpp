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
	int* a= new int[n];
	for(int i=0;i<n;i++)cin>>a[i]; 
	int k; 
	cin>>k; 
	// for lower bound
	int index =-1;
	for(int b = n/2; b>=1; b/=2)
	{
		while( (index + b) < n && a[index+b] < k) 
			index += b;
	}
	// index is the value till where we have elements less than k so our answer is index +1
	cout<<index+1<<endl;
	
	// Here, You have a array which first increasing than decreasing 
	// like this 1 2 3 4 5 4 3 2 1. In this array you have to find the maximum number;
	// We will take input again
	for(int i=0;i<n;i++)cin>>a[i];
	index = -1;
	for(int b = n/2; b>=1;b/=2)
	{
		while((index + b) < n && a[index+b] < a[index+b+1])
			index +=b;
	}
	// same thing is here we are reaching to the element which is 
	cout<<index + 1<<endl;
	return 0; // return type is int
}
