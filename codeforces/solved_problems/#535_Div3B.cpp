#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    
    std::vector<ll> v ;
    
    for(ll i=0;i<n;i++)
    {
        ll num; cin>>num;
        v.push_back(num);
    }
        
    sort(v.begin(),v.end());
    
    for(ll i=n-1;i>=0;i--)
    {
        if((v[i]==v[i-1]) || v[n-1]%v[i]!=0)
        {
            cout<<v[n-1]<<" "<<v[i];
            break;
        }
    }
    
    return 0;
}
