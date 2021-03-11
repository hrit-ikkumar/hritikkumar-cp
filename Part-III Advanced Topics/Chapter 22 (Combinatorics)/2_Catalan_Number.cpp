#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class CatalanNumber
{
	private:
		int number;
	public:
		CatalanNumber()
		{
			this->number = 0;
		}
		
		CatalanNumber(int num)
		{
			this->number = num;
		}
		
		unsigned long int nCr(int n, int r)
		{
			unsigned long int res = 1;
			// nCr = nC(n-k)
			if(r > n-r)
				r = n -r;
			for(int i=0;i<r;i++)
			{
				res *= (n-i);
				res /= (i+1);
			}
			return res;
		}
		
		int calculateCatalanNumber()
		{
			// 1-Method: DP using {sum(from 0 to n-1) [C[i] * C[n-i-1]]}
			// 2-Method: Maths {(1/n+1) * {(2n)C(n)}}
			
			return (int)nCr(2*number, number) / (number+1); // 
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int N;
	cin>>N;
	CatalanNumber *catalanNumber = new CatalanNumber(N);
	cout<<"C(N): "<<catalanNumber->calculateCatalanNumber()<<endl;
	
	return 0; // return type is int
}
