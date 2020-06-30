// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int num1, num2;
	cin>>num1>>num2;
	int AND = num1 & num2, OR = num1 | num2, XOR = num1 ^ num2;
	cout<<AND<<endl<<OR<<endl<<XOR<<endl;
	int NOT_num1 = ~num1, NOT_num2 = ~num2;
	cout<<NOT_num1<<endl<<NOT_num2<<endl;
	//(~ x) = (− x) − 1
	NOT_num1 = - num1 -1, NOT_num2 = - num2 -1 ;
	cout<<NOT_num1<<endl<<NOT_num2<<endl;
	
	int x;
	cin>>x;
	int left_shift = x<<1, right_shift = x>>1;
	cout<<left_shift<<" "<<right_shift<<endl;
	return 0; // return type is int
}
