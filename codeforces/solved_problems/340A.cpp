/*Iahub and his friend Floyd have started painting a wall. Iahub is painting the wall red and Floyd is painting it pink. You can consider the wall being made of a very large number of bricks, numbered 1, 2, 3 and so on.

Iahub has the following scheme of painting: he skips x - 1 consecutive bricks, then he paints the x-th one. That is, he'll paint bricks x, 2·x, 3·x and so on red. Similarly, Floyd skips y - 1 consecutive bricks, then he paints the y-th one. Hence he'll paint bricks y, 2·y, 3·y and so on pink.

After painting the wall all day, the boys observed that some bricks are painted both red and pink. Iahub has a lucky number a and Floyd has a lucky number b. Boys wonder how many bricks numbered no less than a and no greater than b are painted both red and pink. This is exactly your task: compute and print the answer to the question.
Input

The input will have a single line containing four integers in this order: x, y, a, b. (1 ≤ x, y ≤ 1000, 1 ≤ a, b ≤ 2·109, a ≤ b).
Output

Output a single integer — the number of bricks numbered no less than a and no greater than b that are painted both red and pink.
Examples
Input
Copy

2 3 6 18

Output
Copy

3

Note

Let's look at the bricks from a to b (a = 6, b = 18). The bricks colored in red are numbered 6, 8, 10, 12, 14, 16, 18. The bricks colored in pink are numbered 6, 9, 12, 15, 18. The bricks colored in both red and pink are numbered with 6, 12 and 18. 
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

ll lcm(ll a,ll b)
{
    ll g=__gcd(a,b);
    
    ll ans=(a*b)/g;
    
    return ans;
}

int main()
{
	FAST;
	
	ll x,y,a,b; cin>>x>>y>>a>>b;
	
	ll LCM=lcm(x,y);
	
	ll lc=(a-1)/LCM,rc=b/LCM;
	
	cout<<(rc-lc);
	
	return 0;
}
