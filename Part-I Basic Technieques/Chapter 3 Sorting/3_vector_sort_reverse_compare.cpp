#include<bits/stdc++.h> // all  header files

using namespace std; // namespace created as std
bool compare(char, char); // compare function for sort

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	
	int n;
	cin>>n;
	vector<int> vt(n); // size has been defined
	for(int i=0;i<n;i++)cin>>vt[i]; 
	
	sort(vt.begin(), vt.end()); 
	// ascending order sorted vector ( vector is simply a dynamic array)
	for(int i=0;i<n;i++)cout<<vt[i]<<" ";
	cout<<endl;
	
	sort(vt.rbegin(), vt.rend());// reverse(vt.begin(), vt.end());
	// sorting in descending order
	for(int i=0;i<n;i++)cout<<vt[i]<<" ";
	cout<<endl;
	
	// sorting according a compare operator
	string s = "nevergiveup";
	sort(s.begin(), s.end(), compare);
	cout<<s<<endl;
	return 0;
}

bool compare(char ch1, char ch2)
{
	if((ch1-ch2) > 0)
	return false;
	else
	return true;
}
