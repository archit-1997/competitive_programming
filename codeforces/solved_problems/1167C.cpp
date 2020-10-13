/*In some social network, there are n users communicating with each other in m

groups of friends. Let's analyze the process of distributing some news between users.

Initially, some user x

receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.

For each user x
you have to determine what is the number of users that will know the news if initially only user x

starts distributing it.
Input

The first line contains two integers n
and m (1≤n,m≤5⋅105

) — the number of users and the number of groups of friends, respectively.

Then m
lines follow, each describing a group of friends. The i-th line begins with integer ki (0≤ki≤n) — the number of users in the i-th group. Then ki distinct integers follow, denoting the users belonging to the i

-th group.

It is guaranteed that ∑i=1mki≤5⋅105

.
Output

Print n
integers. The i-th integer should be equal to the number of users that will know the news if user i

starts distributing it.
Example
Input
Copy

7 5
3 2 5 4
0
2 1 2
1 1
2 6 7

Output
Copy

4 4 1 4 4 2 2 
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

ll root(V &par,ll i)
{
    while(par[i]!=i)
    {
        par[i]=par[par[i]];
        i=par[i];
    }
    
    return i;
}

ll find(V &par,ll a,ll b)
{
    ll ra=root(par,a),rb=root(par,b);
    
    return (ra==rb);
    
}

void Union(V &par,V &size,ll a,ll b)
{
    ll ra=root(par,a),rb=root(par,b);
    
    if(ra==rb)
        return ;
    
    if(size[ra] < size[rb])
    {
        par[ra]=rb;
        size[rb]+=size[ra];
    }
    else
    {
        par[rb]=ra;
        size[ra]+=size[rb];
    }
}

int main()
{
	FAST;
	
	ll n,m;	cin>>n>>m;
	
	V par(n+1),size(n+1,1);
	
	FOR(i,1,n+1)
	    par[i]=i;
	   
	FOR(i,0,m)
	{
	    ll num; cin>>num;
	    V v(num);
	    FOR(j,0,num)
	        cin>>v[j];
	    
	    if(num>=2)
	    {
	        for(ll j=1;j<num;j++)
	            Union(par,size,v[j-1],v[j]);
	    }
	    
	}
	
	FOR(i,1,n+1)
	{
	    ll r=root(par,i);
	    
	    cout<<size[r]<<" ";
	}
	
	return 0;
}
