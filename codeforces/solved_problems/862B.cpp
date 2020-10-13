/*Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.

A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into 2 sets in such a way, that for each edge (u, v) that belongs to the graph, u and v belong to different sets. You can find more formal definitions of a tree and a bipartite graph in the notes section below.

Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges they can add?

A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. A cycle and a loop aren't the same .
Input

The first line of input contains an integer n — the number of nodes in the tree (1 ≤ n ≤ 105).

The next n - 1 lines contain integers u and v (1 ≤ u, v ≤ n, u ≠ v) — the description of the edges of the tree.

It's guaranteed that the given graph is a tree.
Output

Output one integer — the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.
Examples
Input
Copy

3
1 2
1 3

Output
Copy

0

Input
Copy

5
1 2
2 3
3 4
4 5

Output
Copy

2

Note

Tree definition: https://en.wikipedia.org/wiki/Tree_(graph_theory)

Bipartite graph definition: https://en.wikipedia.org/wiki/Bipartite_graph

In the first test case the only edge that can be added in such a way, that graph won't contain loops or multiple edges is (2, 3), but adding this edge will make the graph non-bipartite so the answer is 0.

In the second test case Mahmoud and Ehab can add edges (1, 4) and (2, 5). 
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

void dfs(ll s,VV &v,V &vis,V &color,ll val)
{
    vis[s]=1;
    color[s]=val;
    
    for(ll i=0;i<v[s].size();i++)
    {
        if(!vis[v[s][i]])
        {
            ll num=(val+1)%2;
            dfs(v[s][i],v,vis,color,num);
        }
    }
    
    
}

int main()
{
	FAST;
	
	ll n;	cin>>n;
	
	VV v(n+1);
	
	FOR(i,0,n)
	{
	    ll a,b; cin>>a>>b;
	    v[a].pb(b);
	    v[b].pb(a);
	}
	
	V color(n+1,-1),vis(n+1,0);
	
	FOR(i,1,n+1)
	{
	    if(!vis[i])
	        dfs(i,v,vis,color,1);
	}
	
	ll l=0,r=0;
	
	FOR(i,1,n+1)
	{
	    if(color[i])
	        l++;
	    else
	        r++;
	}
	
	ll ans=(l*r)-(n-1);
	
	cout<<ans;
	
	return 0;
}
