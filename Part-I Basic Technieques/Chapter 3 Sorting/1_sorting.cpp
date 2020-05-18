#include<bits/stdc++.h> // all header files

using namespace std; //namespace created as std

void swap(int *, int ); // swap two variables

void bubble_sort(int*, int); // bubble sort function

int partition(int *, int); // partition in array or finding the perfect location of that element so that all the elements which are in left side of that element should be lesser than that element
// and all the element which are in the right side, they should be greater than that element. They can be equal to that element (Edge Case).

void merge(int*, int, int, int); // merge two sorted arrays

void merge_sort(int*, int , int); // merge sort function

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	/*
	 * Sorting is the way of arranging elements in ascending or descending order
	 * Mainly, We have two options for sorting O(n^2) and O(n*log(n)).
	 * Bubble Sort => O(n^2)
	 * Merge Sort => O(n^2)
	 */
	 cout<<"Enter N: ";
	 int n;
	 cin>>n;
	 cout<<"Enter Unsorted Array: ";
	 int* a = new int[n]; // dynamic array allocation for 1D array
	 for(int i=0;i<n;i++)cin>>a[i];
	 
	 // bubble_sort(a, n);
	 merge_sort(a, 0, n);
	 
	 cout<<"Sorted Numbers: ";
	 for(int i=0;i<n;i++)
	 {
		 cout<<a[i]<<" ";
	 }
	 cout<<endl;
	 
	 return 0; //return type is int
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void bubble_sort(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j] , a[j+1]);
			}
		}
	}
}

void merge(int *a, int left, int pivot_index, int right)
{
	// This approach is implemented in O(1) memeory space. You may know the O(n) memory space 2-array-merge. (Left arrray and right array then make a combined sorted array then replace the values )
	int i = left, j = pivot_index + 1;
	
	while(i<=pivot_index && j<=right)
	{
		if(a[i] > a[j])
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	while(i<=pivot_index)
	{
		
	}
}

int partition(int *a, int left, int right)
{
	int i = left, j = right -1, pivot = a[right];
	for(;i<right && j>=left; i++)
	{
		if(a[i] > pivot)
		{
			swap(a[i], a[j]);
			j--;
		}
		
	}
	swap(a[j], a[right]);
	return j;
}

void merge_sort(int *a, int left, int right)
{
	if(left >= right)
	return;
	int pivot_index = partition(a, 0, right); // Find the position of pivot (a[right])
	merge_sort(a, left, pivot_index);
	merge_sort(a, pivot_index+1, right);
	merge(a, left, pivot_index, right);
}
