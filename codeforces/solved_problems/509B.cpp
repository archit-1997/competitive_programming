/*There are n piles of pebbles on the table, the i-th pile contains ai pebbles. Your task is to paint each pebble using one of the k given colors so that for each color c and any two piles i and j the difference between the number of pebbles of color c in pile i and number of pebbles of color c in pile j is at most one.

In other words, let's say that bi, c is the number of pebbles of color c in the i-th pile. Then for any 1 ≤ c ≤ k, 1 ≤ i, j ≤ n the following condition must be satisfied |bi, c - bj, c| ≤ 1. It isn't necessary to use all k colors: if color c hasn't been used in pile i, then bi, c is considered to be zero.
Input

The first line of the input contains positive integers n and k (1 ≤ n, k ≤ 100), separated by a space — the number of piles and the number of colors respectively.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 100) denoting number of pebbles in each of the piles.
Output

If there is no way to paint the pebbles satisfying the given condition, output "NO" (without quotes) .

Otherwise in the first line output "YES" (without quotes). Then n lines should follow, the i-th of them should contain ai space-separated integers. j-th (1 ≤ j ≤ ai) of these integers should be equal to the color of the j-th pebble in the i-th pile. If there are several possible answers, you may output any of them.
Examples
Input
Copy

4 4
1 2 3 4

Output
Copy

YES
1
1 4
1 2 4
1 2 3 4

Input
Copy

5 2
3 2 4 1 3

Output
Copy

NO

Input
Copy

5 4
3 2 4 3 5

Output
Copy

YES
1 2 3
1 3
1 2 3 4
1 3 4
1 1 2 3 4*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;   cin>>n>>k;
    vector<ll> v;
    
    ll max=INT_MIN,min=INT_MAX;

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        if(max<num)
            max=num;
        if(num<min)
            min=num;
        v.push_back(num);
    }
    
    ll d=abs(max-min);
    if(d>k)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        
        for(ll i=0;i<n;i++)
        {
            for(ll j=1;j<=v[i];j++)
                cout<<j%k+1<<" ";
            
            cout<<endl;
        }
    }
    
    return 0;
}
