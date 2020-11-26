#include<bits/stdc++.h> // all header files

#define endl '\n'

using namespace std;

class PrimeFactors
{
	private:
		int number;
		vector<bool> isPrime;
		vector<int> numPrimeFactors;
	public:
		PrimeFactors() {}
		PrimeFactors(int num) 
		{
			isPrime.resize(1e7, true);
			this->number = num;
			seiveEratosthenes();
			calculatePrimeFactors();
			print_everthing();
		}
		
		void seiveEratosthenes()
		{
			isPrime[0] = isPrime[1] = false;
			for(int num=2; num < (signed) isPrime.size(); num++)
			{
				if(isPrime[num] == false)
					continue;
				
				for(int multiples = 2 * num; multiples < (signed)isPrime.size(); multiples += num)
				{
					isPrime[multiples] = false;
				}
			}
		}
		
		void calculatePrimeFactors()
		{
			for(int divider = 2; divider * divider <= number; divider ++)
			{
				while(number % divider == 0)
				{
					numPrimeFactors.push_back(divider);
					number /= divider;
				}
			}
			if(number > 1)
				numPrimeFactors.push_back(number);
		}
		
		int gcd(int a, int b)
		{
			if(b == 0)
				return a;
			
			return gcd(b, a % b); // swap the values 
		}
		
		void print_everthing()
		{
			cout<<"NUMBER: "<<number<<endl;
			cout<<"PRIME FACTORS: ";
			for(int x: numPrimeFactors)
				cout<<x<<", ";
			cout<<endl<<endl;
			
			cout<<"Prime Numbers from 1 to 1e7:"<<endl;
			for(int i=0;i< 100; i++)
			{
				cout<<i<<": "<<isPrime[i]<<endl;
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
	
	int n;
	cin>>n;
	PrimeFactors* pf = new PrimeFactors(n);
	int second_n;
	cin>>second_n;
	cout<<"GCD("<<n<<","<<second_n<<") => "<<pf->gcd(n, second_n)<<endl;
	
	return 0; // return type is int
} 
