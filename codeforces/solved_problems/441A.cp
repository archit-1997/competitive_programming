/*Valera is a collector. Once he wanted to expand his collection with exactly one antique item.

Valera knows n sellers of antiques, the i-th of them auctioned ki items. Currently the auction price of the j-th object of the i-th seller is sij. Valera gets on well with each of the n sellers. He is perfectly sure that if he outbids the current price of one of the items in the auction (in other words, offers the seller the money that is strictly greater than the current price of the item at the auction), the seller of the object will immediately sign a contract with him.

Unfortunately, Valera has only v units of money. Help him to determine which of the n sellers he can make a deal with.
Input

The first line contains two space-separated integers n, v (1 ≤ n ≤ 50; 104 ≤ v ≤ 106) — the number of sellers and the units of money the Valera has.

Then n lines follow. The i-th line first contains integer ki (1 ≤ ki ≤ 50) the number of items of the i-th seller. Then go ki space-separated integers si1, si2, ..., siki (104 ≤ sij ≤ 106) — the current prices of the items of the i-th seller.
Output

In the first line, print integer p — the number of sellers with who Valera can make a deal.

In the second line print p space-separated integers q1, q2, ..., qp (1 ≤ qi ≤ n) — the numbers of the sellers with who Valera can make a deal. Print the numbers of the sellers in the increasing order.
Examples
Input
Copy

3 50000
1 40000
2 20000 60000
3 10000 70000 190000

Output
Copy

3
1 2 3

Input
Copy

3 50000
1 50000
3 100000 120000 110000
3 120000 110000 120000

Output
Copy

0

Note

In the first sample Valera can bargain with each of the sellers. He can outbid the following items: a 40000 item from the first seller, a 20000 item from the second seller, and a 10000 item from the third seller.

In the second sample Valera can not make a deal with any of the sellers, as the prices of all items in the auction too big for him.
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
	
	ll n,v;	cin>>n>>v;
	
	VV val(n+1);
	V ans;
	ll count=0;
	
	FOR(i,1,n+1)
	{
		ll t;   cin>>t;
		while(t--)
		{
		    ll num; cin>>num;
		    val[i].pb(num);
		}
	}
	
	
	FOR(i,1,n+1)
	{
	    ll len=val[i].size();
	    
	    FOR(j,0,len)
	    {
	        if(val[i][j]<v)
	        {
	            count++;
	            ans.pb(i);
	            break;
	        }
	    }
	}
	
	cout<<count<<endl;
	
	ll len=ans.size();
	
	FOR(i,0,len)
	    cout<<ans[i]<<" ";
	
	return 0;
}
