#include<bits/stdc++.h> // all header files

using namespace std; //namespace created as std

void recursiveFunction(int n)
{
	if(n==0)
	return;
	
	recursiveFunction(n-1);
	recursiveFunction(n-1);
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("intput.txt", "r", stdin);
	freopen("output.txt", "w",  stdout);
	#endif
	
	cout<<"Let's se how many iterations are possible in each time complesity"<<endl;
	/* 1. O(n) -> 10^5 to 10^7 iterations in one second
	 * 2. O(n*n) -> 5000 iterations in one second
	 * 3. O(log(n)) -> n is large around same as like O(1)
	 * 4. O(2^n) -> 20 iterations in one second because (2^20 == 10^4.5)
	 * 5. O(n!) -> 10 iterations in one second;
	 */
	 // O(n)
	 int  n = 1e10; // O(N)
	 clock_t start = clock();
	 for(int i=0;i<n;i++)
	 {
		 // Your Code goes here
	 }
	 clock_t end = clock();
	 double total_time = (double)(end - start)/CLOCKS_PER_SEC;
	 cout<<"Total time for O(n) where n is 10^7: "<<total_time<<endl;
	 n = 5 * 1e3; //O(N*N)
	 for(int i=0;i<n;i++)
	 {
		 for(int j=0;j<n;j++)
		 {
			 //Your Code goes here
		 }
	 }
	 
	 n = 20; // O(2^N)
	 recursiveFunction(n);
	 
	 n = 10;// O(N!)
	 //for this we have to make unlimited loops like n! way 
	
}
