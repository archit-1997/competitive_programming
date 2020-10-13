/*One day, Twilight Sparkle is interested in how to sort a sequence of integers a1, a2, ..., an in non-decreasing order. Being a young unicorn, the only operation she can perform is a unit shift. That is, she can move the last element of the sequence to its beginning:

a1, a2, ..., an → an, a1, a2, ..., an - 1.
Help Twilight Sparkle to calculate: what is the minimum number of operations that she needs to sort the sequence?

Input
The first line contains an integer n (2 ≤ n ≤ 105). The second line contains n integer numbers a1, a2, ..., an (1 ≤ ai ≤ 105).

Output
If it's impossible to sort the sequence output -1. Otherwise output the minimum number of operations Twilight Sparkle needs to sort it.

Examples
inputCopy
2
2 1
outputCopy
1
inputCopy
3
1 3 2
outputCopy
-1
inputCopy
2
1 2
outputCopy
0


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    vector<ll>v;
    for(ll i=0;i<n;i++)
    {
        ll num; cin>>num;
        v.push_back(num);
    }
    ll index=-1;
    for(ll i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
            {
                index=i;
                break;
            }
    }
    if(n==1 || index==-1)
        cout<<0<<endl;
    else
    {
        ll flag=0;
        
        vector<ll> v2;
        
        for(ll i=index+1;i<n;i++)
        {
            //cout<<v[i]<<" ";
            v2.push_back(v[i]);
        }
        //cout<<endl;
            
        for(ll i=0;i<=index;i++)
        {
            //cout<<v[i]<<" ";
            v2.push_back(v[i]);
        }
        //cout<<endl;
            
        for(ll i=0;i<n-1;i++)
        {
            if(v2[i]>v2[i+1])
            {
                flag=1;
                break;
            }
        }
        
        if(flag)
            cout<<-1<<endl;
        else
        {
            ll ans=(n-(index+1));
            cout<<ans<<endl;
        }
        
        
    }
        
    return 0;
}
