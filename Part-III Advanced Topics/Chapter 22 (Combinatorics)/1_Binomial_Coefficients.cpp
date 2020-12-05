#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class BinomialCoefficient
{
	public:
		int num;
	
	public:
		BinomialCoefficient() 
		{
			// Do nothing
		}
		BinomialCoefficient(int num)
		{
			this->num = num;
		}
		
		void print_everything()
		{
			// Do all the printing tasks
			cout<<"NUM: "<<num<<endl;
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif
	int n;
	cin>>n;
	BinomialCoefficient * binomialCoefficient = new BinomialCoefficient(n);
	binomialCoefficient->print_everything(); // tasking
	return 0; // return type is int 
}
