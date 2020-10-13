        //Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define P pair<ll,ll>
#define PP pair<pair<ll,ll>,ll>
#define V vector<ll>
#define VP vector<pair<ll,ll>>
#define VS vector<string>
#define VV vector<vector<ll>> 
#define VVP vector<vector<pair<ll,ll>>> 
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    FAST;
    
    ll t;   cin>>t;

    while(t--)
    {
        string s;   cin>>s;
        ll n=s.size();
        V z(n,0);
        z[0]=0;

        ll l=0,r=0;

        FOR(i,1,n)
        {
            if(i>r)
            {
                l=r=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l;
                r--;
            }
            else
            {
                k=i-l;
                if(z[k]<r-i+1)
                    z[i]=z[k];
                else
                {
                    l=i;
                    while(r<n && s[r-l]==s[r])
                    r++;
                    z[i]=r-l;
                    r--;
                }
            }
        }

        ll ans=0;

        FOR(i,0,n)
            ans+=z[i];

        cout<<(ans+n)<<endl;

    }
    
    return 0;
}
