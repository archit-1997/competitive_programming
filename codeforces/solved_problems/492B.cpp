/*Vanya walks late at night along a straight street of length l, lit by n lanterns. Consider the coordinate system with the beginning of the street corresponding to the point 0, and its end corresponding to the point l. Then the i-th lantern is at the point ai. The lantern lights all points of the street that are at the distance of at most d from it, where d is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?
Input

The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 109) — the number of lanterns and the length of the street respectively.

The next line contains n integers ai (0 ≤ ai ≤ l). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.
Output

Print the minimum light radius d, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed 10 - 9.
Examples
Input
Copy

7 15
15 5 3 7 9 14 0

Output
Copy

2.5000000000

Input
Copy

2 5
2 5

Output
Copy

2.0000000000

Note

Consider the second sample. At d = 2 the first lantern will light the segment [0, 4] of the street, and the second lantern will light segment [3, 5]. Thus, the whole street will be lit.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,l; cin>>n>>l;
    
    unordered_map<ll,ll> hash;
    vector<ll> v;
    
    for(ll i=0;i<n;i++)
    {
        ll num; cin>>num;
        if(hash.find(num)==hash.end())
        {
            hash[num]=1;
            v.push_back(num);
        }
    }
    
    sort(v.begin(),v.end());
    
    //for(ll i=0;i<v.size();i++)
    //   cout<<v[i]<<" ";
        
    //cout<<endl;
    
    long double max=v[0];
    
    for(ll i=1;i<v.size();i++)
    {
        long double val=(v[i]-v[i-1])/2.0;
        if(max<val)
            max=val;
    }
    
    ll last=v.size()-1;
    
    if(v[last]!=l)
    {
        long double val=l-v[last];
        if(max<val)
            max=val;
    }
    
    cout.precision(9);
    cout<<max<<endl;
    
    return 0;
}
