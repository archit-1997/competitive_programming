/*The following problem is well-known: given integers n and m, calculate
,

where 2n = 2·2·...·2 (n factors), and denotes the remainder of division of x by y.

You are asked to solve the "reverse" problem. Given integers n and m, calculate
.
Input

The first line contains a single integer n (1 ≤ n ≤ 108).

The second line contains a single integer m (1 ≤ m ≤ 108).
Output

Output a single integer — the value of .
Examples
Input
Copy

4
42

Output
Copy

10

Input
Copy

1
58

Output
Copy

0

Input
Copy

98765432
23456789

Output
Copy

23456789

Note

In the first example, the remainder of division of 42 by 24 = 16 is equal to 10.

In the second example, 58 is divisible by 21 = 2 without remainder, and the answer is 0.
*/

///Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll exp(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return exp(x*x,n/2);
    else
        return x*exp(x*x,(n-1)/2);
}

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,m;	cin>>n>>m;
	
	if(n>=27)
	    cout<<m<<endl;
	else
	{
	ll mod=exp(2,n);
	//cout<<mod<<endl;
	
	cout<<m%mod<<endl;
	}
	
	return 0;
}
