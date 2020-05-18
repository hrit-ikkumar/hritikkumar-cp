#include<bits/stdc++.h> // all header files

using namespace std; //namespace created as std

void swap(int *, int ); // swap two variables

void bubble_sort(int*, int); // bubble sort function

void merge(int*, int, int, int, int); // merge two sorted arrays

void merge_sort(int*, int , int, int); // merge sort function

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
	 
	 int max_element = a[0];
	for(int i=1;i<n;i++)
	{
		max_element = max(max_element, a[i]);
	}
	
	 // bubble_sort(a, n);
	 merge_sort(a, 0, n-1, max_element+1);
	 
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

void merge(int *a, int left, int pivot_index, int right, int max_element)
{
	// This approach is implemented in O(1) memeory space. You may know the O(n) memory space 2-array-merge. (Left arrray and right array then make a combined sorted array then replace the values )
    int maxele = max_element;
    int j = pivot_index + 1; 
    int k = left; 
    int i = left;
    while (i <= pivot_index && j <= right) { 
        if (a[i] % maxele <= a[j] % maxele) { 
            a[k] = a[k] + (a[i] % maxele) * maxele; 
            k++; 
            i++; 
        } 
        else { 
            a[k] = a[k] + (a[j] % maxele) * maxele; 
            k++; 
            j++; 
        } 
    } 
    while (i <= pivot_index) { 
        a[k] = a[k] + (a[i] % maxele) * maxele; 
        k++; 
        i++; 
    } 
    while (j <= right) { 
        a[k] = a[k] + (a[j] % maxele) * maxele; 
        k++; 
        j++; 
    } 
  
    // Obtaining actual values 
    for (i = left; i <= right; i++) 
        a[i] = a[i] / maxele; 
}


void merge_sort(int *a, int left, int right, int max_element)
{
	if(left >= right)
	return;
	int mid = (left + right)/2;
	// quick sort apprach int pivot_index = partition(a, 0, right); // Find the position of pivot (a[right])
	merge_sort(a, left, mid,max_element);
	merge_sort(a, mid+1, right, max_element);
	
	merge(a, left, mid, right, max_element);
}
