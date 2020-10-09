/*New Year is coming in Line World! In this world, there are n cells numbered by integers from 1 to n, as a 1 × n board. People live in cells. However, it was hard to move between distinct cells, because of the difficulty of escaping the cell. People wanted to meet people who live in other cells.

So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year. First, he thought of n - 1 positive integers a1, a2, ..., an - 1. For every integer i where 1 ≤ i ≤ n - 1 the condition 1 ≤ ai ≤ n - i holds. Next, he made n - 1 portals, numbered by integers from 1 to n - 1. The i-th (1 ≤ i ≤ n - 1) portal connects cell i and cell (i + ai), and one can travel from cell i to cell (i + ai) using the i-th portal. Unfortunately, one cannot use the portal backwards, which means one cannot move from cell (i + ai) to cell i using the i-th portal. It is easy to see that because of condition 1 ≤ ai ≤ n - i one can't leave the Line World using portals.

Currently, I am standing at cell 1, and I want to go to cell t. However, I don't know whether it is possible to go there. Please determine whether I can go to cell t by only using the construted transportation system.
Input

The first line contains two space-separated integers n (3 ≤ n ≤ 3 × 104) and t (2 ≤ t ≤ n) — the number of cells, and the index of the cell which I want to go to.

The second line contains n - 1 space-separated integers a1, a2, ..., an - 1 (1 ≤ ai ≤ n - i). It is guaranteed, that using the given transportation system, one cannot leave the Line World.
Output

If I can go to cell t using the transportation system, print "YES". Otherwise, print "NO".
Examples
Input
Copy

8 4
1 2 1 2 1 2 1

Output
Copy

YES

Input
Copy

8 5
1 2 1 2 1 1 1

Output
Copy

NO

Note

In the first sample, the visited cells are: 1, 2, 4; so we can successfully visit the cell 4.

In the second sample, the possible cells to visit are: 1, 2, 4, 6, 7, 8; so we can't visit the cell 5, which we want to visit.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    ll d;   cin>>d;
    vector<vector<ll>> v(n+1);

    for(ll i=1;i<=n-1;i++)
    {
        ll num;cin>>num;
        v[i].push_back(i+num);
    }
    
    vector<bool> vis(n+1,false);
    
    stack<ll> s;
    s.push(1);
    vis[1]=true;
    
    while(!s.empty())
    {
        ll t=s.top();
        if(t==d)
        {
            cout<<"YES";
            return 0;
        }
        s.pop();
        
        for(ll i=0;i<v[t].size();i++)
        {
            if(vis[v[t][i]]==false)
            {
                vis[v[t][i]]=true;
                s.push(v[t][i]);
            }
        }
    }
    
    cout<<"NO";
    
    return 0;
}
