#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class Matrix
{
	public:
		vector<vector<int>> mat; 
		int noRows, noColumn;
	public:
		Matrix()
		{
			// do nothing
		}
		Matrix(vector<vector<int>> newMatrix)
		{
			mat = newMatrix;
			noRows = newMatrix.size(),
			noColumn = newMatrix[0].size(); // destructuring
		}
		
		void addTwoMatrices(Matrix *mat2)
		{
			if(noRows != mat2->noRows || noColumn != mat2->noColumn)
			{
				cout<<"WRONG OPERATION!!! IT DOESN't FOLLOW RULES OF NO OF COLUMNS & NO OF ROWS SHOULD BE SAME";
				return;
			}
			vector<vector<int>> matSum = mat;
			for(int rowIndex = 0; rowIndex < noRows; rowIndex +=1)
			{
				for(int colIndex = 0; colIndex < noColumn; colIndex += 1)
				{
					matSum[rowIndex][colIndex] += mat2->mat[rowIndex][colIndex]; // add each value at i,j position
				}
			}
			cout<<"SUM OF MATRICES:"<<endl;
			for(int rowIndex = 0; rowIndex < noRows; rowIndex +=1)
			{
				for(int colIndex = 0; colIndex < noColumn; colIndex += 1)
				{
					cout<<matSum[rowIndex][colIndex]<<" " ;
				}
				cout<<endl;
			}
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fast io
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	
	
	return 0; // return type is int
}
