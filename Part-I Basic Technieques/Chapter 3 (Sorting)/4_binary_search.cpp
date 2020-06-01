#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int  k;
	cin>>k;
	int left = 0, right=n-1, mid=0;
	while(left<=right)
	{
		mid = left + (right-left)/2;
		if(a[mid] == k)
		{
			break;
		}
		else if(a[mid] > k)
		{
			right = mid-1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if(a[mid] != k)
	cout<<-1<<endl;
	else
	cout<<mid<<endl;
	return 0; 
}
