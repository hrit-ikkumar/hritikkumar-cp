// @hritikkumar

#include<bits/stdc++.h> // all header files

using namespace std; //namespace created as std 

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // it makes our program fast
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	// Vector is a Dynamic Array
	// vector<int> v;  //  empty dynamic array
	// vector<int> v(size) array will be initialized with 0 as a default value
	//vector<int> v(size(), value); we can specify the default value by passing it in a argument
	// vector<int> vt = {1, 2, 3, 4 6} // this is also another way of initializing array
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	// We can also use it as stack push_back
	v.push_back(101);
	v.pop_back();
	// We will print vector by using for each loop
	for(int x: v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	
	// string structure is also a dynamic array of characters (we can also use vector<char> str
	
	string s;
	//cin>>s;
	getline(cin, s, '\n'); // this line will get the first \n 
	getline(cin, s, '\n');
	//scanf("%s\n", &s);
	// scanf("%[^\n]s, &s); taking input untill we find a new line character \n
	cout<<s<<endl;
	for(char ch: s)
		cout<<ch<<" ";
	cout<<endl;
	s += '7';
	cout<<s<<endl;
	string substring_s = s.substr(0, 4); // 0 is starting index and 4 is length 
	cout<<substring_s<<endl;
	return 0; //return type is int 
}
