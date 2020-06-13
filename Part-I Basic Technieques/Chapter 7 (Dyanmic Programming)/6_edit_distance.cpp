// @hritikkumar

#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std; // namespace created as std

int editDistanceDP(string s1, string s2);

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	string s1, s2;
	cin>>s1>>s2;
	
	int ans = editDistanceDP(s1,s2);
	
	cout<<ans<<endl;
	
	return 0; // return type is int
}

int editDistanceDP(string s1, string s2)
{
	int** dp_table = new int*[s1.size() +1];
	for(int i=0;i<=(signed)s1.size();++i)
		dp_table[i] = new int[s2.size() + 1];
	for(int i=0;i<=(signed)s1.size();++i)
		dp_table[i][0] = i;
	for(int j=0;j<= (signed)s2.size();++j)
		dp_table[0][j] = j;
	
	for(int i=1;i<=(signed)s1.size();++i)
	{
		for(int j=1;j<=(signed)s2.size();++j)
		{
			dp_table[i][j] = min (dp_table[i-1][j] + 1, min (dp_table[i][j-1] +1, dp_table[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1)));
		}
	}
	string res = "", curr = "";
	int i = s1.size(), j= s2.size();
	while(i>0 && j>0)
	{

		if(dp_table[i][j] == dp_table[i-1][j] + 1 && s1[i-1]   != s2[j-1])
		{
			curr="";
			i-=1;
		}
		else if( dp_table[i][j] == dp_table[i][j-1] +1 && s1[i-1] != s2[j-1])
		{
			curr="";
			j-=1;
		}
		else
		{
			curr = s1[i-1] + curr;
			i-=1; j-=1;
		}
		
		if(res.size() < curr.size())
			res = curr;
	}
	cout<<res<<endl;
	return dp_table[s1.size()][s2.size()];
}
