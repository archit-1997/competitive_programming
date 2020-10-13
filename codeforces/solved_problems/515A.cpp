/*Someday, Drazil wanted to go on date with Varda. Drazil and Varda live on Cartesian plane. Drazil's home is located in point (0, 0) and Varda's home is located in point (a, b). In each step, he can move in a unit distance in horizontal or vertical direction. In other words, from position (x, y) he can go to positions (x + 1, y), (x - 1, y), (x, y + 1) or (x, y - 1).

Unfortunately, Drazil doesn't have sense of direction. So he randomly chooses the direction he will go to in each step. He may accidentally return back to his house during his travel. Drazil may even not notice that he has arrived to (a, b) and continue travelling.

Luckily, Drazil arrived to the position (a, b) successfully. Drazil said to Varda: "It took me exactly s steps to travel from my house to yours". But Varda is confused about his words, she is not sure that it is possible to get from (0, 0) to (a, b) in exactly s steps. Can you find out if it is possible for Varda?
Input

You are given three integers a, b, and s ( - 109 ≤ a, b ≤ 109, 1 ≤ s ≤ 2·109) in a single line.
Output

If you think Drazil made a mistake and it is impossible to take exactly s steps and get from his home to Varda's home, print "No" (without quotes).

Otherwise, print "Yes".
Examples
Input
Copy

5 5 11

Output
Copy

No

Input
Copy

10 15 25

Output
Copy

Yes

Input
Copy

0 5 1

Output
Copy

No

Input
Copy

0 0 2

Output
Copy

Yes

Note

In fourth sample case one possible route is: .
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
	
	ll r,c,s;	cin>>r>>c>>s;
	
	r=abs(r),c=abs(c);
	
	ll ans=r+c;
	
	if(ans==s)
	    cout<<"Yes";
	else if(ans>s)
	    cout<<"No";
	else
	{
	    ll diff=s-ans;
	    if(diff%2==0)
	        cout<<"Yes";
	    else
	        cout<<"No";
	}
	
	return 0;
}
