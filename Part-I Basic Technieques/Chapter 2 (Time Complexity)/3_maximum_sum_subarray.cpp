// @hritikkumar
#include<bits/stdc++.h> // all header files

using namespace std; //namespace created as std

int naive_approach(int [], int);
int order_of_n2(int [], int);
int order_of_n1_fast(int [], int);

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n = 3;
	int a[] = {1, 2, 3};
	cout<<"Naive Approach O(n^3) : "<<naive_approach(a, n)<<endl;
	cout<<"Optimized Approach O(n^2) : "<<order_of_n2(a, n)<<endl;
	cout<<"Fast Optimized Approach O(n^3) : "<<order_of_n1_fast(a, n)<<endl;
	return 0;
}

int naive_approach(int a[], int n)
{
	int answer = a[0];
	for(int start_index = 0; start_index < n; ++start_index) // starting range
	{
		for(int end_index = start_index; end_index < n; ++end_index) // ending range
		{
			int sum = 0; // each subarray's sum
			for(int range_iterator=start_index; range_iterator<=end_index && range_iterator<n;range_iterator++) // sum of all the elements in the give range 
			{
				sum += a[range_iterator];
			}
			answer = max(answer, sum); // check that is it the best as compared to previous ones
		}
	}
	return answer;
}

int order_of_n2(int a[], int n)
{
	int answer  = a[0];
	
	for(int start = 0; start<n; ++start)
	{
		int sum = 0;
		for(int end = start; end<n; ++end)
		{
			sum += a[end];
			answer = max(answer, sum);
		}
	}
	return answer;
}

int order_of_n1_fast(int a[], int n)
{
	int answer = a[0], sum =0;
	for(int start = 0; start<n;start++)
	{
		sum = max(sum+a[start], a[start]);
		answer = max(answer, sum);
	}
	return answer;
}
