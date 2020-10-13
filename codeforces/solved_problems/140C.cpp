/*As meticulous Gerald sets the table and caring Alexander sends the postcards, Sergey makes snowmen. Each showman should consist of three snowballs: a big one, a medium one and a small one. Sergey's twins help him: they've already made n snowballs with radii equal to r1, r2, ..., rn. To make a snowman, one needs any three snowballs whose radii are pairwise different. For example, the balls with radii 1, 2 and 3 can be used to make a snowman but 2, 2, 3 or 2, 2, 2 cannot. Help Sergey and his twins to determine what maximum number of snowmen they can make from those snowballs.
Input

The first line contains integer n (1 ≤ n ≤ 105) — the number of snowballs. The next line contains n integers — the balls' radii r1, r2, ..., rn (1 ≤ ri ≤ 109). The balls' radii can coincide.
Output

Print on the first line a single number k — the maximum number of the snowmen. Next k lines should contain the snowmen's descriptions. The description of each snowman should consist of three space-separated numbers — the big ball's radius, the medium ball's radius and the small ball's radius. It is allowed to print the snowmen in any order. If there are several solutions, print any of them.
Examples
Input
Copy

7
1 2 3 4 5 6 7

Output
Copy

2
3 2 1
6 5 4

Input
Copy

3
2 2 3

Output
Copy

0
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
	unordered_map<ll,ll> hash;
	priority_queue<pair<ll,ll>> pq;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		hash[num]++;
	}
	
	for(auto it=hash.begin();it!=hash.end();it++)
	{
	    ll a=it->F;
	    ll b=it->S;
	    pq.push({b,a});
	}
	
	
	//pair
	//count-->val
	ll ans=0;
	//cout<<pq.size()<<endl;
	//line;
	
	vector<vector<ll>> res;
	
	while(pq.size()>=3)
	{
	    vector<ll> tmp(3);
	    pair<ll,ll> s1=pq.top();
	    pq.pop();
	    pair<ll,ll> s2=pq.top();
	    pq.pop();
	    pair<ll,ll> s3=pq.top();
	    pq.pop();
	    tmp={s1.S,s2.S,s3.S};
	    sort(tmp.begin(),tmp.end(),greater<int>());
	    res.push_back(tmp);
	    ans++;
	    
	    if(s1.F>1)
	    {
	        s1.F--;
	        pq.push({s1.F,s1.S});
	    }
	    if(s2.F>1)
	    {
	        s2.F--;
	        pq.push({s2.F,s2.S});
	    }
	    if(s3.F>1)
	    {
	        s3.F--;
	        pq.push({s3.F,s3.S});
	    }
	}
	
	if(ans==0)
	    cout<<0;
	else
	{
	    cout<<ans<<endl;
	    for(ll i=0;i<res.size();i++)
	        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
	}
	
	return 0;
}
