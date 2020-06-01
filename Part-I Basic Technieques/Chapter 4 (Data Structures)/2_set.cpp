// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; 

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif
	
	set<int> st;
	int n;
	cin>>n;
	int val;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		st.insert(val);
	}
	for(auto it: st)
	{
		cout<<it<<" ";
	}
	cout<<endl;
	/*
	 * for(auto it= st.begin(); it!=st.end(); ++it)
	 * {
	 * cout<<*it<< "" ;
	 * }
	 * cout<<endl;
	 */
	 /*
	  * You can earse values by using 
	  * st.erase(value);
	  * You can also count the occurance of value 
	  * st.count(value); // It will come 0 or 1 in the case of set
	  */
	 // One main thing, Set only contains one value of single value (like it will have 5 not 5, 5).
	 // In order, to have multi values we use multiset 
	 // set can also be declared as 
	 // set<int> s = {2, 5, 56, 38};
	 // We can get the size of set by s.size()
	 
	 multiset<int> mul;
	 cin>>n;
	 for(int i=0;i<n;i++)
	 {
		 cin>>val;
		 mul.insert(val);
	 }
	 int k;
	 cin>>k; // the count of value which should be fined
	 cout<<mul.count(k)<<endl;
	 mul.erase(mul.find(k)); // This will erase only one instance of set value
	 cout<<mul.count(k)<<endl;
	 mul.erase(k); // It will erase all the values
	 // You can find the size of multiset by mul.size();
	/*
	 * for more effient implementation you can use unordered_set which is not sorted by its values
	 * The same thing applys with multisets, you can use unordered_multiset 
	 * set and multiset are sorted sets (distinct & repeated) but unordered_set/multiset are not sorted according to their value
	return 0; //return type is int
}
