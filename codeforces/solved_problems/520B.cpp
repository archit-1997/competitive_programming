/*Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing some positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue button, device subtracts one from the number on the display. If at some point the number stops being positive, the device breaks down. The display can show arbitrarily large numbers. Initially, the display shows number n.

Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?
Input

The first and the only line of the input contains two distinct integers n and m (1 ≤ n, m ≤ 104), separated by a space .
Output

Print a single number — the minimum number of times one needs to push the button required to get the number m out of number n.
Examples
Input
Copy

4 6

Output
Copy

2

Input
Copy

10 1

Output
Copy

9

Note

In the first example you need to push the blue button once, and then push the red button once.

In the second example, doubling the number is unnecessary, so we need to push the blue button nine times.
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
	
	ll n,m; cin>>n>>m;
	
	ll ans=0;
	
	while(m!=n)
	{
	    if(m<n)
	        m++;
	    else
	    {
	        if(m%2==0)
	            m/=2;
	        else
	            m++;
	    }
	    
	    ans++;
	}
	
	cout<<ans;
	
	return 0;
}
