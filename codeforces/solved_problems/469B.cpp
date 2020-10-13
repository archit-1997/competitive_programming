/*Little X and Little Z are good friends. They always chat online. But both of them have schedules.

Little Z has fixed schedule. He always online at any moment of time between a1 and b1, between a2 and b2, ..., between ap and bp (all borders inclusive). But the schedule of Little X is quite strange, it depends on the time when he gets up. If he gets up at time 0, he will be online at any moment of time between c1 and d1, between c2 and d2, ..., between cq and dq (all borders inclusive). But if he gets up at time t, these segments will be shifted by t. They become [ci + t, di + t] (for all i).

If at a moment of time, both Little X and Little Z are online simultaneosly, they can chat online happily. You know that Little X can get up at an integer moment of time between l and r (both borders inclusive). Also you know that Little X wants to get up at the moment of time, that is suitable for chatting with Little Z (they must have at least one common moment of time in schedules). How many integer moments of time from the segment [l, r] suit for that?
Input

The first line contains four space-separated integers p, q, l, r (1 ≤  p, q ≤ 50; 0 ≤ l ≤ r ≤ 1000).

Each of the next p lines contains two space-separated integers ai, bi (0 ≤ ai < bi ≤ 1000). Each of the next q lines contains two space-separated integers cj, dj (0 ≤ cj < dj ≤ 1000).

It's guaranteed that bi < ai + 1 and dj < cj + 1 for all valid i and j.
Output

Output a single integer — the number of moments of time from the segment [l, r] which suit for online conversation.
Examples
Input
Copy

1 1 0 4
2 3
0 1

Output
Copy

3

Input
Copy

2 3 0 20
15 17
23 26
1 4
7 11
15 17

Output
Copy

20*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll p,q,l,r;
    cin>>p>>q>>l>>r;
    
    unordered_map<ll,ll> hash;
    
    for(ll i=0;i<p;i++)
    {
        ll a,b; cin>>a>>b;
        for(ll j=a;j<=b;j++)
            hash[j]=1;
    }
    
    set<ll> s;
    
    for(ll i=0;i<q;i++)
    {
        ll a,b; cin>>a>>b;
        for(ll j=a;j<=b;j++)
            s.insert(j);
    }
    
    ll count=0;
    
    for(ll i=l;i<=r;i++)
    {
        for(auto it=s.begin();it!=s.end();++it)
        {
            ll num=*it;
            //cout<<"--"<<num<<endl;
            if(num+i <=1000 && hash[num+i]==1)
            {
                count++;
                break;
            }
        }
    }
    
    cout<<count<<endl;
    
    return 0;
}
