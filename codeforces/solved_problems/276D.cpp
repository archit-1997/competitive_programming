/*A little girl loves problems on bitwise operations very much. Here's one of them.

You are given two integers l and r. Let's consider the values of for all pairs of integers a and b (l ≤ a ≤ b ≤ r). Your task is to find the maximum value among all considered ones.

Expression means applying bitwise excluding or operation to integers x and y. The given operation exists in all modern programming languages, for example, in languages C++ and Java it is represented as "^", in Pascal — as «xor».
Input

The single line contains space-separated integers l and r (1 ≤ l ≤ r ≤ 1018).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
Output

In a single line print a single integer — the maximum value of for all pairs of integers a, b (l ≤ a ≤ b ≤ r).
Examples
Input
Copy

1 2

Output
Copy

3

Input
Copy

8 16

Output
Copy

31

Input
Copy

1 1

Output
Copy

0
*/

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

string binary(ll n)
{
    string ans;
    
    while(n!=0)
    {
        ans=ans+to_string(n%2);
        n/=2;
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}

ll decimal(string s)
{
    reverse(s.begin(),s.end());
    
    ll ans=0,n=s.size();
    
    FOR(i,0,n)
    {
        if(s[i]=='1')
            ans+=pow(2,i);
    }
    
    return ans;
}

int main()
{
	FAST;
	
	ll l,r; cin>>l>>r;
	
	if(l==r)
	    cout<<0;
	else if(r==l+1)
	    cout<<(l^r);
	else
	{
	    ll x=l^r;
	    string s=binary(x);
	    
	    ll n=s.size(),index;
	    
	    for(ll i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	        {
	            index=i;
	            break;
	        }
	    }
	    
	    for(ll i=index;i<n;i++)
	        s[i]='1';
	        
	    ll ans=decimal(s);
	    
	    cout<<ans<<endl;
	    
	}
	
	return 0;
}
