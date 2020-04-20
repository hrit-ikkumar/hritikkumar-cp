// @hritikkumar
#include<bits/stdc++.h> // all header files
using namespace std;

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cout<<"Sum of N natuaral numbers: N? : ";
	cin>>n;
	cout<<n*(n+1)/2<<endl;
	return 0; 
}
