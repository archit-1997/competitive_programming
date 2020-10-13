/*The capital of Berland has n multifloor buildings. The architect who built up the capital was very creative, so all the houses were built in one row.

Let's enumerate all the houses from left to right, starting with one. A house is considered to be luxurious if the number of floors in it is strictly greater than in all the houses with larger numbers. In other words, a house is luxurious if the number of floors in it is strictly greater than in all the houses, which are located to the right from it. In this task it is assumed that the heights of floors in the houses are the same.

The new architect is interested in n questions, i-th of them is about the following: "how many floors should be added to the i-th house to make it luxurious?" (for all i from 1 to n, inclusive). You need to help him cope with this task.

Note that all these questions are independent from each other — the answer to the question for house i does not affect other answers (i.e., the floors to the houses are not actually added).
Input

The first line of the input contains a single number n (1 ≤ n ≤ 105) — the number of houses in the capital of Berland.

The second line contains n space-separated positive integers hi (1 ≤ hi ≤ 109), where hi equals the number of floors in the i-th house.
Output

Print n integers a1, a2, ..., an, where number ai is the number of floors that need to be added to the house number i to make it luxurious. If the house is already luxurious and nothing needs to be added to it, then ai should be equal to zero.

All houses are numbered from left to right, starting from one.
Examples
Input
Copy

5
1 2 3 1 2

Output
Copy

3 2 0 2 0 

Input
Copy

4
3 2 1 4

Output
Copy

2 3 4 0 
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define P pair<ll,ll>
#define PP pair<pair<ll,ll>,ll>
#define V vector<ll>
#define VP vector<pair<ll,ll>>
#define VS vector<string>
#define VV vector<vector<ll>> 
#define VVP vector<vector<pair<ll,ll>>> 
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	FAST;
	
	ll n;	cin>>n;
	V v;
	
	FOR(i,0,n)
	{
		ll num;	cin>>num;
		v.pb(num);
	}
	
	V ans(n);
	
	ans[n-1]=0;
	
	ll big=v[n-1];

	for(ll i=n-2;i>=0;i--)
	{
	    if(v[i]<big)
	    {
	        ll val=big-v[i]+1;
	        ans[i]=val;
	    }
	    else if(v[i]==big)
	        ans[i]=1;
	    else if(v[i]>big)
	    {
	        ans[i]=0;
	        big=v[i];
	    }
	}
	
	FOR(i,0,n)
	    cout<<ans[i]<<" ";
	
	
	
	return 0;
}
