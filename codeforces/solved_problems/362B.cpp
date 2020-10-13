/*Little boy Petya loves stairs very much. But he is bored from simple going up and down them — he loves jumping over several stairs at a time. As he stands on some stair, he can either jump to the next one or jump over one or two stairs at a time. But some stairs are too dirty and Petya doesn't want to step on them.
Now Petya is on the first stair of the staircase, consisting of n stairs. He also knows the numbers of the dirty stairs of this staircase. Help Petya find out if he can jump through the entire staircase and reach the last stair number n without touching a dirty stair once.
One has to note that anyway Petya should step on the first and last stairs, so if the first or the last stair is dirty, then Petya cannot choose a path with clean steps only.
Input
The first line contains two integers n and m (1 ≤ n ≤ 109, 0 ≤ m ≤ 3000) — the number of stairs in the staircase and the number of dirty stairs, correspondingly. The second line contains m different space-separated integers d1, d2, ..., dm (1 ≤ di ≤ n) — the numbers of the dirty stairs (in an arbitrary order).
Output
Print "YES" if Petya can reach stair number n, stepping only on the clean stairs. Otherwise print "NO".
Examples
Input
Copy
10 5
2 4 8 3 6
Output
Copy
NO
Input
Copy
10 5
2 4 5 7 9
Output
Copy
YES*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m; cin>>n>>m;
    
    vector<ll> v;
    
    for(ll i=0;i<m;i++)
    {
        ll num; cin>>num;
        v.push_back(num);
    }
    
    if(m==0)
