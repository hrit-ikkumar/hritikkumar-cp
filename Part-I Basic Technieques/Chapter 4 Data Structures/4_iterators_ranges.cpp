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
	
	// Vector Iterators
	
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
	 
	 // Set Iterators
	 set<int> st;
	 cin>>n;
	 for(int i=0;i<n;i++){int val; cin>>val; st.insert(val);}
	 
	 set<int>::iterator it = st.begin();  // this element is the smallest element in ordered set
	 // auto it = st.begin();
	 cout<<*it<<endl;
	 // it iterator can be moved forward (++) and bacward(--) 
	 it++;
	 cout<<*it<<endl;
	 it--;
	 cout<<*it<<endl;
	 // print whole set using iterator
	 for(auto itr = st.begin(); itr!=st.end(); itr++)
	 {
		 cout<<*itr<<" ";
	 }
	 cout<<endl;
	 
	 // largest element in set
	 it = st.end(); it--;
	 cout<<*it<<endl;
	 
	 int k;
	 cin>>k;
	 it  = st.find(k); // returns the iterator which points to that element
	 if(it!=st.end())
		cout<<*it<<" has been founded"<<endl;
	else
		cout<<*it<<" has not founded"<<endl;
	int find_me;
	cin>>find_me;
	// find the element which is nearted to given element
	it = st.lower_bound(find_me);
	
	if(it==st.begin())
		cout<<*it<<endl;
	else if(it==st.end())
	{
		it--;
		cout<<*it<<endl;
	}
	else
	{
		int a = *it; it--;
		int b = *it;
		
		if((find_me-b) < (find_me - a))
			cout<<b<<endl;
		else
			cout<<a<<endl;
	}
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
