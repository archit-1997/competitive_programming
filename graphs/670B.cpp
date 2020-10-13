/*In late autumn evening n robots gathered in the cheerful company of friends. Each robot has a unique identifier — an integer from 1 to 109.

At some moment, robots decided to play the game "Snowball". Below there are the rules of this game. First, all robots stand in a row. Then the first robot says his identifier. After that the second robot says the identifier of the first robot and then says his own identifier. Then the third robot says the identifier of the first robot, then says the identifier of the second robot and after that says his own. This process continues from left to right until the n-th robot says his identifier.

Your task is to determine the k-th identifier to be pronounced.
Input

The first line contains two positive integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ min(2·109, n·(n + 1) / 2).

The second line contains the sequence id1, id2, ..., idn (1 ≤ idi ≤ 109) — identifiers of roborts. It is guaranteed that all identifiers are different.
Output

Print the k-th pronounced identifier (assume that the numeration starts from 1).
Examples
Input
Copy

2 2
1 2

Output
Copy

1

Input
Copy

4 5
10 4 18 3

Output
Copy

4

Note

In the first sample identifiers of robots will be pronounced in the following order: 1, 1, 2. As k = 2, the answer equals to 1.

In the second test case identifiers of robots will be pronounced in the following order: 10, 10, 4, 10, 4, 18, 10, 4, 18, 3. As k = 5, the answer equals to 4.
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
	
	ll n,k;	cin>>n>>k;
	V v;
	
	FOR(i,0,n)
	{
		ll num;	cin>>num;
		v.pb(num);
	}
	
	ll i=1;
	
	while(1)
	{
	    if(k>i)
	    {
	        k=k-i;
	        i++;
	    }
	    else
	        break;
	}
	
	cout<<v[k-1]<<endl;
	
	return 0;
}
