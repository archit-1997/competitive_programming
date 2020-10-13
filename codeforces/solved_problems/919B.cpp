/*We consider a positive integer perfect, if and only if the sum of its digits is exactly 10. Given a positive integer k, your task is to find the k

-th smallest perfect positive integer.
Input

A single line with a positive integer k
(1≤k≤10000

).
Output

A single number, denoting the k

-th smallest perfect integer.
Examples
Input
Copy

1

Output
Copy

19

Input
Copy

2

Output
Copy

28

Note

The first perfect integer is 19
and the second one is 28.
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

ll sum(ll n)
{
    ll ans=0;
    
    while(n!=0)
    {
        ans+=n%10;
        n/=10;
    }
    
    return ans;
}

int main()
{
	FAST;
	
	ll k;   cin>>k;
	
	ll num=1,c=0;
	
	while(1)
	{
	    if(sum(num)==10)
	    {
	        c++;
	        if(c==k)
	        {
	            cout<<num;
	            break;
	        }
	    }
	    num++;
	}
	
	
	
	return 0;
}
