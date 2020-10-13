/*Vasya has got an undirected graph consisting of n vertices and m edges. This graph doesn't contain any self-loops or multiple edges. Self-loop is an edge connecting a vertex to itself. Multiple edges are a pair of edges such that they connect the same pair of vertices. Since the graph is undirected, the pair of edges (1,2) and (2,1)

is considered to be multiple edges. Isolated vertex of the graph is a vertex such that there is no edge connecting this vertex to any other vertex.

Vasya wants to know the minimum and maximum possible number of isolated vertices in an undirected graph consisting of n
vertices and m

edges.
Input

The only line contains two integers n
and m (1≤n≤105,0≤m≤n(n−1)2)

.

It is guaranteed that there exists a graph without any self-loops or multiple edges with such number of vertices and edges.
Output

In the only line print two numbers min
and max

— the minimum and maximum number of isolated vertices, respectively.
Examples
Input
Copy

4 2

Output
Copy

0 1

Input
Copy

3 1

Output
Copy

1 1

Note

In the first example it is possible to construct a graph with 0
isolated vertices: for example, it should contain edges (1,2) and (3,4). To get one isolated vertex, we may construct a graph with edges (1,2) and (1,3)

.

In the second example the graph will always contain exactly one isolated vertex.
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
	
	ll n,m; cin>>n>>m;
	
	if(m==0)
	{
	    cout<<n<<" "<<n;
	    return 0;
	}
	
	ll node=1;
	
	ll big=-1,small=-1;
	
	while(node<=n)
	{
	    ll val=node*(node-1);
	    if((val/2) >=m)
	    {
	        big=node;
	        break;
	    }
	    
	    node++;
	}
	

	big=n-node;
	
	if((2*m)>=n)
	    small=0;
	else
	    small=n-(2*m);
	    
	cout<<small<<" "<<big<<endl;
	
	
	return 0;
}
