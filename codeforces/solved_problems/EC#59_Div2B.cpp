#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll  q;  cin>>q;
    
    while(q--)
    {
        ll k,x;
        cin>>k>>x;
        
        ll num=(k-1)*9 + x;
        
        cout<<num<<endl;
    }
    
    return 0;
}
