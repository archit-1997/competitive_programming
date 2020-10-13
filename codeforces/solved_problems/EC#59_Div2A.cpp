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
        ll d;   cin>>d;
        
        string s;   cin>>s;
        
        if(d==2)
        {
            ll l=s[0]-'0';
            ll r=s[1]-'0';
            
            if(l<r)
            {
                cout<<"YES"<<endl;
                cout<<2<<endl;
                cout<<l<<" "<<r<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<s[0]<<" "<<s.substr(1)<<endl;
        }
    }
    
    
    
    return 0;
}
