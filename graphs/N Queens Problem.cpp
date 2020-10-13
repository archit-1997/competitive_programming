/*  Constraint : n>=1 && n<=10  */



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
#define VV vector<vector<ll>> 
#define pb push_back
#define pf push_front

ll isSafe(VV &v,ll r,ll c,ll mat)
{
    //checking whether row is safe
    
    for(ll j=1;j<=mat;j++)
    {
        if(v[r][j]==1)
            return 0;
    }
    
    //checking whether column is safe
    
    for(ll i=1;i<=mat;i++)
    {
        if(v[i][c]==1)
            return 0;
    }
    
    //checking whether diagonal safe 
    
    for(ll i=1;i<=mat;i++)
    {
        for(ll j=1;j<=mat;j++)
        {
            //checking for i+j
            if((i+j)==(r+c) && v[i][j]==1)
                return 0;
            
            //checking for i-j
            if((i-j)==(r-c) && v[i][j]==1)
                return 0;
        }
    }
    
    return 1;
}

ll nQueen(VV &v,ll n,ll mat)
{
    //If the queens have been finished
    if(n==0)
        return 1;
    
    //If there are queens which need to be placed
    
    for(ll i=1;i<=mat;i++)
    {
        for(ll j=1;j<=mat;j++)
        {
            ll val=isSafe(v,i,j,mat);
            
            if(val==1)
            {
                //place the queen
                v[i][j]=1;
                
                if(nQueen(v,n-1,mat)==1)
                    return 1;
                //agar yahan place krna safe nhi to hata do changes undo kr do
                v[i][j]=0;
            }
        }
    }
    
    return 0;
    
}

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;	cin>>n;
	VV v(n+1,V (n+1,0));
	
	ll exist=nQueen(v,n,n);
	
	if(exist==0 || n<1 || n>10)
	    cout<<"NO";
	else
	{
	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=1;j<=n;j++)
	            cout<<v[i][j]<<" ";
	        
	        cout<<endl;
	    }
	}
	
	
	return 0;
}
