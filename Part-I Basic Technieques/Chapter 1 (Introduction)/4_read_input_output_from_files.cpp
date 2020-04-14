// @hritikkumar
#include<bits/stdc++.h> // all header files
using namespace std; //namespace created as std 

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t; // test cases
	cin>>t;
	string tmp;
	getline(cin, tmp); // additional line for test cases because that line should be ened
	while(t--)
	{
		string s;
		getline(cin, s);
		cout<<"S: "<<s<<endl;
	}
	
	return 0; // return type is into
}
