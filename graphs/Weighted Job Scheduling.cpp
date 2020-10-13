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

struct job
{
    ll s,e,pos;
};

bool compare(const job &a,const job &b)
{
    if(a.e==b.e)
        return a.s<b.s;
    else
        return a.e<b.e;
}

int main()
{
    FAST;
    
    ll n;   cin>>n;

    vector<job> v(n);
    V ans(n);
    V cost(n);

    FOR(i,0,n)
    {
        ll a,b,c;   cin>>a>>b>>c;
        ans[i]=c;
        cost[i]=c;
        v[i].s=a,v[i].e=b,v[i].pos=i;
    }

    sort(v.begin(),v.end(),compare);

    FOR(i,1,n)
    {
        FOR(j,0,i)
        {
            if(v[j].e <= v[i].s && ans[v[i].pos]<ans[v[j].pos]+cost[v[i].pos])
                ans[v[i].pos]=ans[v[j].pos]+cost[v[i].pos];
        }
    }

    cout<<*max_element(ans.begin(),ans.end());
    
    return 0;
}
