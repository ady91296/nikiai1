#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const long M = 1000000007;
map<long long, long long> Memoize;

//Function to calculate nth Fibonacci number
long long CountCombinations(long long n)
{
	if (Memoize.count(n))
		return Memoize[n];
	long long k=n/2;
/*
	we have two case: n is even and n is odd.
	f(2*k)=f(k)*f(k)+f(k-1)*f(k-1)
	f(2*k+1)=f(k)*f(k+1)+f(k-1)*f(k)
*/
	if (n%2==0)
	{
		// n=2*k
		return Memoize[n] = (CountCombinations(k)*CountCombinations(k) + CountCombinations(k-1)*CountCombinations(k-1)) % M;
	}
	else
	{
		// n=2*k+1
		return Memoize[n] = (CountCombinations(k)*CountCombinations(k+1) + CountCombinations(k-1)*CountCombinations(k)) % M;
	}
}
// Driver Code
main()
{
	long long t,n;
	Memoize[0]=Memoize[1]=1;
	// Number of Testcases
	cin >> t;
	while (t--)
	{
		//Length of Bit String
		cin>>n;
		// Result
		cout << (n+1==0 ? 0 : CountCombinations(n+1)) << endl;
	}
}
