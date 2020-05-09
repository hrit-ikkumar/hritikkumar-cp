
#include<bits/stdc++.h> // all header files
using namespace std;
int main(void)
{
	int a[] = {1,2 , 3 ,4 ,5 };
	int n = 5;
		int answer = 0;
	for(int start_index = 0; start_index < n; start_index+=1) // starting range
	{
		for(int end_index = start_index; end_index < n;end_index+=1) // range index
		{
			int sum = 0; // each subarray's sum
			for(int range_iterator=start_index; range_iterator<=end_index && range_iterator<n;range_iterator++) // sum of all the elements in the give range 
			{
				sum += a[range_iterator];
			}
			answer = max(answer, sum); // check that is it the best as compared to previous ones
		}
	}
	cout<<answer<<endl;
}
