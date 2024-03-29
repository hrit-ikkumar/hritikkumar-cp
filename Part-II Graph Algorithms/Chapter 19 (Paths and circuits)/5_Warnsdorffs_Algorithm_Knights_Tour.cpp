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
			srand(time(NULL)); 
			
			if(solveKT()==true)
				cout<<"Knights Tour EXIST:"<<endl;
			else
				cout<<"Knights Tour Does NOT EXIST"<<endl;
			
			cout<<"AFTER:"<<endl;
			print_everything();
		}
		
		bool solveKT()
		{
			chessBoard.resize(size, vector<int>(size, -1)); // initialize
			
			int sx = rand()%size;
			int sy = rand()%size;
			int x = sx, y = sy; // current points are same as initial points
			chessBoard[x][y] = 1; // mark first move
			
			for(int i=0;i<size * size - 1; i++)
			{
					if(nextMove(&x, &y) == 0)
						return false;
			}
			if(!neighbour(x, y, sx, sy))
				return false;
			
			// printing the chessboard
			cout<<"CHESS BOARD:"<<endl;
			for(auto row: chessBoard)
			{
				for(auto cell:row)
					cout<<cell<<" ";
				cout<<endl;
			}
			
			return true;
		}
		
		bool neighbour(int x, int y, int xx, int yy)
		{
			for(int i=0;i<(signed)moveX.size(); i++)
				if( (x+moveX[i]) == xx && (y+moveY[i]) ==yy)
					return true;
			return false;
		}
		
		bool nextMove(int *x, int *y)
		{
			int min_deg_idx = -1, c, min_deg = size + 1, nx, ny;
			int start = rand()%size;
			for(int count = 0; count < size; count++)
			{
				int i = (start + count) % size;
				nx = *x + moveX[i],
				ny = *y + moveY[i];
				
				if( (isEmpty(nx, ny) && (c = getDegree(nx, ny)) < min_deg))
				{
					min_deg_idx = i,
					min_deg = c;
				}
			}
			
			if(min_deg_idx == -1)
				return false;
				
			nx = *x + moveX[min_deg_idx],
			ny = *y + moveY[min_deg_idx];
			
			chessBoard[nx][ny] = chessBoard[*x][*y] + 1;
			*x = nx;
			*y = ny;
			return true;
		}
		
		bool limit(int x, int y)
		{
			return (x>=0 && y >=0) && (x < size && y < size);
		}
		
		bool isEmpty(int x, int y)
		{
			return limit(x,y) && chessBoard[x][y] < 0;
		}
		
		int getDegree(int x, int y)
		{
			int count = 0;
			for(int i=0;i<(signed)moveX.size(); i++)
			{
				if(isEmpty(x + moveX[i], y+moveY[i]))
					count += 1;
			}
			return count;
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
	srand(time(NULL));
	int boardSize;
	cin>>boardSize;
	KnightsTour* knightsTour  = new KnightsTour(boardSize);
	knightsTour -> runScript();
	
	return 0; // return type is int
}
