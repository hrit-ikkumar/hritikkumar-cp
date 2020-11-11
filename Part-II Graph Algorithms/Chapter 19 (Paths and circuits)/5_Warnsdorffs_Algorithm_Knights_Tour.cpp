// @hritikkumar

#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class KnightsTour
{
	public:
		vector<vector<int>> chessBoard;
		int size;
		vector<int> moveX = {2, 1, -1, -2, -2, -1, 1, 2},
							 moveY = {1, 2,  2,  1, -1, -2,-2, -1}; 
	public:
		KnightsTour() {}
		KnightsTour(int N)
		{
			this->size = N;
			chessBoard.resize(N, vector<int>(N, -1)); // chess board of N x N size
		}
		
		void runScript()
		{
			cout<<"BEFORE:"<<endl;
			print_everything();
			
			solveKT();
			
			cout<<"AFTER:"<<endl;
			print_everything();
		}
		
		void solveKT()
		{
			chessBoard[0][0] = 0;
			if(solveKTUtil(0, 0, 1) == 0)
			{
				cout<<"Solution does not exist"<<endl;
			}
			else
			{
				cout<<"Solution DOES EXIST"<<endl;
			}
		}
		
		int solveKTUtil(int x, int y, int currVal)
		{
			if(currVal == size * size)
			{
				return 1;
			}
			
			for(int i=0;i<(signed)moveX.size(); i++)
			{
				int next_x = x + moveX[i],
				next_y = y + moveY[i];
				
				if(isSafe(next_x, next_y))
				{
					chessBoard[next_x][next_y] = currVal;
					if(solveKTUtil(next_x, next_y, currVal + 1) == 1)
						return 1;
					else
						chessBoard[next_x][next_y] = -1;
				}
			}
			return 0;
		}
		
		bool isSafe(int x, int y)
		{
			return (
							x>=0 && x < size && y >= 0 && y < size 
							&& chessBoard[x][y] == -1
						);
		}
		
		void print_everything()
		{
			cout<<"N: "<<size<<endl;
			for(auto row: chessBoard)
			{
				for(auto cell: row)
					cout<<cell<<" ";
				cout<<endl;
			}
		}
};


int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int boardSize;
	cin>>boardSize;
	KnightsTour* knightsTour  = new KnightsTour(boardSize);
	knightsTour -> runScript();
	
	return 0; // return type is int
}
