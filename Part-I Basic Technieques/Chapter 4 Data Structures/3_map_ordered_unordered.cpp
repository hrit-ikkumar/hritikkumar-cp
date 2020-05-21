// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; 

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	// Map contains key-value pair
	map<string, int> mp;
	mp["monkey"] = 4;
	mp["banana"] = 5;
	mp["harpisichord"] = 9;
	
	cout<<mp["banana"]<<endl; // It will return value of key "banana" string
	cout<<mp["apple"] <<endl; // It will return 0 because map does not contain "apple" string in it
	
	if(mp.count("monkey"))
	cout<<"monkey consists in mp"<<endl;
	else 
	cout<<"monkey does not consist in mp"<<endl;
	// print all the key and pair in map
	for(auto pr: mp)
	{
		cout<<pr.
	}
}
