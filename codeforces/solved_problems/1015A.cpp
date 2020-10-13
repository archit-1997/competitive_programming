/*You are given a set of 𝑛 segments on the axis 𝑂𝑥, each segment has integer endpoints between 1 and 𝑚 inclusive. Segments may intersect, overlap or even coincide with each other. Each segment is characterized by two integers 𝑙𝑖 and 𝑟𝑖 (1≤𝑙𝑖≤𝑟𝑖≤𝑚

) — coordinates of the left and of the right endpoints.

Consider all integer points between 1
and 𝑚 inclusive. Your task is to print all such points that don't belong to any segment. The point 𝑥 belongs to the segment [𝑙;𝑟] if and only if 𝑙≤𝑥≤𝑟

.
Input

The first line of the input contains two integers 𝑛
and 𝑚 (1≤𝑛,𝑚≤100

) — the number of segments and the upper bound for coordinates.

The next 𝑛
lines contain two integers each 𝑙𝑖 and 𝑟𝑖 (1≤𝑙𝑖≤𝑟𝑖≤𝑚) — the endpoints of the 𝑖-th segment. Segments may intersect, overlap or even coincide with each other. Note, it is possible that 𝑙𝑖=𝑟𝑖

, i.e. a segment can degenerate to a point.
Output

In the first line print one integer 𝑘

— the number of points that don't belong to any segment.

In the second line print exactly 𝑘

integers in any order — the points that don't belong to any segment. All points you print should be distinct.

If there are no such points at all, print a single integer 0

in the first line and either leave the second line empty or do not print it at all.
Examples
Input
Copy

3 5
2 2
1 2
5 5

Output
Copy

2
3 4 

Input
Copy

1 7
1 7

Output
Copy

0

Note

In the first example the point 1
belongs to the second segment, the point 2 belongs to the first and the second segments and the point 5 belongs to the third segment. The points 3 and 4

do not belong to any segment.

In the second example all the points from 1
to 7 belong to the first segment.

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

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,m;	cin>>n>>m;
	vector<ll> v(m+1,0);
	
	for(ll i=0;i<n;i++)
	{
		ll a,b; cin>>a>>b;
		
		fill(v.begin()+a,v.begin()+b+1,1);
	}
	
	ll count=0;
	vector<ll> ans;
	
	for(ll i=1;i<=m;i++)
	{
	    if(v[i]==0)
	    {
	        ans.push_back(i);
	        count++;
	    }
	}
	
	cout<<count<<endl;
	for(ll i=0;i<ans.size();i++)
	    cout<<ans[i]<<" ";
	
	
	return 0;
}
