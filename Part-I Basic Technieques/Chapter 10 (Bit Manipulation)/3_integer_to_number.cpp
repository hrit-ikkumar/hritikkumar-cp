// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std;

string intToBinary(int);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int num;
	cin>>num;
	string binary = intToBinary(num);
	cout<<binary<<endl;
	int k; cin>>k;
	int num1 = num | (1<<k);
	binary = intToBinary(num1);
	cout<<binary<<endl;
	int num2 = num & ~(1<<k);
	binary = intToBinary(num2);
	cout<<binary<<endl;
	int num3 = num ^ (1<<k);
	binary = intToBinary(num3);
	cout<<binary<<endl;
	return 0; // return type is int
}

string intToBinary(int num)
{
	string ans = "";
	for(int i=31;i>=0;i--)
	{
		if( num&(1<<i) )	ans += '1';
		else				ans += '0';
	}
	return ans;
}
