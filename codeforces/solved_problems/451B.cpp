/*Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers.

Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a bigger array, but only if you are able to answer the following question correctly: is it possible to sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment and reversing in the notes.
Input

The first line of the input contains an integer n (1 ≤ n ≤ 105) — the size of array a.

The second line contains n distinct space-separated integers: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109).
Output

Print "yes" or "no" (without quotes), depending on the answer.

If your answer is "yes", then also print two space-separated integers denoting start and end (start must not be greater than end) indices of the segment to be reversed. If there are multiple ways of selecting these indices, print any of them.
Examples
Input
Copy

3
3 2 1

Output
Copy

yes
1 3

Input
Copy

4
2 1 3 4

Output
Copy

yes
1 2

Input
Copy

4
3 1 2 4

Output
Copy

no

Input
Copy

2
1 2

Output
Copy

yes
1 1

Note

Sample 1. You can reverse the entire array to get [1, 2, 3], which is sorted.

Sample 3. No segment can be reversed such that the array will be sorted.

Definitions

A segment [l, r] of array a is the sequence a[l], a[l + 1], ..., a[r].

If you have an array a of size n and you reverse its segment [l, r], the array will become:

a[1], a[2], ..., a[l - 2], a[l - 1], a[r], a[r - 1], ..., a[l + 1], a[l], a[r + 1], a[r + 2], ..., a[n - 1], a[n].

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
    
    ll l=-1,r=-1;
    
    for(ll i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            l=i;break;
        }
    }
    
    //cout<<"l "<<l<<endl;
    
    if(l==-1)
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    
    for(ll i=n-1;i>0;i--)
    {
        //cout<<i<<" ";
        if(v[i]<v[i-1])
        {
            r=i;break;
        }
    }
    
    //cout<<endl;
    
    //cout<<"r "<<r<<endl;
    
    reverse(v.begin()+l,v.begin()+r+1);
    
    //for(ll i=0;i<n;i++)
        //cout<<v[i]<<" ";
    
    //cout<<endl;
    
    ll flag=0;
    
    for(ll i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            flag=1;break;
        }
    }
    
    if(flag)
        cout<<"no"<<endl;
    else
    {
        cout<<"yes"<<endl;
        cout<<l+1<<" "<<r+1<<endl;
    }
    
    return 0;
}
