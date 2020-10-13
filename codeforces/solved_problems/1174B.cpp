/*You're given an array 𝑎 of length 𝑛

. You can perform the following operation on it as many times as you want:

    Pick two integers 𝑖

and 𝑗 (1≤𝑖,𝑗≤𝑛) such that 𝑎𝑖+𝑎𝑗 is odd, then swap 𝑎𝑖 and 𝑎𝑗

    . 

What is lexicographically the smallest array you can obtain?

An array 𝑥
is lexicographically smaller than an array 𝑦 if there exists an index 𝑖 such that 𝑥𝑖<𝑦𝑖, and 𝑥𝑗=𝑦𝑗 for all 1≤𝑗<𝑖. Less formally, at the first index 𝑖 in which they differ, 𝑥𝑖<𝑦𝑖

Input

The first line contains an integer 𝑛
(1≤𝑛≤105) — the number of elements in the array 𝑎

.

The second line contains 𝑛
space-separated integers 𝑎1, 𝑎2, …, 𝑎𝑛 (1≤𝑎𝑖≤109) — the elements of the array 𝑎

.
Output

The only line contains 𝑛

space-separated integers, the lexicographically smallest array you can obtain.
Examples
Input
Copy

3
4 1 7

Output
Copy

1 4 7 

Input
Copy

2
1 1

Output
Copy

1 1 

Note

In the first example, we can swap 1
and 4 since 1+4=5, which is odd.
*/

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
	
	ll even=0,odd=0;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		if(even==0 && num%2==0)
		    even=1;
		if(odd==0 && num%2==1)
		    odd=1;
		v.push_back(num);
	}
	
	if(odd==0 || even==0)
    {
        for(ll i=0;i<n;i++)
            cout<<v[i]<<" ";
    }
    else
    {
        sort(v.begin(),v.end());
        for(ll i=0;i<n;i++)
            cout<<v[i]<<" ";
    }
	
	return 0;
}
