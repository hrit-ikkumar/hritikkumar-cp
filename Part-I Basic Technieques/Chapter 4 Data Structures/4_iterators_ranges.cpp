// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

void print_vector_array(vector<int>);

int main(void)
{
	std:: ios::sync_with_stdio(false); cin.tie(0); // for making a program fast (closes other input methods)
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> vt(n); // vector of n size
	
	for(int i=0;i<n;i++)cin>>vt[i]; 
	
	// sorting a vector using iterators
	sort(vt.begin(), vt.end());
	print_vector_array(vt);
	
	// reverse the order of element in vector
	reverse(vt.begin(), vt.end());
	print_vector_array(vt); 
	
	// random shuffle in vector 
	random_shuffle(vt.begin(), vt.end());
	print_vector_array(vt); 
	
	/* 
	 * If we want to do the same thingwith array we can use array pointers instead of the iterators
	 * sort(a, a+n);
	 * reverse(a, a+n);
	 * random_shuffle(a, a+n);
	 */
	 // We do have two more iterators (rbegin() & rend()) they are just reverse of iterators of the vector
	 return 0; 
}

void print_vector_array(vector<int> vt)
{
	int n = vt.size();
	for(int i=0;i<n;i++)
	{
		cout<<vt[i]<<" ";
	}
	cout<<endl;
}
