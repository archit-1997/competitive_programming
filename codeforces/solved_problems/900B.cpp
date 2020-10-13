/*You have a fraction . You need to find the first occurrence of digit c into decimal notation of the fraction after decimal point.
Input

The first contains three single positive integers a, b, c (1 ≤ a < b ≤ 105, 0 ≤ c ≤ 9).
Output

Print position of the first occurrence of digit c into the fraction. Positions are numbered from 1 after decimal point. It there is no such position, print -1.
Examples
Input
Copy

1 2 0

Output
Copy

2

Input
Copy

2 3 7

Output
Copy

-1

Note

The fraction in the first example has the following decimal notation: . The first zero stands on second position.

The fraction in the second example has the following decimal notation: . There is no digit 7 in decimal notation of the fraction. 
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

int main()
{
	FAST;
	
	ll a,b,c;   cin>>a>>b>>c;
	
	ll rem=a%b;

	V v;
	
	ll count=b;
	
	while(count--)
	{
	    ll val=rem*10;
	    ll q=val/b;
	    v.push_back(q);
	    rem=val%b;
	}
	ll n=v.size();
	ll i;
	
// 	FOR(i,0,n)
// 	    cout<<v[i]<<" ";
	
// 	cout<<endl;
// 	line;
	
	ll flag=-1;
	
    FOR(i,0,n)
	{
	    if(v[i]==c)
	    {
	        flag=i;
	        break;
	    }
	}
	
	if(flag!=-1)
	    cout<<flag+1;
	else
	    cout<<-1;
	
	return 0;
}
