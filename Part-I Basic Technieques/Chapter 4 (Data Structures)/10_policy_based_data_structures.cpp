// @hritikkumar


  
#include <iostream>  
using namespace std;  
  
// Important header files   
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  


using namespace __gnu_pbds;  
using namespace std; 

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	/*
	 * These data structures are not part of standard c++ but g++ compiler supports them. 
	 * those data structures are called as policy-based data structurs
	 */
	 
	 indexed_set s;
	 s.insert(2);
	 s.insert(3);
	 s.insert(7);
	 s.insert(9);
	 auto x = s.find_by_order(2);
	cout << *x << "\n"; // 7
	cout << s.order_of_key(7) << "\n"; // 2
	
	cout << s.order_of_key(6) << "\n"; // 2
	cout << s.order_of_key(8) << "\n"; // 3
	
	return 0; //return type is int
}
