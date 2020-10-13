/*Mahmoud has n line segments, the i-th of them has length ai. Ehab challenged him to use exactly 3 line segments to form a non-degenerate triangle. Mahmoud doesn't accept challenges unless he is sure he can win, so he asked you to tell him if he should accept the challenge. Given the lengths of the line segments, check if he can choose exactly 3 of them to form a non-degenerate triangle.

Mahmoud should use exactly 3 line segments, he can't concatenate two line segments or change any length. A non-degenerate triangle is a triangle with positive area.
Input

The first line contains single integer n (3 ≤ n ≤ 105) — the number of line segments Mahmoud has.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the lengths of line segments Mahmoud has.
Output

In the only line print "YES" if he can choose exactly three line segments and form a non-degenerate triangle with them, and "NO" otherwise.
Examples
Input
Copy

5
1 5 3 2 4

Output
Copy

YES

Input
Copy

3
4 1 2

Output
Copy

NO

Note

For the first example, he can use line segments with lengths 2, 4 and 5 to form a non-degenerate triangle.
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
	
	ll n;	cin>>n;
	V v;
	
	FOR(i,0,n)
	{
		ll num;	cin>>num;
		v.pb(num);
	}
	
    sort(v.begin(),v.end());
    
    for(ll i=0;i<n-2;i++)
    {
        ll a=v[i],b=v[i+1],c=v[i+2];
        
        if(a+b>c && b+c>a && c+a>b)
        {
            cout<<"Yes";
            return 0;
        }
        
    }
    
    cout<<"No";
	
	return 0;
}
