// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std;  // namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif
	/*
					set syntax	bit syntax
	intersection 	a ∩ b		a & b
	union 			a ∪ b		a | b
	complement 		ā			~ a
	difference 		a \ b		a & (~ b )
	*/
	
	int x = 0;
	x |= (1<<1);
	x |= (1<<3);
	x |= (1<<4);
	x |= (1<<8);
	cout<<__builtin_popcount(x)<<endl;
	for(int i=0;i<32;i++)
		if(x&(1<<i)) cout<<i<<" ";
	
	int y = (1<<3) | (1<<6) | (1<<8) | (1<<9);
	int z = x | y;
	cout<<__builtin_popcount(z)<<endl;
	
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int k;
	cin>>k;
	// print all the subset size of exactly k
	for(int b = 0;b<(1<<n); b++)
	{
		if(__builtin_popcount(b) ==k)
		{
			for(int i=0;i<n;i++)
			{
				if(b & (1<<i))
					cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
	// print all the subsets of given set (x is the bit number)
	cin>>x;
	int b = 0;
	do{
		for(int i=0;i<n;i++)
		{
			if(b & (1<<i))
				cout<<a[i]<<" ";
		}
		cout<<endl;
	}while((b=((b-x)&x)));
	
	return 0; // return type is int
}
