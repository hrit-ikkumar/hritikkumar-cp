#include<bits/stdc++.h> // all header files

using namespace std; // namespace created as std

class Probability
{
	public:
		int num;
	public:
		Probability(){}
		Probability(int number)
		{
			this->num = number;
		}
		
		double getProbability()
		{
			double Pnum = 1.0/ num;
			return Pnum;
		}
};

int main(void)
{
	std::ios::sync_with_stdio(false); cin.tie(); cout.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	#endif
	int n;
	cin>>n;
	Probability *p = new Probability(n);
	cout<<"P(1:"<<n<<") => "<<p->getProbability()<<endl;
	return 0; // return type is int 
}
