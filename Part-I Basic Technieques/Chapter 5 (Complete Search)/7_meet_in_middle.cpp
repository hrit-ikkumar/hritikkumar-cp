// @hritikkumar

/* Given a set of n integers where n <= 40. Each of them is at most 1012, 
 * determine the maximum sum subset having sum less than or equal S 
 * where S <= 1018.
 */
#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; //namespace created as std

long long hash_x[2000005], hash_y[2000005];

void calculateSubarray(int *, long long int [], int , int );

long long int solvesSubsetSum(int*, int , int); // maximum possible sum less or equal to sum


int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt" ,"r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	
	int n;
	cin>>n;
	int* a = new int [n];
	for(int i=0;i<n;i++)cin>>a[i];
	int sum;
	cin>> sum; // desired sum
	cout<<solvesSubsetSum(a, n, sum)<<endl;
	
	return 0; // return type is int
	
}

void calculateSubarray(int *a, long long int hash[], int n, int c)
{
	for(int i=0;i< (1<<n); ++i)
	{
		long long int sum = 0;
		for(int j=0;j<n;j++)
			if(i & (1<<j))
				sum += a[j+c];
		hash[i] = sum;
	}
}

long long int solvesSubsetSum(int *a, int n, int sum)
{
	calculateSubarray(a, hash_x, n/2, 0);
	calculateSubarray(a, hash_y, n - n/2, n/2);
	
	int size_x = 1 << (n/2);
	int size_y = 1 << (n - n/2);
	
	sort(hash_y, hash_y + size_y);
	
	long long int max = 0;
	for(int i=0;i<size_x; i++)
	{
		if(hash_x[i]  <= sum)
		{
			int p = lower_bound(hash_y, hash_y + size_y, sum - hash_x[i]) - hash_y;
			
			if(p == size_y || hash_y[p] != (sum - hash_x[i]))
				p--;
			if( (hash_y[p] + hash_x[i]) > max)
				max = hash_y[p] + hash_x[i];
		}
	}
	return max; 
}
