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
	cin>>num; // integer to number
	string binary = intToBinary(num);
	cout<<binary<<endl;
	
	int k; cin>>k; // kth bit (0-based from right to left)
	int num1 = num | (1<<k); // set kth bit of num to 1
	binary = intToBinary(num1);
	cout<<binary<<endl;
	
	// (1<<k) gives you the 1 bit at kth position
	
	int num2 = num & ~(1<<k); // set kth bit of num to 0
	binary = intToBinary(num2);
	cout<<binary<<endl;
	
	int num3 = num ^ (1<<k); // invert the kth bit of num 
	binary = intToBinary(num3);
	cout<<binary<<endl;
	
	int num4 = num & (num-1); // set the last bit of num to 0
	binary = intToBinary(num4);
	cout<<binary<<endl;
	
	int num5 = num & -num; // set all the 1 bits to 0 except to last one bit
	binary = intToBinary(num5);
	cout<<binary<<endl;
	
	int num6 = num | (num-1); // Inverts all the bits after the last one bit
	binary = intToBinary(num6);
	cout<<binary<<endl;
	
	int num7 = num & (num-1); // check wheater the given number is a 2's power or not?x
	if(num7 == 0)
		cout<<"NUM: "<<num<<" is a 2's power number"<<endl;
	else
		cout<<"NUM: "<<num<<" is not a 2's power number"<<endl;
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
