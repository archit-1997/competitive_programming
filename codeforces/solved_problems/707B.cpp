/*Masha wants to open her own bakery and bake muffins in one of the n cities numbered from 1 to n. There are m bidirectional roads, each of whose connects some pair of cities.

To bake muffins in her bakery, Masha needs to establish flour supply from some storage. There are only k storages, located in different cities numbered a1, a2, ..., ak.

Unforunately the law of the country Masha lives in prohibits opening bakery in any of the cities which has storage located in it. She can open it only in one of another n - k cities, and, of course, flour delivery should be paid — for every kilometer of path between storage and bakery Masha should pay 1 ruble.

Formally, Masha will pay x roubles, if she will open the bakery in some city b (ai ≠ b for every 1 ≤ i ≤ k) and choose a storage in some city s (s = aj for some 1 ≤ j ≤ k) and b and s are connected by some path of roads of summary length x (if there are more than one path, Masha is able to choose which of them should be used).

Masha is very thrifty and rational. She is interested in a city, where she can open her bakery (and choose one of k storages and one of the paths between city with bakery and city with storage) and pay minimum possible amount of rubles for flour delivery. Please help Masha find this amount.
Input

The first line of the input contains three integers n, m and k (1 ≤ n, m ≤ 105, 0 ≤ k ≤ n) — the number of cities in country Masha lives in, the number of roads between them and the number of flour storages respectively.

Then m lines follow. Each of them contains three integers u, v and l (1 ≤ u, v ≤ n, 1 ≤ l ≤ 109, u ≠ v) meaning that there is a road between cities u and v of length of l kilometers .

If k > 0, then the last line of the input contains k distinct integers a1, a2, ..., ak (1 ≤ ai ≤ n) — the number of cities having flour storage located in. If k = 0 then this line is not presented in the input.
Output

Print the minimum possible amount of rubles Masha should pay for flour delivery in the only line.

If the bakery can not be opened (while satisfying conditions) in any of the n cities, print  - 1 in the only line.
Examples
Input
Copy

5 4 2
1 2 5
1 2 3
2 3 4
1 4 10
1 5

Output
Copy

3

Input
Copy

3 1 1
1 2 3
3

Output
Copy

-1
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
	
	ll n,m,k;	cin>>n>>m>>k;
	vector<pair<ll,P>> v;
	
	FOR(i,0,m)
	{
		ll a,b,c;   cin>>a>>b>>c;
		v.pb({c,{a,b}});
	}
	
	V store(n+1,0);
	
	FOR(i,0,k)
	{
	    ll num; cin>>num;
	    store[num]=1;
	}
	
	sort(v.begin(),v.end());
	
	ll ans=INT_MAX;
	
	FOR(i,0,m)
	{
	    ll d=v[i].F;
		ll c1=v[i].S.F;
		ll c2=v[i].S.S;
		
		if((store[c1]==0 && store[c2]==1) || (store[c1]==1 && store[c2]==0))
		{
		    if(d<ans)
		        ans=d;
		}
	}
	
	if(ans==INT_MAX)
	   cout<<-1;
	else
	    cout<<ans<<endl;
	
	return 0;
}
