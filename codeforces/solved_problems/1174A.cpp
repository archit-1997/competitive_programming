/*You're given an array 𝑎 of length 2𝑛. Is it possible to reorder it in such way so that the sum of the first 𝑛 elements isn't equal to the sum of the last 𝑛

elements?
Input

The first line contains an integer 𝑛
(1≤𝑛≤1000), where 2𝑛 is the number of elements in the array 𝑎

.

The second line contains 2𝑛
space-separated integers 𝑎1, 𝑎2, …, 𝑎2𝑛 (1≤𝑎𝑖≤106) — the elements of the array 𝑎

.
Output

If there's no solution, print "-1" (without quotes). Otherwise, print a single line containing 2𝑛
space-separated integers. They must form a reordering of 𝑎

. You are allowed to not change the order.
Examples
Input
Copy

3
1 2 2 1 3 1

Output
Copy

2 1 3 1 1 2

Input
Copy

1
1 1

Output
Copy

-1

Note

In the first example, the first 𝑛
elements have sum 2+1+3=6 while the last 𝑛 elements have sum 1+1+2=4

. The sums aren't equal.

In the second example, there's no solution.*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;	cin>>n;
	vector<ll> v;
	
	ll ls=0,sum=0;
	
	for(ll i=0;i<2*n;i++)
	{
		ll num;	cin>>num;
		v.push_back(num);
		sum+=num;
	}
	
	sort(v.begin(),v.end());
	
	for(ll i=0;i<n;i++)
	    ls+=v[i];
	    
	ll rs=sum-ls;
	
	if(ls==rs)
	    cout<<-1<<endl;
	else
	{
	    for(ll i=0;i<2*n;i++)
	        cout<<v[i]<<" ";
	       
	    cout<<endl;
	}
	
	
	return 0;
}
