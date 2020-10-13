/*On a random day, Neko found n treasure chests and m keys. The i-th chest has an integer ai written on it and the j-th key has an integer bj

on it. Neko knows those chests contain the powerful mysterious green Grapes, thus Neko wants to open as many treasure chests as possible.

The j
-th key can be used to unlock the i-th chest if and only if the sum of the key number and the chest number is an odd number. Formally, ai+bj≡1(mod2)

. One key can be used to open at most one chest, and one chest can be opened at most once.

Find the maximum number of chests Neko can open.
Input

The first line contains integers n
and m (1≤n,m≤105

) — the number of chests and the number of keys.

The second line contains n
integers a1,a2,…,an (1≤ai≤109

) — the numbers written on the treasure chests.

The third line contains m
integers b1,b2,…,bm (1≤bi≤109

) — the numbers written on the keys.
Output

Print the maximum number of chests you can open.
Examples
Input
Copy

5 4
9 14 6 2 11
8 4 7 20

Output
Copy

3

Input
Copy

5 1
2 4 6 8 10
5

Output
Copy

1

Input
Copy

1 4
10
20 30 40 50

Output
Copy

0

Note

In the first example, one possible way to unlock 3

chests is as follows:

    Use first key to unlock the fifth chest,
    Use third key to unlock the second chest,
    Use fourth key to unlock the first chest. 

In the second example, you can use the only key to unlock any single chest (note that one key can't be used twice).

In the third example, no key can unlock the given chest.
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
	
	ll n,m;	cin>>n>>m;
	
	ll o_a=0,o_b=0,e_a=0,e_b=0;
	
	FOR(i,0,n)
	{
		ll num;	cin>>num;
		if(num%2)
		    o_a++;
		else
		    e_a++;
	}
	
	
	FOR(i,0,m)
	{
		ll num;	cin>>num;
		if(num%2)
		    o_b++;
		else
		    e_b++;
	}
	
	//cout<<o_a<<" "<<e_a<<" "<<o_b<<" "<<e_b<<endl;
	
	ll v1=min(o_a,e_b),v2=min(e_a,o_b);
	
	cout<<v1+v2;;
	
	return 0;
}
