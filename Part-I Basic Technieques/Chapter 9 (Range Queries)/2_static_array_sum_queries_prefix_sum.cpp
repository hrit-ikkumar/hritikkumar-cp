// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int staticRangeQuery1D(vector<int> & , int , int);

int staticRangeQuery2D(vector<vector<int>> &, vector<pair<int, int>> &xy);

int main(void)
{
	std::ios::sync_with_stdio(false); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) cin>>a[i];
	int left, right;
	cin>>left>>right;
	int ans = staticRangeQuery1D(a, left, right);
	cout<<ans<<endl;
	
	int row, col;
	cin>>row>>col;
	vector<vector<int>> matrix(row, vector<int>(col));
	for(int i=0;i<row;i++) for(int j=0;j<col;j++) cin>>matrix[i][j];
	vector<pair<int, int>> xy(4);
	/*
	 xy[3]=d		xy[2]=c
	 xy[1]=b		xy[0]=a
	 */
	for(int i=0;i<(signed)xy.size();i++) cin>>xy[i].first>>xy[i].second;
	
	ans = staticRangeQuery2D(matrix, xy);
	cout<<ans<<endl;
	return 0; // return type is int
}

int staticRangeQuery1D(vector<int> &a,int left, int right)
{
	int n = a.size();
	vector<int> prefix_sum(n, 0);
	prefix_sum[0] = a[0];
	for(int i=1;i<n;i++) prefix_sum[i] = prefix_sum[i-1] + a[i];
	
	return (prefix_sum[right] - prefix_sum[left-1]);
}

int staticRangeQuery2D(vector<vector<int>> &mat, vector<pair<int, int>> &xy)
{
	int row = mat.size(), col = mat[0].size();
	
	vector<vector<int>> prefix_sum_table(row, vector<int>(col, 0));
	prefix_sum_table[0][0] = mat[0][0];
	for(int r=1;r<row;r++)
		prefix_sum_table[r][0] = prefix_sum_table[r-1][0] + mat[r][0];
	for(int c=1;c<col;c++)
		prefix_sum_table[0][c] = prefix_sum_table[0][c-1] + mat[0][c];
	
	for(int r = 1;r<row;r++)
	{
		for(int c = 1;c<col;c++)
		{
			prefix_sum_table[r][c] = prefix_sum_table[r-1][c] + prefix_sum_table[r][c-1] - prefix_sum_table[r-1][c-1] + mat[r][c];
		}
	}
	return (prefix_sum_table[xy[0].first][xy[0].second] - prefix_sum_table[xy[1].first][xy[1].second] - prefix_sum_table[xy[2].first][xy[2].second] + prefix_sum_table[xy[3].first][xy[3].second]);
}
