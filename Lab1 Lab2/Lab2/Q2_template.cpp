#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define Max 100000 //sqrt(1043115528)
typedef long long ll;
vector<int> Prime;//to record Prime number
bool isnt_prime[Max];//the number isnt prime is true

//ifstream the_input("input.txt");//input fstream
ifstream the_input("input_2.txt");

class PrimeFactorization {
private:
	int num1, num2;
	vector<int> num1_factor, num2_factor;

public:

	//Init
	PrimeFactorization() {
		num1=0;
		num2=0;
	}
	PrimeFactorization(int _a, int _b) {
		num1=_a;
		num2=_b;
	}

	//put num's prime_factors into each vector
	void Get_Prime_Factorization() {

		//num1
		int tmp=num1;
		for(unsigned int i=0;i<Prime.size()&&tmp>=Prime[i];i++)
		{
			while(tmp%Prime[i]==0)
			{
				num1_factor.emplace_back(Prime[i]);
				tmp/=Prime[i];
			}
		}

		//if it has a prime_factor bigger than Max
		if(tmp!=1)
			num1_factor.emplace_back(tmp);

		//num2
		tmp=num2;
		for(unsigned int i=0;i<Prime.size()&&tmp>=Prime[i];i++)
		{
			while(tmp%Prime[i]==0)
			{
				num2_factor.emplace_back(Prime[i]);
				tmp/=Prime[i];
			}
		}
		if(tmp!=1)
			num2_factor.emplace_back(tmp);
	}

	void Print_Prime_Factorization() {
		//num1
		cout<<"num1_Prime_factor : \" ";
		for(unsigned int i=0;i<num1_factor.size();i++)
			cout<<num1_factor[i]<<' ';
		cout<<"\"\n";

		//num2
		cout<<"num2_Prime_factor : \" ";
		for(unsigned int i=0;i<num2_factor.size();i++)
			cout<<num2_factor[i]<<' ';
		cout<<"\"\n";
}

	void Print_GCD_Factorization() {
		//TO_DO: Use num1_factor and num2_factor to find prime factorization of GCD and print the result.
		unsigned int i=0,j=0;
		bool coprime=1;//special

		cout<<"GCD_Prime_factor : \" ";
		while(i<num1_factor.size()&&j<num2_factor.size())
		{
			if(num1_factor[i]==num2_factor[j])
			{
				coprime=0;
				cout<<num1_factor[i]<<' ';
				i++;
				j++;
			}
			else if(num1_factor[i]>num2_factor[j])
				j++;
			else
				i++;
		}
		if(coprime)//if max cofactor is 1
			cout<<"1 ";
		cout<<"\"\n";
	}

};

void InitPrime()//table prime
{
	for(ll i=2;i<Max;i++)
	{
		if(!isnt_prime[i])
		{
			for(ll j=i*i;j<Max;j+=i)
				isnt_prime[j]=1;
			Prime.emplace_back(i);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	InitPrime();
	int n;

	the_input>>n;
	/* Do something to read the input.txt file*/

	while(n--)
	{
		int a, b;
		the_input>>a;
		the_input>>b;
		/*Read a and b from input.txt file*/

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD_Factorization();

		cout << '\n';

	}

	//system("PAUSE");
	return 0;
}
