#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class GameStates
{
	public:
		int totalNumberOfSticks;
	public:
		GameStates()
		{
			totalNumberOfSticks = 0;
		}
		GameStates(int numberOfSticks)
		{
			this->totalNumberOfSticks = numberOfSticks;
		}
		
		void canWeWin(int k)
		{
			if(totalNumberOfSticks % (k+1) == 0)
			{
				cout<<"LOSING SITUATION!!!"<<endl;
			}
			else
			{
				cout<<"WINNING SITUATION!!!"<<endl;
			}
		}
};

int main(void)
{
	std:: ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	GameStates *gS = new GameStates(n);
	int k;
	cin>>k;
	gS -> canWeWin(k);
	
	return 0; // return type is int
}
