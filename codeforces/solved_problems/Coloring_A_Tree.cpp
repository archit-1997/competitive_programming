/*You are given a rooted tree with n vertices. The vertices are numbered from 1 to n, the root is the vertex number 1.

Each vertex has a color, let's denote the color of vertex v by cv. Initially cv = 0.

You have to color the tree into the given colors using the smallest possible number of steps. On each step you can choose a vertex v and a color x, and then color all vectices in the subtree of v (including v itself) in color x. In other words, for every vertex u, such that the path from root to u passes through v, set cu = x.

It is guaranteed that you have to color each vertex in a color different from 0.

You can learn what a rooted tree is using the link: https://en.wikipedia.org/wiki/Tree_(graph_theory).
Input

The first line contains a single integer n (2 ≤ n ≤ 104) — the number of vertices in the tree.

The second line contains n - 1 integers p2, p3, ..., pn (1 ≤ pi < i), where pi means that there is an edge between vertices i and pi.

The third line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ n), where ci is the color you should color the i-th vertex into.

It is guaranteed that the given graph is a tree.
Output

Print a single integer — the minimum number of steps you have to perform to color the tree into given colors.
Examples
Input
Copy

6
1 2 2 1 5
2 1 1 1 1 1

Output
Copy

3

Input
Copy

7
1 1 2 3 1 4
3 3 1 1 1 2 3

Output
Copy

5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

void dfs(ll s,vector<vector<ll>> &v,vector<bool> &vis,vector<ll> &color)
{
    vis[s]=true;
    for(ll i=0;i<v[s].size();i++)
    {
        if(vis[v[s][i]]==false && color[v[s][i]]==color[s])
            dfs(v[s][i],v,vis,color);
    }
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    vector<vector<ll>> v(n+1);
    vector<bool> vis(n+1,false);
    vector<ll> color(n+1);

    for(ll i=2;i<=n;i++)
    {
        ll num;cin>>num;
        v[num].push_back(i);
        v[i].push_back(num);
    }
    
    for(ll i=1;i<=n;i++)
    {
        ll num; cin>>num;
        color[i]=num;
    }
    
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i,v,vis,color);
            ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
