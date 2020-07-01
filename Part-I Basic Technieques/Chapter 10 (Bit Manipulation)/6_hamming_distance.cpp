// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int hammingDistance(string, string);

int hammingDistance(int , int );

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	/*The Hamming distance hamming ( a, b ) between two strings a and b of equal
	length is the number of positions where the strings differ. For example,
		hamming (01101, 11001) = 2.
	*/
	
	string a, b;
	cin>>a>>b;
	int ans = hammingDistance(a, b);
	cout<<ans<<endl;
	
	int num1, num2;
	cin>>num1>>num2;
	ans = hammingDistance(num1, num2);
	cout<<ans<<endl;
	
	return 0; // return type is int
}

int hammingDistance(string a, string b)
{
	int d = 0;
	for(int i=0;i<(signed)a.size() && i<(signed)b.size(); ++i)
	{
		if(a[i] != b[i])	++d;
	}
	return d;
}

int hammingDistance(int a, int b)
{
	return __builtin_popcount(a^b);
}
