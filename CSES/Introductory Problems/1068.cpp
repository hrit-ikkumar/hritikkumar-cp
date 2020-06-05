
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
	#endif
	*/
	long long int n;
	cin>>n;
	cout<<n;
	while(n!=1)
	{
		if(n%2==0)
			n /= 2;
		else
			n = 3*n + 1;
		cout<<" "<<n;
	}
	cout<<endl; // new line
	
	return 0; //return type is int
}
